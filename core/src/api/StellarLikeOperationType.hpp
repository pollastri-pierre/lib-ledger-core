// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from stellar_like_wallet.djinni

#ifndef DJINNI_GENERATED_STELLARLIKEOPERATIONTYPE_HPP
#define DJINNI_GENERATED_STELLARLIKEOPERATIONTYPE_HPP

#include <functional>
#include <iostream>
#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

enum class StellarLikeOperationType : int {
    CREATE_ACCOUNT,
    PAYMENT,
    PATH_PAYMENT,
    MANAGE_OFFER,
    CREATE_PASSIVE_OFFER,
    SET_OPTIONALS,
    CHANGE_TRUST,
    ALLOW_TRUST,
    ACCOUNT_MERGE,
    INFLATION,
    MANAGE_DATA,
    BUMP_SEQUENCE,
};
LIBCORE_EXPORT  std::string to_string(const StellarLikeOperationType& stellarLikeOperationType);
LIBCORE_EXPORT  std::ostream &operator<<(std::ostream &os, const StellarLikeOperationType &o);

} } }  // namespace ledger::core::api

namespace std {

template <>
struct hash<::ledger::core::api::StellarLikeOperationType> {
    size_t operator()(::ledger::core::api::StellarLikeOperationType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
#endif //DJINNI_GENERATED_STELLARLIKEOPERATIONTYPE_HPP
