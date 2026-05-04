//
//  AnalyticsManager.swift
//  IGISampleApp
//
//  Created by Hammad Mehmood on 03/06/2025.
//  Copyright © 2025 Hammad Mehmood. All rights reserved.
//

import Foundation
import igi_sdk

// `IGIAnalyticsListener` method labels lost their `with*` prefixes
// when the SDK moved from Obj-C to Swift-native. Legacy:
//   `trackPurchase(withTransactionId:userId:itemId:…)`
// New:
//   `trackPurchase(transactionId:userId:itemId:…)`
// The `with` prefix was a Swift import of the Obj-C selector
// `trackPurchaseWithTransactionId:userId:itemId:…`. The new Swift
// protocol uses bare external labels. Same pattern across every
// other `track*` method on the protocol.
class AnalyticsManager: NSObject, IGIAnalyticsListener {
    static let shared = AnalyticsManager()

    private override init() {
        super.init()
    }
    func trackPurchase(transactionId: String, userId: String, itemId: String, itemName: String, itemCategory: String, price: Double, quantity: Int, total: Double, currencyCode: String) {
        print("Tracking purchase: \(itemName), \(price) \(currencyCode)")
    }

    func trackBid(transactionId: String, userId: String, itemId: String, itemName: String, itemCategory: String, price: Double, quantity: Int, total: Double, currencyCode: String, bidType: String) {
        print("Tracking bid of type \(bidType): \(itemName), \(price) \(currencyCode)")
    }

    func trackPromotion(transactionId: String, userId: String, itemId: String, itemName: String, itemCategory: String, price: Double, quantity: Int, total: Double, currencyCode: String) {
        print("Tracking promotion: \(itemName), \(price) \(currencyCode)")
    }

    func trackAddPayment(userId: String) {
        print("Tracking add payment method for user \(userId)")
    }

    func trackAddShipping(userId: String) {
        print("Tracking add shipping for user \(userId)")
    }

    func trackItemListSelection(itemId: String, itemName: String, itemCategory: String) {
        print("Tracking item list selection: \(itemName)")
    }

    func trackItemSelection(itemId: String, itemName: String, itemCategory: String, price: Double) {
        print("Tracking item selection: \(itemName), \(price)")
    }

    func trackEvent(_ eventName: String, attributes: [String : Any]) {
        print("Tracking custom event: \(eventName) with attributes: \(attributes)")
    }
}
