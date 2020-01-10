// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from errors.djinni

#ifndef DJINNI_GENERATED_ERROR_HPP_JNI_
#define DJINNI_GENERATED_ERROR_HPP_JNI_

#include "../../api/Error.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class Error final {
public:
    using CppType = ::ledger::core::api::Error;
    using JniType = jobject;

    using Boxed = Error;

    ~Error();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    Error();
    friend ::djinni::JniClass<Error>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/Error") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Lco/ledger/core/ErrorCode;Ljava/lang/String;)V") };
    const jfieldID field_code { ::djinni::jniGetFieldID(clazz.get(), "code", "Lco/ledger/core/ErrorCode;") };
    const jfieldID field_message { ::djinni::jniGetFieldID(clazz.get(), "message", "Ljava/lang/String;") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_ERROR_HPP_JNI_
