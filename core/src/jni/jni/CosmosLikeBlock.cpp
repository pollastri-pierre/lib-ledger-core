// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#include "CosmosLikeBlock.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

CosmosLikeBlock::CosmosLikeBlock() : ::djinni::JniInterface<::ledger::core::api::CosmosLikeBlock, CosmosLikeBlock>("co/ledger/core/CosmosLikeBlock$CppProxy") {}

CosmosLikeBlock::~CosmosLikeBlock() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_CosmosLikeBlock_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::CosmosLikeBlock>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_co_ledger_core_CosmosLikeBlock_00024CppProxy_native_1getHash(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeBlock>(nativeRef);
        auto r = ref->getHash();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jlong JNICALL Java_co_ledger_core_CosmosLikeBlock_00024CppProxy_native_1getHeight(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeBlock>(nativeRef);
        auto r = ref->getHeight();
        return ::djinni::release(::djinni::I64::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_CosmosLikeBlock_00024CppProxy_native_1getTime(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeBlock>(nativeRef);
        auto r = ref->getTime();
        return ::djinni::release(::djinni::Date::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
