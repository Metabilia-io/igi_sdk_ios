//
//  ViewController.swift
//  IGISampleApp
//
//  Created by Hammad Mehmood on 06/01/2020.
//  Copyright © 2020 Hammad Mehmood. All rights reserved.
//

import UIKit
import igi_sdk

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func viewEventsButtonPressed(_ sender: Any) {

        IGISVProgressHUD.show()

        // `forFirstName:` → `firstName:` (legacy Obj-C bridging
        // added the `for` prefix; the Swift SDK uses the bare
        // `firstName:` label).
        IGIManager.shared().startUserSession(
            firstName: nil,
            lastName: nil,
            email: "abc@def.com",
            dob: nil,
            phoneNumber: nil) { (user, error: Error?) in

                IGISVProgressHUD.dismiss()

                if(error == nil) {


                }

                else {

                    NSLog(error!.localizedDescription)
                }

                self.showEventsScreen()
        }
    }

    func showEventsScreen() {
        // `IGIManager.shared().eventsScreen()` still returns a
        // `UINavigationController?` in the new SDK — the SwiftUI
        // surface is wrapped internally so the legacy "present a
        // UIViewController" call site keeps working unchanged.
        let eventsScreen = IGIManager.shared().eventsScreen()!

        navigationController?.present(eventsScreen, animated: true, completion: nil)
    }
}

