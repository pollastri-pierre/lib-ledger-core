// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from emitter.djinni

#import <Foundation/Foundation.h>
@protocol LGEventReceiver;
@protocol LGExecutionContext;


@interface LGEventEmitter : NSObject

- (void)register:(nullable id<LGExecutionContext>)context
        receiver:(nullable id<LGEventReceiver>)receiver;

- (void)unregister:(nullable id<LGEventReceiver>)receiver;

@end