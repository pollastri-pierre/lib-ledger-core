// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP
#define DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP

#include "CosmosLikeAmount.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace ledger { namespace core { namespace api {

struct CosmosLikeMsgSend final {
    std::string fromAddress;
    std::string toAddress;
    std::vector<CosmosLikeAmount> amounts;

    CosmosLikeMsgSend(std::string fromAddress_,
                      std::string toAddress_,
                      std::vector<CosmosLikeAmount> amounts_)
    : fromAddress(std::move(fromAddress_))
    , toAddress(std::move(toAddress_))
    , amounts(std::move(amounts_))
    {}

    CosmosLikeMsgSend(const CosmosLikeMsgSend& cpy) {
       this->fromAddress = cpy.fromAddress;
       this->toAddress = cpy.toAddress;
       this->amounts = cpy.amounts;
    }

    CosmosLikeMsgSend() = default;


    CosmosLikeMsgSend& operator=(const CosmosLikeMsgSend& cpy) {
       this->fromAddress = cpy.fromAddress;
       this->toAddress = cpy.toAddress;
       this->amounts = cpy.amounts;
       return *this;
    }

    template <class Archive>
    void load(Archive& archive) {
        archive(fromAddress, toAddress, amounts);
    }

    template <class Archive>
    void save(Archive& archive) const {
        archive(fromAddress, toAddress, amounts);
    }
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSLIKEMSGSEND_HPP
