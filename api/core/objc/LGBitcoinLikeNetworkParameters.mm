// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#import "LGBitcoinLikeNetworkParameters.h"


@implementation LGBitcoinLikeNetworkParameters

- (nonnull instancetype)initWithIdentifier:(nonnull NSString *)Identifier
                              P2PKHVersion:(nonnull NSData *)P2PKHVersion
                               P2SHVersion:(nonnull NSData *)P2SHVersion
                               XPUBVersion:(nonnull NSData *)XPUBVersion
                                 FeePolicy:(LGBitcoinLikeFeePolicy)FeePolicy
                                DustAmount:(int64_t)DustAmount
                             MessagePrefix:(nonnull NSString *)MessagePrefix
                UsesTimestampedTransaction:(BOOL)UsesTimestampedTransaction
                                   SigHash:(nonnull NSData *)SigHash
{
    if (self = [super init]) {
        _Identifier = [Identifier copy];
        _P2PKHVersion = [P2PKHVersion copy];
        _P2SHVersion = [P2SHVersion copy];
        _XPUBVersion = [XPUBVersion copy];
        _FeePolicy = FeePolicy;
        _DustAmount = DustAmount;
        _MessagePrefix = [MessagePrefix copy];
        _UsesTimestampedTransaction = UsesTimestampedTransaction;
        _SigHash = [SigHash copy];
    }
    return self;
}

+ (nonnull instancetype)BitcoinLikeNetworkParametersWithIdentifier:(nonnull NSString *)Identifier
                                                      P2PKHVersion:(nonnull NSData *)P2PKHVersion
                                                       P2SHVersion:(nonnull NSData *)P2SHVersion
                                                       XPUBVersion:(nonnull NSData *)XPUBVersion
                                                         FeePolicy:(LGBitcoinLikeFeePolicy)FeePolicy
                                                        DustAmount:(int64_t)DustAmount
                                                     MessagePrefix:(nonnull NSString *)MessagePrefix
                                        UsesTimestampedTransaction:(BOOL)UsesTimestampedTransaction
                                                           SigHash:(nonnull NSData *)SigHash
{
    return [[self alloc] initWithIdentifier:Identifier
                               P2PKHVersion:P2PKHVersion
                                P2SHVersion:P2SHVersion
                                XPUBVersion:XPUBVersion
                                  FeePolicy:FeePolicy
                                 DustAmount:DustAmount
                              MessagePrefix:MessagePrefix
                 UsesTimestampedTransaction:UsesTimestampedTransaction
                                    SigHash:SigHash];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p Identifier:%@ P2PKHVersion:%@ P2SHVersion:%@ XPUBVersion:%@ FeePolicy:%@ DustAmount:%@ MessagePrefix:%@ UsesTimestampedTransaction:%@ SigHash:%@>", self.class, (void *)self, self.Identifier, self.P2PKHVersion, self.P2SHVersion, self.XPUBVersion, @(self.FeePolicy), @(self.DustAmount), self.MessagePrefix, @(self.UsesTimestampedTransaction), self.SigHash];
}

@end
