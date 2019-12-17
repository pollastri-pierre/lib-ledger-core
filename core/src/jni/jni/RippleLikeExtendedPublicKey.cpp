// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#include "RippleLikeExtendedPublicKey.hpp"  // my header
#include "Marshal.hpp"
#include "RippleLikeAddress.hpp"

namespace djinni_generated {

RippleLikeExtendedPublicKey::RippleLikeExtendedPublicKey() : ::djinni::JniInterface<::ledger::core::api::RippleLikeExtendedPublicKey, RippleLikeExtendedPublicKey>("RippleLikeExtendedPublicKey$CppProxy") {}

RippleLikeExtendedPublicKey::~RippleLikeExtendedPublicKey() = default;


CJNIEXPORT void JNICALL Java_RippleLikeExtendedPublicKey_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::RippleLikeExtendedPublicKey>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_RippleLikeExtendedPublicKey_00024CppProxy_native_1derive(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_path)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::RippleLikeExtendedPublicKey>(nativeRef);
        auto r = ref->derive(::djinni::String::toCpp(jniEnv, j_path));
        return ::djinni::release(::djinni_generated::RippleLikeAddress::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_RippleLikeExtendedPublicKey_00024CppProxy_native_1derivePublicKey(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_path)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::RippleLikeExtendedPublicKey>(nativeRef);
        auto r = ref->derivePublicKey(::djinni::String::toCpp(jniEnv, j_path));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_RippleLikeExtendedPublicKey_00024CppProxy_native_1deriveHash160(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_path)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::RippleLikeExtendedPublicKey>(nativeRef);
        auto r = ref->deriveHash160(::djinni::String::toCpp(jniEnv, j_path));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_RippleLikeExtendedPublicKey_00024CppProxy_native_1toBase58(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::RippleLikeExtendedPublicKey>(nativeRef);
        auto r = ref->toBase58();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_RippleLikeExtendedPublicKey_00024CppProxy_native_1getRootPath(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::RippleLikeExtendedPublicKey>(nativeRef);
        auto r = ref->getRootPath();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
