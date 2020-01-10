// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from database.djinni

#ifndef DJINNI_GENERATED_DATABASECOLUMN_HPP_JNI_
#define DJINNI_GENERATED_DATABASECOLUMN_HPP_JNI_

#include "../../api/DatabaseColumn.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class DatabaseColumn final : ::djinni::JniInterface<::ledger::core::api::DatabaseColumn, DatabaseColumn> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::DatabaseColumn>;
    using CppOptType = std::shared_ptr<::ledger::core::api::DatabaseColumn>;
    using JniType = jobject;

    using Boxed = DatabaseColumn;

    ~DatabaseColumn();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<DatabaseColumn>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<DatabaseColumn>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    DatabaseColumn();
    friend ::djinni::JniClass<DatabaseColumn>;
    friend ::djinni::JniInterface<::ledger::core::api::DatabaseColumn, DatabaseColumn>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::DatabaseColumn
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        ::ledger::core::api::DatabaseValueType getType() override;
        std::string getName() override;

    private:
        friend ::djinni::JniInterface<::ledger::core::api::DatabaseColumn, ::djinni_generated::DatabaseColumn>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/DatabaseColumn") };
    const jmethodID method_getType { ::djinni::jniGetMethodID(clazz.get(), "getType", "()Lco/ledger/core/DatabaseValueType;") };
    const jmethodID method_getName { ::djinni::jniGetMethodID(clazz.get(), "getName", "()Ljava/lang/String;") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_DATABASECOLUMN_HPP_JNI_
