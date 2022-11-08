//
//  OtlpTraceExporter.h
//  BugsnagPerformance
//
//  Created by Nick Dowell on 05/10/2022.
//

#import <Foundation/Foundation.h>

#import "SpanExporter.h"
#import "OtlpPackage.h"
#import "OtlpSendQueue.h"
#import "Uploader.h"

namespace bugsnag {

/**
 * Exports traces, sending them to the server.
 * Handles retrying if the server is unreachable.
 */
class OtlpTraceExporter: public SpanExporter {
public:
    OtlpTraceExporter(NSDictionary *resourceAttributes, std::shared_ptr<Uploader> uploader) noexcept
    : resourceAttributes_(resourceAttributes)
    , uploader_(std::move(uploader))
    {}

    /**
     * Export spans to the server. The set of spans will be queued if the server is currently unreachable.
     * Will also drain the queue if the current request succeeds.
     */
    void exportSpans(std::vector<std::unique_ptr<SpanData>> spans) noexcept override;

    /**
     * Notify this object that network connectivity has been re-established, and it can retry previously failed requests.
     */
    void notifyConnectivityReestablished() noexcept;
    
private:
    NSDictionary *resourceAttributes_;
    std::shared_ptr<Uploader> uploader_;
    OtlpSendQueue retryQueue_;
    
    std::unique_ptr<OtlpPackage> buildPackage(const std::vector<std::unique_ptr<SpanData>> &spans) const noexcept;
    
    void uploadPackage(std::unique_ptr<OtlpPackage> package) noexcept;
    void sendNextRetry(void) noexcept;
};
}
