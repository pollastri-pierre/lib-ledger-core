// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from websocket_client.djinni

#include "WebSocketConnection.hpp"  // my header
#include "ErrorCode.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

WebSocketConnection::WebSocketConnection() : ::djinni::JniInterface<::ledger::core::api::WebSocketConnection, WebSocketConnection>("WebSocketConnection$CppProxy") {}

WebSocketConnection::~WebSocketConnection() = default;


CJNIEXPORT void JNICALL Java_WebSocketConnection_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::WebSocketConnection>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_WebSocketConnection_00024CppProxy_native_1onConnect(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_connectionId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::WebSocketConnection>(nativeRef);
        ref->onConnect(::djinni::I32::toCpp(jniEnv, j_connectionId));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_WebSocketConnection_00024CppProxy_native_1onClose(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::WebSocketConnection>(nativeRef);
        ref->onClose();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_WebSocketConnection_00024CppProxy_native_1onMessage(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_data)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::WebSocketConnection>(nativeRef);
        ref->onMessage(::djinni::String::toCpp(jniEnv, j_data));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_WebSocketConnection_00024CppProxy_native_1onError(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_code, jstring j_message)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::WebSocketConnection>(nativeRef);
        ref->onError(::djinni_generated::ErrorCode::toCpp(jniEnv, j_code),
                     ::djinni::String::toCpp(jniEnv, j_message));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jint JNICALL Java_WebSocketConnection_00024CppProxy_native_1getConnectionId(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::WebSocketConnection>(nativeRef);
        auto r = ref->getConnectionId();
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
