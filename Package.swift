// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "igi_sdk",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "igi_sdk",
            targets: ["igi_sdk"]),
    ],
    dependencies: [
        .package(url: "https://github.com/stripe/stripe-ios-spm", exact: "24.12.0"),
        .package(url: "https://github.com/pusher/pusher-websocket-swift.git", exact: "10.1.5"),
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .target(
            name: "igi_sdk",
            dependencies: [
                .target(name: "igi_framework", condition: .when(platforms: [.iOS])),
                .product(name: "PusherSwift", package: "pusher-websocket-swift"),
                .product(name: "Stripe", package: "stripe-ios-spm")
            ]
        ),
        .binaryTarget(name: "igi_framework", path: "./Sources/Frameworks/igi_sdk.xcframework")
    ]
)
