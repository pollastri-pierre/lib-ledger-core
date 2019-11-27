// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#include "CosmosLikeMsgDelegate.hpp"  // my header
#include "CosmosLikeAmount.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

CosmosLikeMsgDelegate::CosmosLikeMsgDelegate() = default;

CosmosLikeMsgDelegate::~CosmosLikeMsgDelegate() = default;

auto CosmosLikeMsgDelegate::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<CosmosLikeMsgDelegate>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.delegatorAddress)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.validatorAddress)),
                                                           ::djinni::get(::djinni_generated::CosmosLikeAmount::fromCpp(jniEnv, c.amount)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto CosmosLikeMsgDelegate::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 4);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<CosmosLikeMsgDelegate>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_delegatorAddress)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_validatorAddress)),
            ::djinni_generated::CosmosLikeAmount::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_amount))};
}

}  // namespace djinni_generated