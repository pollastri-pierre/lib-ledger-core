// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from cosmos_like_wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKETRANSACTION_HPP_JNI_
#define DJINNI_GENERATED_COSMOSLIKETRANSACTION_HPP_JNI_

#include "../../api/CosmosLikeTransaction.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class CosmosLikeTransaction final : ::djinni::JniInterface<::ledger::core::api::CosmosLikeTransaction, CosmosLikeTransaction> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::CosmosLikeTransaction>;
    using CppOptType = std::shared_ptr<::ledger::core::api::CosmosLikeTransaction>;
    using JniType = jobject;

    using Boxed = CosmosLikeTransaction;

    ~CosmosLikeTransaction();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<CosmosLikeTransaction>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<CosmosLikeTransaction>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    CosmosLikeTransaction();
    friend ::djinni::JniClass<CosmosLikeTransaction>;
    friend ::djinni::JniInterface<::ledger::core::api::CosmosLikeTransaction, CosmosLikeTransaction>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_COSMOSLIKETRANSACTION_HPP_JNI_