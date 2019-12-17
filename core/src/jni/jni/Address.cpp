// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#include "Address.hpp"  // my header
#include "BitcoinLikeAddress.hpp"
#include "Currency.hpp"
#include "Marshal.hpp"
#include "StellarLikeAddress.hpp"

namespace djinni_generated {

Address::Address() : ::djinni::JniInterface<::ledger::core::api::Address, Address>("co/ledger/core/Address$CppProxy") {}

Address::~Address() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_Address_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::Address>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_co_ledger_core_Address_00024CppProxy_native_1getDerivationPath(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Address>(nativeRef);
        auto r = ref->getDerivationPath();
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_co_ledger_core_Address_00024CppProxy_native_1toString(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Address>(nativeRef);
        auto r = ref->toString();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_Address_00024CppProxy_native_1asBitcoinLikeAddress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Address>(nativeRef);
        auto r = ref->asBitcoinLikeAddress();
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni_generated::BitcoinLikeAddress>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_co_ledger_core_Address_00024CppProxy_native_1isInstanceOfBitcoinLikeAddress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Address>(nativeRef);
        auto r = ref->isInstanceOfBitcoinLikeAddress();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_Address_00024CppProxy_native_1asStellarLikeAddress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Address>(nativeRef);
        auto r = ref->asStellarLikeAddress();
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni_generated::StellarLikeAddress>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_co_ledger_core_Address_00024CppProxy_native_1isInstanceOfStellarLikeAddress(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Address>(nativeRef);
        auto r = ref->isInstanceOfStellarLikeAddress();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_Address_00024CppProxy_native_1getCurrency(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Address>(nativeRef);
        auto r = ref->getCurrency();
        return ::djinni::release(::djinni_generated::Currency::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_Address_parse(JNIEnv* jniEnv, jobject /*this*/, jstring j_address, jobject j_currency)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ledger::core::api::Address::parse(::djinni::String::toCpp(jniEnv, j_address),
                                                     ::djinni_generated::Currency::toCpp(jniEnv, j_currency));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni_generated::Address>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_co_ledger_core_Address_isValid(JNIEnv* jniEnv, jobject /*this*/, jstring j_address, jobject j_currency)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ledger::core::api::Address::isValid(::djinni::String::toCpp(jniEnv, j_address),
                                                       ::djinni_generated::Currency::toCpp(jniEnv, j_currency));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
