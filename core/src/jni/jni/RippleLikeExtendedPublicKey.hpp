// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#ifndef DJINNI_GENERATED_RIPPLELIKEEXTENDEDPUBLICKEY_HPP_JNI_
#define DJINNI_GENERATED_RIPPLELIKEEXTENDEDPUBLICKEY_HPP_JNI_

#include "../../api/RippleLikeExtendedPublicKey.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class RippleLikeExtendedPublicKey final : ::djinni::JniInterface<::ledger::core::api::RippleLikeExtendedPublicKey, RippleLikeExtendedPublicKey> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::RippleLikeExtendedPublicKey>;
    using CppOptType = std::shared_ptr<::ledger::core::api::RippleLikeExtendedPublicKey>;
    using JniType = jobject;

    using Boxed = RippleLikeExtendedPublicKey;

    ~RippleLikeExtendedPublicKey();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<RippleLikeExtendedPublicKey>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<RippleLikeExtendedPublicKey>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    RippleLikeExtendedPublicKey();
    friend ::djinni::JniClass<RippleLikeExtendedPublicKey>;
    friend ::djinni::JniInterface<::ledger::core::api::RippleLikeExtendedPublicKey, RippleLikeExtendedPublicKey>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_RIPPLELIKEEXTENDEDPUBLICKEY_HPP_JNI_
