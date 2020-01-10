// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from secp256k1.djinni

#include "Secp256k1.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

Secp256k1::Secp256k1() : ::djinni::JniInterface<::ledger::core::api::Secp256k1, Secp256k1>("co/ledger/core/Secp256k1$CppProxy") {}

Secp256k1::~Secp256k1() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_Secp256k1_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::Secp256k1>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_Secp256k1_createInstance(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ledger::core::api::Secp256k1::createInstance();
        return ::djinni::release(::djinni_generated::Secp256k1::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_co_ledger_core_Secp256k1_00024CppProxy_native_1computePubKey(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_privKey, jboolean j_compress)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Secp256k1>(nativeRef);
        auto r = ref->computePubKey(::djinni::Binary::toCpp(jniEnv, j_privKey),
                                    ::djinni::Bool::toCpp(jniEnv, j_compress));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_co_ledger_core_Secp256k1_00024CppProxy_native_1computeUncompressedPubKey(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_pubKey)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Secp256k1>(nativeRef);
        auto r = ref->computeUncompressedPubKey(::djinni::Binary::toCpp(jniEnv, j_pubKey));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_co_ledger_core_Secp256k1_00024CppProxy_native_1sign(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_privKey, jbyteArray j_data)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Secp256k1>(nativeRef);
        auto r = ref->sign(::djinni::Binary::toCpp(jniEnv, j_privKey),
                           ::djinni::Binary::toCpp(jniEnv, j_data));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_co_ledger_core_Secp256k1_00024CppProxy_native_1verify(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_data, jbyteArray j_signature, jbyteArray j_pubKey)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Secp256k1>(nativeRef);
        auto r = ref->verify(::djinni::Binary::toCpp(jniEnv, j_data),
                             ::djinni::Binary::toCpp(jniEnv, j_signature),
                             ::djinni::Binary::toCpp(jniEnv, j_pubKey));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_Secp256k1_newInstance(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ledger::core::api::Secp256k1::newInstance();
        return ::djinni::release(::djinni_generated::Secp256k1::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
