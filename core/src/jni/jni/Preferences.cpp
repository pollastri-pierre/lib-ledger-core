// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from preferences.djinni

#include "Preferences.hpp"  // my header
#include "Marshal.hpp"
#include "PreferencesEditor.hpp"

namespace djinni_generated {

Preferences::Preferences() : ::djinni::JniInterface<::ledger::core::api::Preferences, Preferences>("co/ledger/core/Preferences$CppProxy") {}

Preferences::~Preferences() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_Preferences_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::Preferences>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jstring JNICALL Java_co_ledger_core_Preferences_00024CppProxy_native_1getString(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_key, jstring j_fallbackValue)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Preferences>(nativeRef);
        auto r = ref->getString(::djinni::String::toCpp(jniEnv, j_key),
                                ::djinni::String::toCpp(jniEnv, j_fallbackValue));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jint JNICALL Java_co_ledger_core_Preferences_00024CppProxy_native_1getInt(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_key, jint j_fallbackValue)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Preferences>(nativeRef);
        auto r = ref->getInt(::djinni::String::toCpp(jniEnv, j_key),
                             ::djinni::I32::toCpp(jniEnv, j_fallbackValue));
        return ::djinni::release(::djinni::I32::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jlong JNICALL Java_co_ledger_core_Preferences_00024CppProxy_native_1getLong(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_key, jlong j_fallbackValue)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Preferences>(nativeRef);
        auto r = ref->getLong(::djinni::String::toCpp(jniEnv, j_key),
                              ::djinni::I64::toCpp(jniEnv, j_fallbackValue));
        return ::djinni::release(::djinni::I64::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_co_ledger_core_Preferences_00024CppProxy_native_1getBoolean(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_key, jboolean j_fallbackValue)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Preferences>(nativeRef);
        auto r = ref->getBoolean(::djinni::String::toCpp(jniEnv, j_key),
                                 ::djinni::Bool::toCpp(jniEnv, j_fallbackValue));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_Preferences_00024CppProxy_native_1getStringArray(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_key, jobject j_fallbackValue)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Preferences>(nativeRef);
        auto r = ref->getStringArray(::djinni::String::toCpp(jniEnv, j_key),
                                     ::djinni::List<::djinni::String>::toCpp(jniEnv, j_fallbackValue));
        return ::djinni::release(::djinni::List<::djinni::String>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_co_ledger_core_Preferences_00024CppProxy_native_1getData(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_key, jbyteArray j_fallbackValue)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Preferences>(nativeRef);
        auto r = ref->getData(::djinni::String::toCpp(jniEnv, j_key),
                              ::djinni::Binary::toCpp(jniEnv, j_fallbackValue));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_co_ledger_core_Preferences_00024CppProxy_native_1contains(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_key)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Preferences>(nativeRef);
        auto r = ref->contains(::djinni::String::toCpp(jniEnv, j_key));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_Preferences_00024CppProxy_native_1edit(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::Preferences>(nativeRef);
        auto r = ref->edit();
        return ::djinni::release(::djinni_generated::PreferencesEditor::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
