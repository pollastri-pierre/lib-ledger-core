// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from stellar_like_wallet.djinni

#ifndef DJINNI_GENERATED_STELLARLIKEWALLET_HPP_JNI_
#define DJINNI_GENERATED_STELLARLIKEWALLET_HPP_JNI_

#include "../../api/StellarLikeWallet.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class StellarLikeWallet final : ::djinni::JniInterface<::ledger::core::api::StellarLikeWallet, StellarLikeWallet> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::StellarLikeWallet>;
    using CppOptType = std::shared_ptr<::ledger::core::api::StellarLikeWallet>;
    using JniType = jobject;

    using Boxed = StellarLikeWallet;

    ~StellarLikeWallet();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<StellarLikeWallet>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<StellarLikeWallet>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    StellarLikeWallet();
    friend ::djinni::JniClass<StellarLikeWallet>;
    friend ::djinni::JniInterface<::ledger::core::api::StellarLikeWallet, StellarLikeWallet>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_STELLARLIKEWALLET_HPP_JNI_