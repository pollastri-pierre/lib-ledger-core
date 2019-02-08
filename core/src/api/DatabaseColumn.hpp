// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from database.djinni

#ifndef DJINNI_GENERATED_DATABASECOLUMN_HPP
#define DJINNI_GENERATED_DATABASECOLUMN_HPP

#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER) && _MSC_VER <= 1900
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

enum class DatabaseValueType;

/** An object holding metadata information about a single SQL column (type, name...). */
class DatabaseColumn {
public:
    virtual ~DatabaseColumn() {}

    /**
     * Get the type of the underlying SQL value.
     * @return The type of th
     */
    virtual DatabaseValueType getType() = 0;

    virtual std::string getName() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_DATABASECOLUMN_HPP
