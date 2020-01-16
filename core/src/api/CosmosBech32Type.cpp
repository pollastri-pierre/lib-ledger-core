// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#include "CosmosBech32Type.hpp"  // my header
#include "enum_from_string.hpp"

namespace ledger { namespace core { namespace api {

std::string to_string(const CosmosBech32Type& cosmosBech32Type) {
    switch (cosmosBech32Type) {
        case CosmosBech32Type::PUBLIC_KEY: return "PUBLIC_KEY";
        case CosmosBech32Type::PUBLIC_KEY_VAL: return "PUBLIC_KEY_VAL";
        case CosmosBech32Type::ADDRESS: return "ADDRESS";
        case CosmosBech32Type::ADDRESS_VAL: return "ADDRESS_VAL";
    };
};
template <>
CosmosBech32Type from_string(const std::string& cosmosBech32Type) {
    if (cosmosBech32Type == "PUBLIC_KEY") return CosmosBech32Type::PUBLIC_KEY;
    else if (cosmosBech32Type == "PUBLIC_KEY_VAL") return CosmosBech32Type::PUBLIC_KEY_VAL;
    else if (cosmosBech32Type == "ADDRESS") return CosmosBech32Type::ADDRESS;
    else return CosmosBech32Type::ADDRESS_VAL;
};

std::ostream &operator<<(std::ostream &os, const CosmosBech32Type &o)
{
    switch (o) {
        case CosmosBech32Type::PUBLIC_KEY:  return os << "PUBLIC_KEY";
        case CosmosBech32Type::PUBLIC_KEY_VAL:  return os << "PUBLIC_KEY_VAL";
        case CosmosBech32Type::ADDRESS:  return os << "ADDRESS";
        case CosmosBech32Type::ADDRESS_VAL:  return os << "ADDRESS_VAL";
    }
}

} } }  // namespace ledger::core::api