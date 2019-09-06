// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from stellar_like_wallet.djinni

#ifndef DJINNI_GENERATED_STELLARLIKETRANSACTIONBUILDER_HPP
#define DJINNI_GENERATED_STELLARLIKETRANSACTIONBUILDER_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class Amount;
class BigInt;
class StellarLikeTransactionCallback;

class LIBCORE_EXPORT StellarLikeTransactionBuilder {
public:
    virtual ~StellarLikeTransactionBuilder() {}

    virtual std::shared_ptr<StellarLikeTransactionBuilder> addNativePayment(const std::string & address, const std::shared_ptr<Amount> & amount) = 0;

    virtual std::shared_ptr<StellarLikeTransactionBuilder> addCreateAccount(const std::string & address, const std::shared_ptr<Amount> & amount) = 0;

    virtual std::shared_ptr<StellarLikeTransactionBuilder> setBaseFee(const std::shared_ptr<Amount> & baseFee) = 0;

    virtual std::shared_ptr<StellarLikeTransactionBuilder> putSignature(const std::vector<uint8_t> & signature) = 0;

    virtual std::shared_ptr<StellarLikeTransactionBuilder> setTextMemo(const std::string & text) = 0;

    virtual std::shared_ptr<StellarLikeTransactionBuilder> setNumberMemo(const std::shared_ptr<BigInt> & number) = 0;

    virtual std::shared_ptr<StellarLikeTransactionBuilder> setHashMemo(const std::vector<uint8_t> & hash) = 0;

    virtual std::shared_ptr<StellarLikeTransactionBuilder> setReturnMemo(const std::vector<uint8_t> & value) = 0;

    virtual std::shared_ptr<StellarLikeTransactionBuilder> setSequence(const std::shared_ptr<BigInt> & sequence) = 0;

    virtual void build(const std::shared_ptr<StellarLikeTransactionCallback> & callback) = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_STELLARLIKETRANSACTIONBUILDER_HPP
