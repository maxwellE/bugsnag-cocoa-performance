//
//  Reachability.h
//  BugsnagPerformance
//
//  Created by Nick Dowell on 03/11/2022.
//  Copyright © 2022 Bugsnag. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <vector>

namespace bugsnag {
class Reachability {
public:
    static Reachability &get() noexcept; 
    
    enum Connectivity {
        Unknown,
        None,
        Cellular,
        Wifi,
    };
    
    Connectivity getConnectivity() noexcept { return connectivity_; }
    
    void addCallback(void (^)(Connectivity));
    
private:
    Reachability() noexcept;
    
    static void callback(SCNetworkReachabilityRef target,
                         SCNetworkReachabilityFlags flags,
                         void *info) noexcept;
    
    static CFStringRef copyDescription(__unused const void *info) {
        return CFSTR("bugsnag::Reachability");
    }
    
    std::vector<void (^)(Connectivity)> callbacks_;
    dispatch_queue_t queue_{nullptr};
    SCNetworkReachabilityContext context_{
        .version = 0,
        .info = this,
        .retain = nullptr,
        .release = nullptr,
        .copyDescription = copyDescription
    };
    SCNetworkReachabilityRef target_{nullptr};
    Connectivity connectivity_{Connectivity::Unknown};
};
}
