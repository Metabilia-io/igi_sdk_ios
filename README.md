# IGI SDK — iOS

Embeds the Metabilia / IGI consumer experience (events, marketplace,
auctions, wishlist, mystery boxes, account history) into a host iOS
app as a SwiftUI surface. Distributed as a binary XCFramework via
Swift Package Manager.

## Requirements

| | |
|---|---|
| Minimum iOS deployment target | **17.0** |
| Xcode | 15+ (Swift 5.9 toolchain) |
| Swift Package Manager | 5.9+ |
| Architecture support | `arm64` device + `arm64` simulator (Apple Silicon Macs) |

The XCFramework does **not** ship an `x86_64` simulator slice. Intel
Macs that run the simulator under Rosetta are not supported targets;
M-series Macs are.

## Install (Swift Package Manager)

In Xcode: **File → Add Package Dependencies…**, paste:

```
https://github.com/Metabilia-io/igi_sdk_ios.git
```

Select **Up to Next Major Version** from `4.0.0`, then add the
`igi_sdk` library to your app target.

Or in `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/Metabilia-io/igi_sdk_ios.git", from: "4.0.0"),
],
targets: [
    .target(
        name: "MyApp",
        dependencies: [
            .product(name: "igi_sdk", package: "igi_sdk_ios"),
        ]
    ),
]
```

The SPM dependency pulls in **Stripe** (`stripe-ios-spm`) and
**PusherSwift** transitively — you do not need to add them
yourself.

## Initialization

Initialize the SDK exactly once during app launch, before any IGI
view is presented. The SDK requires an API key and a subdomain
slug — both come from Metabilia ops. Pick the matching environment:

| Environment | `sdkMode` constant |
|---|---|
| Development | `IGIManager.IGI_SDK_DEV_MODE` |
| Production | `IGIManager.IGI_SDK_PRODUCTION_MODE` |

```swift
import SwiftUI
import igi_sdk

@main
struct MyApp: App {
    @UIApplicationDelegateAdaptor(MyAppDelegate.self) var appDelegate

    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}

class MyAppDelegate: NSObject, UIApplicationDelegate {
    func application(
        _ application: UIApplication,
        didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]? = nil
    ) -> Bool {
        IGIManager.shared().initialize(
            apiKey: "<API_KEY_FROM_METABILIA>",
            sdkMode: IGIManager.IGI_SDK_PRODUCTION_MODE,
            subDomain: "<SUBDOMAIN_FROM_METABILIA>"
        ) { _, error in
            if let error {
                print("IGI SDK initialization failed: \(error.localizedDescription)")
            }
        }
        return true
    }
}
```

## Hosting the SDK UI

Render the SDK's UI as any other SwiftUI view — typically
`IGIMainTabView` inside the host's content view:

```swift
import SwiftUI
import igi_sdk

struct ContentView: View {
    var body: some View {
        IGIMainTabView()
    }
}
```

`IGIMainTabView` is a `TabView` with five tabs (events / wishlist /
mystery boxes / account / etc.), each wrapping its own
`NavigationStack`. Wrap it in your own `NavigationStack` only if
you want to push the SDK's surface onto an existing navigation
stack — most hosts use it as the root of a `WindowGroup` directly.

UIKit hosts can render the same view via
`UIHostingController(rootView: IGIMainTabView())`.

## Push notifications

The SDK consumes FCM tokens to deliver item-update / auction
realtime pushes. Wiring is host-owned because the partner already
manages Firebase / APNs. The SDK only needs the FCM token forwarded
once per session.

The integration spans four delegate methods plus an active token
fetch at launch. **All five are necessary** — missing any one
silently degrades push delivery in a different scenario.

### Required `AppDelegate` wiring

