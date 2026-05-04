//
//  AppDelegate.swift
//  IGISampleApp
//
//  Created by Hammad Mehmood on 06/01/2020.
//  Copyright © 2020 Hammad Mehmood. All rights reserved.
//

import UIKit
import igi_sdk
import FirebaseMessaging
import FirebaseCore

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        FirebaseApp.configure()
        Messaging.messaging().delegate = self

        initializeIGISDK()

        UNUserNotificationCenter.current().delegate = self
        UNUserNotificationCenter.current().requestAuthorization(
            options: [.alert, .badge, .sound],
            completionHandler: { _, _ in })
        application.registerForRemoteNotifications()

        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func initializeIGISDK() {
        IGIManager.shared().initialize(apiKey: "ff64-f61c-7ff8-d183-b746-731b-e3f1",
                                       sdkMode: IGIManager.IGI_SDK_DEV_MODE,
                                       subDomain: "demo",
                                       callback: { (_: Any?, error: Error?) in
            if let error = error {
                NSLog(error.localizedDescription)
            }
        })

        IGIManager.shared().setAnalyticsDelegate(AnalyticsManager.shared)
    }
}

extension AppDelegate: MessagingDelegate {

    func messaging(_ messaging: Messaging, didReceiveRegistrationToken fcmToken: String?) {
        print("Firebase registration token: \(String(describing: fcmToken))")
        IGIManager.shared().setDeviceToken(fcmToken)
    }
}

extension AppDelegate: UNUserNotificationCenterDelegate {

    /// Foreground push presentation — let the user see the banner even
    /// when the app is open.
    func userNotificationCenter(_ center: UNUserNotificationCenter,
                                willPresent notification: UNNotification) async
    -> UNNotificationPresentationOptions {
        return [.sound, .banner, .badge]
    }

    /// Tap-routing — fires for both warm taps (app already running)
    /// and cold-start taps (app was killed). iOS waits until the
    /// window/scene is ready before dispatching the response on
    /// cold-start, so no scene-side handling is needed.
    func userNotificationCenter(_ center: UNUserNotificationCenter,
                                didReceive response: UNNotificationResponse) async {
        let userInfo = response.notification.request.content.userInfo
        if IGIManager.shouldHandleRemodeMessage(userInfo) {
            IGIManager.shared().handleRemoteMessage(userInfo)
        }
    }
}
