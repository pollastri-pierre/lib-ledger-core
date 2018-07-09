// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#ifndef DJINNI_GENERATED_ETHEREUMLIKEEXTENDEDPUBLICKEY_HPP_JNI_
#define DJINNI_GENERATED_ETHEREUMLIKEEXTENDEDPUBLICKEY_HPP_JNI_

#include "../../api/EthereumLikeExtendedPublicKey.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class EthereumLikeExtendedPublicKey final : ::djinni::JniInterface<::ledger::core::api::EthereumLikeExtendedPublicKey, EthereumLikeExtendedPublicKey> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::EthereumLikeExtendedPublicKey>;
    using CppOptType = std::shared_ptr<::ledger::core::api::EthereumLikeExtendedPublicKey>;
    using JniType = jobject;

    using Boxed = EthereumLikeExtendedPublicKey;

    ~EthereumLikeExtendedPublicKey();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<EthereumLikeExtendedPublicKey>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<EthereumLikeExtendedPublicKey>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    EthereumLikeExtendedPublicKey();
    friend ::djinni::JniClass<EthereumLikeExtendedPublicKey>;
    friend ::djinni::JniInterface<::ledger::core::api::EthereumLikeExtendedPublicKey, EthereumLikeExtendedPublicKey>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_ETHEREUMLIKEEXTENDEDPUBLICKEY_HPP_JNI_
