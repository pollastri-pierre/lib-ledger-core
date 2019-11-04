// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#include "CosmosLikeMsgType.hpp"  // my header
#include "enum_from_string.hpp"

namespace ledger { namespace core { namespace api {

std::string to_string(const CosmosLikeMsgType& cosmosLikeMsgType) {
    switch (cosmosLikeMsgType) {
        case CosmosLikeMsgType::MSGSEND: return "MSGSEND";
        case CosmosLikeMsgType::MSGDELEGATE: return "MSGDELEGATE";
        case CosmosLikeMsgType::MSGUNDELEGATE: return "MSGUNDELEGATE";
        case CosmosLikeMsgType::MSGREDELEGATE: return "MSGREDELEGATE";
        case CosmosLikeMsgType::MSGSUBMITPROPOSAL: return "MSGSUBMITPROPOSAL";
        case CosmosLikeMsgType::MSGVOTE: return "MSGVOTE";
        case CosmosLikeMsgType::MSGDEPOSIT: return "MSGDEPOSIT";
        case CosmosLikeMsgType::MSGWITHDRAWDELEGATIONREWARD: return "MSGWITHDRAWDELEGATIONREWARD";
    };
};
template <>
CosmosLikeMsgType from_string(const std::string& cosmosLikeMsgType) {
    if (cosmosLikeMsgType == "MSGSEND") return CosmosLikeMsgType::MSGSEND;
    else if (cosmosLikeMsgType == "MSGDELEGATE") return CosmosLikeMsgType::MSGDELEGATE;
    else if (cosmosLikeMsgType == "MSGUNDELEGATE") return CosmosLikeMsgType::MSGUNDELEGATE;
    else if (cosmosLikeMsgType == "MSGREDELEGATE") return CosmosLikeMsgType::MSGREDELEGATE;
    else if (cosmosLikeMsgType == "MSGSUBMITPROPOSAL") return CosmosLikeMsgType::MSGSUBMITPROPOSAL;
    else if (cosmosLikeMsgType == "MSGVOTE") return CosmosLikeMsgType::MSGVOTE;
    else if (cosmosLikeMsgType == "MSGDEPOSIT") return CosmosLikeMsgType::MSGDEPOSIT;
    else return CosmosLikeMsgType::MSGWITHDRAWDELEGATIONREWARD;
};

std::ostream &operator<<(std::ostream &os, const CosmosLikeMsgType &o)
{
    switch (o) {
        case CosmosLikeMsgType::MSGSEND:  return os << "MSGSEND";
        case CosmosLikeMsgType::MSGDELEGATE:  return os << "MSGDELEGATE";
        case CosmosLikeMsgType::MSGUNDELEGATE:  return os << "MSGUNDELEGATE";
        case CosmosLikeMsgType::MSGREDELEGATE:  return os << "MSGREDELEGATE";
        case CosmosLikeMsgType::MSGSUBMITPROPOSAL:  return os << "MSGSUBMITPROPOSAL";
        case CosmosLikeMsgType::MSGVOTE:  return os << "MSGVOTE";
        case CosmosLikeMsgType::MSGDEPOSIT:  return os << "MSGDEPOSIT";
        case CosmosLikeMsgType::MSGWITHDRAWDELEGATIONREWARD:  return os << "MSGWITHDRAWDELEGATIONREWARD";
    }
}

} } }  // namespace ledger::core::api
