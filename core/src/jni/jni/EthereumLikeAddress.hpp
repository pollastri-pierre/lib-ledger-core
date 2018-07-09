// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#ifndef DJINNI_GENERATED_ETHEREUMLIKEADDRESS_HPP_JNI_
#define DJINNI_GENERATED_ETHEREUMLIKEADDRESS_HPP_JNI_

#include "../../api/EthereumLikeAddress.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class EthereumLikeAddress final : ::djinni::JniInterface<::ledger::core::api::EthereumLikeAddress, EthereumLikeAddress> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::EthereumLikeAddress>;
    using CppOptType = std::shared_ptr<::ledger::core::api::EthereumLikeAddress>;
    using JniType = jobject;

    using Boxed = EthereumLikeAddress;

    ~EthereumLikeAddress();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<EthereumLikeAddress>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<EthereumLikeAddress>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    EthereumLikeAddress();
    friend ::djinni::JniClass<EthereumLikeAddress>;
    friend ::djinni::JniInterface<::ledger::core::api::EthereumLikeAddress, EthereumLikeAddress>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_ETHEREUMLIKEADDRESS_HPP_JNI_
