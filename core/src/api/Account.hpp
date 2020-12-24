// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#ifndef DJINNI_GENERATED_ACCOUNT_HPP
#define DJINNI_GENERATED_ACCOUNT_HPP

#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class AddressListCallback;
class AlgorandAccount;
class AmountCallback;
class AmountListCallback;
class BitcoinLikeAccount;
class BlockCallback;
class CosmosLikeAccount;
class ErrorCodeCallback;
class EthereumLikeAccount;
class EventBus;
class Keychain;
class Logger;
class OperationQuery;
class Preferences;
class RippleLikeAccount;
class StellarLikeAccount;
class TezosLikeAccount;
enum class TimePeriod;
enum class WalletType;

/** Class representing an account. */
class LIBCORE_EXPORT Account {
public:
    virtual ~Account() {}

    /**
     * Key of the synchronization duration time in the synchronize event payload.
     * The value is stored in a int64 time expressed in miliseconds.
     */
    static std::string const EV_SYNC_DURATION_MS;

    /**
     * Indicates the last block height fetch during synchronization
     * The value is stored as a int32
     */
    static std::string const EV_SYNC_LAST_BLOCK_HEIGHT;

    /**
     * Indicates the number of new operations during the synchronization
     * The value is stored as a int32
     */
    static std::string const EV_SYNC_NEW_OPERATIONS;

    /**
     * Indicates the first valid block height before the reorganization during the synchronization
     * The value is stored as a int32
     */
    static std::string const EV_SYNC_REORG_BLOCK_HEIGHT;

    /** Key of the synchronization error code. The code is a stringified version of the value in the ErrorCode enum. */
    static std::string const EV_SYNC_ERROR_CODE;

    static std::string const EV_SYNC_ERROR_CODE_INT;

    /** Key of the synchronization error message. The message is stored as a string. */
    static std::string const EV_SYNC_ERROR_MESSAGE;

    /**TODO */
    static std::string const EV_NEW_BLOCK_CURRENCY_NAME;

    static std::string const EV_NEW_BLOCK_HASH;

    static std::string const EV_NEW_BLOCK_HEIGHT;

    /**TODO */
    static std::string const EV_NEW_OP_WALLET_NAME;

    static std::string const EV_NEW_OP_ACCOUNT_INDEX;

    static std::string const EV_NEW_OP_UID;

    static std::string const EV_DELETED_OP_UID;

    /**
     * Returned flag when a transaction is put in DB
     * Some of those are unrelevant for specific coins
     * but for the sake of generic mechanism we put all those
     * flags together
     */
    static int32_t const FLAG_TRANSACTION_IGNORED;

    static int32_t const FLAG_NEW_TRANSACTION;

    static int32_t const FLAG_TRANSACTION_UPDATED;

    static int32_t const FLAG_TRANSACTION_ON_PREVIOUSLY_EMPTY_ADDRESS;

    static int32_t const FLAG_TRANSACTION_ON_USED_ADDRESS;

    static int32_t const FLAG_TRANSACTION_CREATED_SENDING_OPERATION;

    static int32_t const FLAG_TRANSACTION_CREATED_RECEPTION_OPERATION;

    static int32_t const FLAG_TRANSACTION_CREATED_EXTERNAL_OPERATION;

    /**
     * Get index of account in user's wallet
     * 32-bit integer
     */
    virtual int32_t getIndex() = 0;

    /** Get the list of all operations. */
    virtual std::shared_ptr<OperationQuery> queryOperations() = 0;

    /**
     * Get balance of account.
     * @param callback, if getBalacne, Callback returning an Amount object which represents account's balance
     */
    virtual void getBalance(const std::shared_ptr<AmountCallback> & callback) = 0;

    /**
     * Get balance of account at a precise interval with a certain granularity.
     * @param start, lower bound of search range
     * @param end, upper bound of search range
     * @param precision, granularity at which we want results
     * @param callback, ListCallback returning a list of Amount object which represents account's balance
     */
    virtual void getBalanceHistory(const std::string & start, const std::string & end, TimePeriod period, const std::shared_ptr<AmountListCallback> & callback) = 0;

