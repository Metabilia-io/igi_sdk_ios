//
//  SceneDelegate.swift
//  IGISampleApp
//
//  Created by Hammad Mehmood on 06/01/2020.
//  Copyright © 2020 Hammad Mehmood. All rights reserved.
//

import UIKit

class SceneDelegate: UIResponder, UIWindowSceneDelegate {

    var window: UIWindow?

    func scene(_ scene: UIScene,
               willConnectTo session: UISceneSession,
               options connectionOptions: UIScene.ConnectionOptions) {
        // The window is auto-loaded via `UISceneStoryboardFile = Main`
        // in Info.plist — no manual UIWindow setup needed here. Push
        // tap-routing happens in `AppDelegate`'s
        // `userNotificationCenter(_:didReceive:)` for both warm and
        // cold-start taps.
        guard scene is UIWindowScene else { return }
    }
}
