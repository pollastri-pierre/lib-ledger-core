// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from thread_dispatcher.djinni

#ifndef DJINNI_GENERATED_LOCK_HPP_JNI_
#define DJINNI_GENERATED_LOCK_HPP_JNI_

#include "../../api/Lock.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class Lock final : ::djinni::JniInterface<::ledger::core::api::Lock, Lock> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::Lock>;
    using CppOptType = std::shared_ptr<::ledger::core::api::Lock>;
    using JniType = jobject;

    using Boxed = Lock;

    ~Lock();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<Lock>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<Lock>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    Lock();
    friend ::djinni::JniClass<Lock>;
    friend ::djinni::JniInterface<::ledger::core::api::Lock, Lock>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::Lock
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void lock() override;
        bool tryLock() override;
        void unlock() override;

    private:
        friend ::djinni::JniInterface<::ledger::core::api::Lock, ::djinni_generated::Lock>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/Lock") };
    const jmethodID method_lock { ::djinni::jniGetMethodID(clazz.get(), "lock", "()V") };
    const jmethodID method_tryLock { ::djinni::jniGetMethodID(clazz.get(), "tryLock", "()Z") };
    const jmethodID method_unlock { ::djinni::jniGetMethodID(clazz.get(), "unlock", "()V") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_LOCK_HPP_JNI_
