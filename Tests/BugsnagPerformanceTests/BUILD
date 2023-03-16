load(
    "@build_bazel_rules_apple//apple:ios.bzl",
    "ios_unit_test",
)

objc_library(
    name = "FileBasedTest",
    srcs = [
        "FileBasedTest.m",
    ],
    hdrs = [
        "FileBasedTest.h",
    ],
    copts = [
        "-w",
    ],
    deps = [
        "//:BugsnagPerformance",
    ],
)

objc_library(
    name = "FilesystemTests",
    srcs = ["FilesystemTests.m"],
    copts = [
        "-w",
    ],
    deps = [
        ":FileBasedTest",
    ],
)

objc_library(
    name = "BugsnagPerformanceTests",
    srcs = glob([
        "**/*.mm",
    ]),
    copts = [
        "-std=c++14",
        "-w",
    ],
    deps = [
        ":FileBasedTest",
        "//:BugsnagPerformance",
    ],
)

ios_unit_test(
    name = "BugsnagPerformanceUnitTests",
    minimum_os_version = "11.0",
    deps = [
        ":BugsnagPerformanceTests",
        ":FilesystemTests",
    ],
)
