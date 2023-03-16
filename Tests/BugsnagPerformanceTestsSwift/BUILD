load(
    "@build_bazel_rules_swift//swift:swift.bzl",
    "swift_library",
)
load(
    "@build_bazel_rules_apple//apple:ios.bzl",
    "ios_unit_test",
)

swift_library(
    name = "BugsnagPerformanceTestsSwift",
    testonly = True,
    srcs = glob([
        "*.swift",
    ]),
    deps = [
        "//:BugsnagPerformance",
    ],
)

ios_unit_test(
    name = "BugsnagPerformanceUnitTestsSwift",
    minimum_os_version = "11.0",
    deps = [
        ":BugsnagPerformanceTestsSwift",
    ],
)
