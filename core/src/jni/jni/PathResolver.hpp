// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from path_resolver.djinni

#ifndef DJINNI_GENERATED_PATHRESOLVER_HPP_JNI_
#define DJINNI_GENERATED_PATHRESOLVER_HPP_JNI_

#include "../../api/PathResolver.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class PathResolver final : ::djinni::JniInterface<::ledger::core::api::PathResolver, PathResolver> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::PathResolver>;
    using CppOptType = std::shared_ptr<::ledger::core::api::PathResolver>;
    using JniType = jobject;

    using Boxed = PathResolver;

    ~PathResolver();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<PathResolver>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<PathResolver>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    PathResolver();
    friend ::djinni::JniClass<PathResolver>;
    friend ::djinni::JniInterface<::ledger::core::api::PathResolver, PathResolver>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::PathResolver
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        std::string resolveDatabasePath(const std::string & path) override;
        std::string resolveLogFilePath(const std::string & path) override;
        std::string resolvePreferencesPath(const std::string & path) override;

    private:
        friend ::djinni::JniInterface<::ledger::core::api::PathResolver, ::djinni_generated::PathResolver>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("PathResolver") };
    const jmethodID method_resolveDatabasePath { ::djinni::jniGetMethodID(clazz.get(), "resolveDatabasePath", "(Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_resolveLogFilePath { ::djinni::jniGetMethodID(clazz.get(), "resolveLogFilePath", "(Ljava/lang/String;)Ljava/lang/String;") };
    const jmethodID method_resolvePreferencesPath { ::djinni::jniGetMethodID(clazz.get(), "resolvePreferencesPath", "(Ljava/lang/String;)Ljava/lang/String;") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_PATHRESOLVER_HPP_JNI_
