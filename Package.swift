// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

// Package layout
// --------------
// The library product `igi_sdk` is an "umbrella" target that bundles
// three things consumers want with a single SPM dependency:
//   1. The compiled SDK as a binary `.xcframework`. As of 2026-05-01
//      the framework's Swift module name and the library product
//      name both equal `igi_sdk` — consumer code is
//      `import igi_sdk`. (Earlier 4.0.x prereleases shipped under
//      `igi_sdk_swift` while the legacy Obj-C target still owned
//      the `igi_sdk` name; that ambiguity is gone.)
//   2. The SDK's transitive Swift Package deps (Stripe + PusherSwift)
//      so the consumer doesn't have to add them separately.
//   3. The wrapper Swift target `igi_sdk` itself, which exists only
//      because SwiftPM requires every `.target()` to declare at
//      least one source file. `Sources/igi_sdk/dummy.c` is the
//      placeholder; the wrapper is otherwise empty. Consumers
//      depending on the `igi_sdk` library product transitively pick
//      up everything above.
let package = Package(
    name: "igi_sdk",
    platforms: [
        .iOS(.v17)
    ],
    products: [
        .library(
            name: "igi_sdk",
            targets: ["igi_sdk"]),
    ],
    dependencies: [
        .package(url: "https://github.com/stripe/stripe-ios-spm", exact: "25.6.2"),
        .package(url: "https://github.com/pusher/pusher-websocket-swift.git", exact: "10.1.5"),
    ],
    targets: [
        .target(
            name: "igi_sdk",
            dependencies: [
                .target(name: "igi_framework", condition: .when(platforms: [.iOS])),
                .product(name: "PusherSwift", package: "pusher-websocket-swift"),
                .product(name: "Stripe", package: "stripe-ios-spm"),
                .product(name: "StripePaymentSheet", package: "stripe-ios-spm")
            ]
        ),
        // Binary target — `igi_sdk.xcframework` is produced by
        // `ios_sdk/scripts/build_xcframework.sh` (defaults to the
        // `igi_sdk` scheme). Drop the resulting xcframework into
        // `Sources/Frameworks/` and commit it; SPM consumes the
        // path-relative bundle directly. (We're not yet using the
        // remote-URL `.binaryTarget` form because the SPM repo is
        // private and a path-relative file is the simplest
        // validation path for the first 4.0.0 release.)
        .binaryTarget(name: "igi_framework", path: "./Sources/Frameworks/igi_sdk.xcframework")
    ]
)