```swift
import FirebaseCore
import FirebaseMessaging
import UserNotifications
import igi_sdk

class MyAppDelegate: NSObject, UIApplicationDelegate, UNUserNotificationCenterDelegate, MessagingDelegate {
    func application(
        _ application: UIApplication,
        didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]? = nil
    ) -> Bool {
        FirebaseApp.configure()
        Messaging.messaging().delegate = self
        UNUserNotificationCenter.current().delegate = self

        // Permission prompt — show this at the moment that's right
        // for your UX (post-login, post-onboarding, first launch).
        UNUserNotificationCenter.current()
            .requestAuthorization(options: [.alert, .sound, .badge]) { _, _ in }
        application.registerForRemoteNotifications()

        // ...IGIManager.shared().initialize(...) here...

        // Active FCM token fetch — required because Firebase caches
        // tokens at the Installations layer across reinstalls; the
        // `messaging(_:didReceiveRegistrationToken:)` callback below
        // can quietly skip firing on a fresh install of the same
        // simulator. `IGIManager.setDeviceToken` is idempotent and
        // dedup-guarded, so this is cheap to call on every launch.
        Messaging.messaging().token { token, _ in
            if let token { IGIManager.shared().setDeviceToken(token) }
        }

        return true
    }

    // Hand the APNs device token to Firebase Messaging — without
    // this, FCM token fetches fail with "No APNS token specified
    // before fetching FCM Token". Firebase's method-swizzling is
    // unreliable under SwiftUI's @UIApplicationDelegateAdaptor, so
    // wire it explicitly.
    func application(
        _ application: UIApplication,
        didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data
    ) {
        Messaging.messaging().apnsToken = deviceToken
    }

    // Foreground push presentation — let the user see the banner
    // even when your app is open.
    func userNotificationCenter(
        _ center: UNUserNotificationCenter,
        willPresent notification: UNNotification,
        withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void
    ) {
        completionHandler([.sound, .banner, .badge])
    }

    // Tap-routing — fires for both warm taps (app already running)
    // and cold-start taps (app was killed). iOS waits until the
    // window is ready before dispatching on cold-start, so this
    // single handler covers all tap cases. Without it, taps land on
    // your launch screen instead of the right item-detail / receipt
    // screen.
    func userNotificationCenter(
        _ center: UNUserNotificationCenter,
        didReceive response: UNNotificationResponse,
        withCompletionHandler completionHandler: @escaping () -> Void
    ) {
        let userInfo = response.notification.request.content.userInfo
        if !IGIManager.shared().handleRemoteMessage(userInfo) {
            // Fallthrough for non-IGI pushes.
        }
        completionHandler()
    }

    // Forwarded FCM tokens (rotation case).
    func messaging(_ messaging: Messaging, didReceiveRegistrationToken fcmToken: String?) {
        if let fcmToken { IGIManager.shared().setDeviceToken(fcmToken) }
    }

    // Silent / `content-available` data pushes.
    func application(
        _ application: UIApplication,
        didReceiveRemoteNotification userInfo: [AnyHashable: Any],
        fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void
    ) {
        if !IGIManager.shared().handleRemoteMessage(userInfo) {
            // Fallthrough for non-IGI pushes.
        }
        completionHandler(.newData)
    }
}
```

The push payloads the SDK recognises are `type` / `event_item_id` /
`item_type` keyed; anything outside that vocabulary falls through to
your own handlers (the `handleRemoteMessage` returns `false`).

### Required Xcode capability

Add the **Push Notifications** capability under your target's
**Signing & Capabilities** tab. This writes the `aps-environment`
entitlement to your `.entitlements` file. Without it, the
AppDelegate wiring above silently fails to deliver pushes.

## Analytics

