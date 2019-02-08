// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from configuration.djinni

#ifndef DJINNI_GENERATED_SYNCHRONIZATIONENGINES_HPP
#define DJINNI_GENERATED_SYNCHRONIZATIONENGINES_HPP

#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER) && _MSC_VER <= 1900
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

/** Available synchronization mechanisms. */
class LIBCORE_EXPORT SynchronizationEngines {
public:
    virtual ~SynchronizationEngines() {}

    /** Synchronize via blockchain explorers. */
    static std::string const BLOCKCHAIN_EXPLORER_SYNCHRONIZATION;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_SYNCHRONIZATIONENGINES_HPP