    /**
     * Get synchronization status of account.
     * @return bool
     */
    virtual bool isSynchronizing() = 0;

    /**
     * Start synchronization of account.
     * @return EventBus, handler will be notified of synchronization outcome
     */
    virtual std::shared_ptr<EventBus> synchronize() = 0;

    /**
     * Return account's preferences.
     * @return Preferences object
     */
    virtual std::shared_ptr<Preferences> getPreferences() = 0;

    /**
     * Return account's logger which provides all needed (e.g. database) logs.
     * @return Logger Object
     */
    virtual std::shared_ptr<Logger> getLogger() = 0;

    /**
     * Return operation for a specific operation.
     * @param uid, string of operation id
     */
    virtual std::shared_ptr<Preferences> getOperationPreferences(const std::string & uid) = 0;

    /**
     * Turn the account into an Bitcoin one, allowing operations to be performed on the Bitcoin
     * network.
     */
    virtual std::shared_ptr<BitcoinLikeAccount> asBitcoinLikeAccount() = 0;

    /**
     * Turn the account into an Cosmos one, allowing operations to be performed on the Cosmos
     * network.
     */
    virtual std::shared_ptr<CosmosLikeAccount> asCosmosLikeAccount() = 0;

    /**
     * Turn the account into an Ethereum one, allowing operations to be performrd on the Ethereum
     * network.
     */
    virtual std::shared_ptr<EthereumLikeAccount> asEthereumLikeAccount() = 0;

    /** Turn the account into a Ripple one, allowing operations to be performed on the Ripple network. */
    virtual std::shared_ptr<RippleLikeAccount> asRippleLikeAccount() = 0;

    /** Turn the account into a Tezos one, allowing operations to be performed on the Tezos network. */
    virtual std::shared_ptr<TezosLikeAccount> asTezosLikeAccount() = 0;

    /** Turn the account into an Algorand one, allowing operations to be performed on the Algorand network. */
    virtual std::shared_ptr<AlgorandAccount> asAlgorandAccount() = 0;

    /**
     * Turn the account into a Stellar one, allowing operations to be performerd on the Stellar
     * network.
     */
    virtual std::shared_ptr<StellarLikeAccount> asStellarLikeAccount() = 0;

    /**
     * Check if account is a Bitcoin one.
     * @return bool
     */
    virtual bool isInstanceOfBitcoinLikeAccount() = 0;

    /**
     * Check if account is a Cosmos one.
     * @return bool
     */
    virtual bool isInstanceOfCosmosLikeAccount() = 0;

    /**
     * Check if account is an Ethereum one.
     * @return bool
     */
    virtual bool isInstanceOfEthereumLikeAccount() = 0;

    /**
     * Check if account is a Stellar one.
     * @return bool
     */
    virtual bool isInstanceOfStellarLikeAccount() const = 0;

    /**
     * Check if account is a Ripple one.
     * @return bool
     */
    virtual bool isInstanceOfRippleLikeAccount() = 0;

    /**TODO */
    virtual void getFreshPublicAddresses(const std::shared_ptr<AddressListCallback> & callback) = 0;

    /**
     * Get type of wallet to which account belongs.
     * @return WalletType object
     */
    virtual WalletType getWalletType() = 0;

    /**
     * Get event bus through which account is notified on synchronization status.
     * @return EventBus object
     */
    virtual std::shared_ptr<EventBus> getEventBus() = 0;

    /**
     * Get Last block of blockchain on which account operates.
     * @param callback, Callback returning, if getLastBlock succeeds, a Block object
     */
    virtual void getLastBlock(const std::shared_ptr<BlockCallback> & callback) = 0;

    /** Get the key used to generate the account. */
    virtual std::string getRestoreKey() = 0;

    /**
     * Erase data (in user's DB) relative to wallet since given date.
     * @param date, start date of data deletion
     */
    virtual void eraseDataSince(const std::chrono::system_clock::time_point & date, const std::shared_ptr<ErrorCodeCallback> & callback) = 0;

    /** Access to underlying keychain. */
    virtual std::shared_ptr<Keychain> getAccountKeychain() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_ACCOUNT_HPP
