// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from dynamic.djinni

#include "DynamicArray.hpp"  // my header
#include "DynamicObject.hpp"
#include "DynamicType.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

DynamicArray::DynamicArray() : ::djinni::JniInterface<::ledger::core::api::DynamicArray, DynamicArray>("DynamicArray$CppProxy") {}

DynamicArray::~DynamicArray() = default;


CJNIEXPORT void JNICALL Java_DynamicArray_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::DynamicArray>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jlong JNICALL Java_DynamicArray_00024CppProxy_native_1size(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->size();
        return ::djinni::release(::djinni::I64::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1pushInt(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->pushInt(::djinni::I32::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1pushLong(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->pushLong(::djinni::I64::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1pushString(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->pushString(::djinni::String::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1pushDouble(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jdouble j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->pushDouble(::djinni::F64::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1pushData(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jbyteArray j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->pushData(::djinni::Binary::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1pushBoolean(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jboolean j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->pushBoolean(::djinni::Bool::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1pushObject(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->pushObject(::djinni_generated::DynamicObject::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1pushArray(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_value)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->pushArray(::djinni_generated::DynamicArray::toCpp(jniEnv, j_value));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_DynamicArray_00024CppProxy_native_1getString(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getString(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1getInt(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getInt(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni::I32>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1getLong(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getLong(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni::I64>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1getDouble(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getDouble(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni::F64>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_DynamicArray_00024CppProxy_native_1getData(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getData(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni::Binary>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1getBoolean(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getBoolean(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni::Bool>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1getObject(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getObject(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni_generated::DynamicObject>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1getArray(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getArray(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni_generated::DynamicArray>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1concat(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_array)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->concat(::djinni_generated::DynamicArray::toCpp(jniEnv, j_array));
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_00024CppProxy_native_1getType(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->getType(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni_generated::DynamicType>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_DynamicArray_00024CppProxy_native_1remove(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jlong j_index)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->remove(::djinni::I64::toCpp(jniEnv, j_index));
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_DynamicArray_00024CppProxy_native_1dump(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->dump();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_DynamicArray_00024CppProxy_native_1serialize(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->serialize();
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_DynamicArray_00024CppProxy_native_1isReadOnly(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::DynamicArray>(nativeRef);
        auto r = ref->isReadOnly();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_newInstance(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ledger::core::api::DynamicArray::newInstance();
        return ::djinni::release(::djinni_generated::DynamicArray::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_DynamicArray_load(JNIEnv* jniEnv, jobject /*this*/, jbyteArray j_serialized)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::ledger::core::api::DynamicArray::load(::djinni::Binary::toCpp(jniEnv, j_serialized));
        return ::djinni::release(::djinni::Optional<std::experimental::optional, ::djinni_generated::DynamicArray>::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
