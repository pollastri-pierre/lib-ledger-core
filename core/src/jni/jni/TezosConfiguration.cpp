// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from tezos_like_wallet.djinni

#include "TezosConfiguration.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

TezosConfiguration::TezosConfiguration() : ::djinni::JniInterface<::ledger::core::api::TezosConfiguration, TezosConfiguration>("co/ledger/core/TezosConfiguration$CppProxy") {}

TezosConfiguration::~TezosConfiguration() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_TezosConfiguration_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::TezosConfiguration>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