The SDK is provider-agnostic. It emits string-keyed events through
an `IGIAnalyticsListener` protocol; the host implements that and
forwards to Firebase / Mixpanel / Amplitude / etc. Event names and
payload keys are stable across releases — see
[`Analytics/IGIAnalyticsEvents.swift`](https://github.com/Metabilia-io/igi_sdk_ios)
for the constants.

```swift
import FirebaseAnalytics
import igi_sdk

final class AnalyticsBridge: NSObject, IGIAnalyticsListener {
    static let shared = AnalyticsBridge()

    func trackEvent(_ eventName: String, parameters: [String: Any]?) {
        Analytics.logEvent(eventName, parameters: parameters)
    }
}

// Register after `initialize(...)` succeeds:
IGIManager.shared().setAnalyticsDelegate(AnalyticsBridge.shared)
```

## Theming

Override SDK colors and fonts via a single dictionary keyed by
`IGIManager.IGI_KEY_*` constants. Set it on launch, before the
first SDK view renders:

```swift
IGIManager.shared().themeDictionary = [
    IGIManager.IGI_KEY_PRIMARY_COLOR: UIColor(named: "TeamPrimary")!,
    IGIManager.IGI_KEY_SECONDARY_COLOR: UIColor(named: "TeamSecondary")!,
    IGIManager.IGI_KEY_TEXT_COLOR: UIColor.white,
    IGIManager.IGI_KEY_TEXT_FONT: UIFont(name: "TeamSans-Medium", size: 16)!
]
```

All SDK SwiftUI views read from this dictionary; you don't need to
subclass or override anything else.

## Migrating from 3.x to 4.0.0

The 4.0.0 release replaces the Objective-C SDK that 3.x clients
shipped against with a SwiftUI-native rewrite. **The public API
shape is intentionally close to 3.x** so that most call sites
need only a one-line change; the diff below covers everything you
should expect to touch in a typical 3.x integration. Each item
links back to the source-of-change in 4.0.0's surface, so if your
project uses an API not listed here, the most likely answer is
"no change."

### Quick checklist

- [ ] Update SPM dependency from `from: "3.x.x"` to `from: "4.0.0"` (and bump the package's `kind = exactVersion` if pinned).
- [ ] Drop `#import <igi_sdk/igi_sdk.h>` from your bridging header.
- [ ] `import igi_sdk` stays as-is — 4.0.0 keeps the same module name as 3.x.
- [ ] `IGIManager.shared().initialize(withApiKey:…)` → `IGIManager.shared().initialize(apiKey:…)`.
- [ ] Switch `sdkMode:` argument from a string literal to the typed `IGIManager.IGI_SDK_*_MODE` constant.
- [ ] `IGIManager.shared().startUserSession(forFirstName:…)` → `IGIManager.shared().startUserSession(firstName:…)`.
- [ ] `IGIAnalyticsListener` conformers: drop the `with*` prefix from every `track…` method's first argument label.
- [ ] Add `EXCLUDED_ARCHS[sdk=iphonesimulator*] = x86_64` to your target's build settings if your simulator build includes `x86_64` (Intel Macs, or legacy Xcode templates that still ship `x86_64` in `VALID_ARCHS`). The 4.0.0 XCFramework ships arm64 simulator slices only.
- [ ] Bump deployment target if needed: 4.0.0 requires **iOS 17.0+** (3.x supported iOS 16+).

### Source-level changes

#### 1. Bridging header

The 3.x integration exposed the Obj-C SDK to Swift via a bridging
header import. The 4.0.0 SDK is a pure Swift module — no bridging
needed.

```diff
  // YourApp-Bridging-Header.h
- #import <igi_sdk/igi_sdk.h>
```

You can leave the (now-empty) bridging header in place if your
project's `SWIFT_OBJC_BRIDGING_HEADER` build setting points at it
and you want to avoid touching the project file. Future Obj-C
imports can land here as needed.

#### 2. Swift module import

`import igi_sdk` is unchanged — 4.0.0 keeps the same module name
that 3.x clients shipped against. No edit required.

#### 3. `IGIManager.initialize`

The Obj-C selector was `initializeWithApiKey:sdkMode:subDomain:callback:`,
which Swift imported as `initialize(withApiKey:…)`. The Swift SDK
uses native parameter naming.

```diff
  IGIManager.shared().initialize(
-     withApiKey: "<API_KEY>",
-     sdkMode: "IGI_SDK_PRODUCTION_MODE",
+     apiKey: "<API_KEY>",
+     sdkMode: IGIManager.IGI_SDK_PRODUCTION_MODE,
      subDomain: "<SUBDOMAIN>",
      callback: { _, error in
          if let error { print(error.localizedDescription) }
      }
  )
```

The `sdkMode` change is technically optional — the underlying
constant value is still the string `"IGI_SDK_PRODUCTION_MODE"`, so
a 3.x literal still passes the validity check. Switching to the
typed constant is recommended because it catches typos at compile
time.

#### 4. `IGIManager.startUserSession`

Same Obj-C-bridge naming convention applied; the `for` prefix
goes away.

```diff
  IGIManager.shared().startUserSession(
-     forFirstName: nil,
+     firstName: nil,
      lastName: nil,
      email: "user@example.com",
      dob: nil,
      phoneNumber: nil
  ) { user, error in
      // …
  }
```

#### 5. `IGIAnalyticsListener` conformance

Every `track…` method drops the `with*` prefix from its first
argument label. The method body is unchanged — just the
declaration's signature.

```diff
  class AnalyticsManager: NSObject, IGIAnalyticsListener {
-     func trackPurchase(withTransactionId transactionId: String,
+     func trackPurchase(transactionId: String,
                         userId: String,
                         itemId: String,
                         itemName: String,
                         itemCategory: String,
                         price: Double,
                         quantity: Int,
                         total: Double,
                         currencyCode: String) { … }

-     func trackBid(withTransactionId transactionId: String, …, bidType: String) { … }
+     func trackBid(transactionId: String, …, bidType: String) { … }

-     func trackPromotion(withTransactionId transactionId: String, …) { … }
+     func trackPromotion(transactionId: String, …) { … }

-     func trackAddPayment(withUserId userId: String) { … }
+     func trackAddPayment(userId: String) { … }

-     func trackAddShipping(withUserId userId: String) { … }
+     func trackAddShipping(userId: String) { … }

-     func trackItemListSelection(withItemId itemId: String, …) { … }
+     func trackItemListSelection(itemId: String, …) { … }

-     func trackItemSelection(withItemId itemId: String, …) { … }
+     func trackItemSelection(itemId: String, …) { … }

      func trackEvent(_ eventName: String, attributes: [String: Any]) { … } // unchanged
  }
```

If you're conforming via Obj-C, the method names are still
`trackPurchaseWithTransactionId:…` etc. — the rename is only
visible to Swift clients.

### Project / build settings

#### Apple Silicon-only simulator

The 4.0.0 XCFramework ships **only** `arm64` device + `arm64`
simulator slices. If your sample apps or test targets are built
on an Apple Silicon Mac (most modern setups), this is invisible
— you build arm64 simulator slices anyway. If you build on an
Intel Mac, or if your target is configured to fall back to
`x86_64` for the simulator (the Xcode default in some templates),
you'll see:

```
… is missing architecture(s) required by this target (x86_64), but may still be link-compatible.
… error: unsupported Swift architecture
```

Fix: in your target's **Build Settings → Excluded Architectures**,
under **Any iOS Simulator SDK**, add `x86_64`. Or in
`project.pbxproj`:

```diff
  buildSettings = {
      …
      ENABLE_BITCODE = NO;
+     "EXCLUDED_ARCHS[sdk=iphonesimulator*]" = x86_64;
      …
  };
```

This flows from a deliberate distribution choice on our side —
the SDK fleet is fully Apple Silicon, and shipping `x86_64` would
inflate the framework size for an architecture none of our
deployments use. If a partner needs Intel-Mac simulator support,
file an issue on this repository and we'll discuss adding the
slice back.

#### Deployment target

`Package.swift` declares `platforms: [.iOS(.v17)]`. If your host
app is on iOS 16 or earlier, bump it (`General` tab → `Minimum
Deployments`) before adding the 4.0.0 dependency.

### Validation reference

A complete worked migration from a real 3.x integration is in
[`IGISampleApp_ios/`](./IGISampleApp_ios/) — sample app shipped
alongside the SDK in this repo, consuming `igi_sdk` via SwiftPM
remote URL pinned at `4.0.0` (the same way partner hosts integrate).
Files modified — `AppDelegate.swift`, `ViewController.swift`,
`AnalyticsManager.swift`, `IGISampleApp-Bridging-Header.h`, plus
the `EXCLUDED_ARCHS` line in `project.pbxproj` — cover every
change in this guide.

## Reporting issues

For SDK-level bugs / feature requests, file an issue on this
repository. For credentials, environment access, or API-key
provisioning, contact Metabilia ops directly.
