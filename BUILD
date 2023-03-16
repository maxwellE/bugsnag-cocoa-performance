objc_library(
    name = "BugsnagPerformanceCXX",
    srcs = glob([
        "Sources/BugsnagPerformance/**/*.mm",
        "Sources/BugsnagPerformance/**/*.h",
    ]),
    copts = [
        "-std=c++14",
        "-w",
    ],
    includes = [
        "Sources/BugsnagPerformance",
        "Sources/BugsnagPerformance/Private",
        "Sources/BugsnagPerformance/Private/Instrumentation",
        "Sources/BugsnagPerformance/Private/Instrumentation/NetworkInstrumentation",
        "Sources/BugsnagPerformance/Public",
        "Sources/BugsnagPerformance/include",
        "Sources/BugsnagPerformance/include/BugsnagPerformance",
    ],
)

objc_library(
    name = "BugsnagPerformance",
    srcs = glob(
        [
            "Sources/BugsnagPerformance/Private/**/*.h",
            "Sources/BugsnagPerformance/**/*.m",
            "Sources/BugsnagPerformance/**/*.c",
        ],
        allow_empty = False,
    ),
    hdrs = glob(
        [
            "Sources/BugsnagPerformance/**/*.h",
        ],
        [
            "Sources/BugsnagPerformance/Private/**/*.h",
        ],
        allow_empty = False,
    ),
    copts = [
        "-w",
    ],
    includes = [
        "Sources/BugsnagPerformance",
        "Sources/BugsnagPerformance/Private",
        "Sources/BugsnagPerformance/Private/Instrumentation",
        "Sources/BugsnagPerformance/Private/Instrumentation/NetworkInstrumentation",
        "Sources/BugsnagPerformance/Public",
        "Sources/BugsnagPerformance/include",
        "Sources/BugsnagPerformance/include/BugsnagPerformance",
    ],
    module_name = "BugsnagPerformance",
    sdk_dylibs = [
        "z",
        "c++",
    ],
    sdk_frameworks = [
        "Foundation",
        "SystemConfiguration",
        "Security",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":BugsnagPerformanceCXX",
    ],
)
