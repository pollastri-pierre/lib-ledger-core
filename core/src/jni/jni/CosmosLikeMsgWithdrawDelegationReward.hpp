// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEMSGWITHDRAWDELEGATIONREWARD_HPP_JNI_
#define DJINNI_GENERATED_COSMOSLIKEMSGWITHDRAWDELEGATIONREWARD_HPP_JNI_

#include "../../api/CosmosLikeMsgWithdrawDelegationReward.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class CosmosLikeMsgWithdrawDelegationReward final {
public:
    using CppType = ::ledger::core::api::CosmosLikeMsgWithdrawDelegationReward;
    using JniType = jobject;

    using Boxed = CosmosLikeMsgWithdrawDelegationReward;

    ~CosmosLikeMsgWithdrawDelegationReward();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    CosmosLikeMsgWithdrawDelegationReward();
    friend ::djinni::JniClass<CosmosLikeMsgWithdrawDelegationReward>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/CosmosLikeMsgWithdrawDelegationReward") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;Ljava/lang/String;)V") };
    const jfieldID field_delegatorAddress { ::djinni::jniGetFieldID(clazz.get(), "delegatorAddress", "Ljava/lang/String;") };
    const jfieldID field_validatorAddress { ::djinni::jniGetFieldID(clazz.get(), "validatorAddress", "Ljava/lang/String;") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_COSMOSLIKEMSGWITHDRAWDELEGATIONREWARD_HPP_JNI_