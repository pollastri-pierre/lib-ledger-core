// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKETRANSACTION_HPP
#define DJINNI_GENERATED_COSMOSLIKETRANSACTION_HPP

#include <chrono>
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
class CosmosLikeMessage;

/**Class representing a Cosmos transaction */
class LIBCORE_EXPORT CosmosLikeTransaction {
public:
    virtual ~CosmosLikeTransaction() {}

    /** Get the hash of the transaction. */
    virtual std::string getHash() const = 0;

    /** Get Fee (in drop) */
    virtual std::shared_ptr<Amount> getFee() const = 0;

    /** Serialize the transaction to its JSON format. */
    virtual std::string serialize() = 0;

    /** Get the list of messages */
    virtual std::vector<std::shared_ptr<CosmosLikeMessage>> getMessages() const = 0;

    /** Get memo */
    virtual std::string getMemo() const = 0;

    /** Set signature of transaction, when a signature is set serialize method gives back serialized Tx */
    virtual void setSignature(const std::vector<uint8_t> & rSignature, const std::vector<uint8_t> & sSignature) = 0;

    virtual void setDERSignature(const std::vector<uint8_t> & signature) = 0;

    /**
     * Get the time when the transaction was issued or the time of the block including
     * this transaction
     */
    virtual std::chrono::system_clock::time_point getDate() const = 0;

    /** Get Signing public Key */
    virtual std::vector<uint8_t> getSigningPubKey() const = 0;

    virtual std::shared_ptr<Amount> getGas() const = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSLIKETRANSACTION_HPP
