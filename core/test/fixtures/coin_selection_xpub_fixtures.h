// This file was GENERATED by command:
//     generate_bitcoin_fixtures.py
// DO NOT EDIT BY HAND!!!
#ifndef LEDGER_FIXTURES_COIN_SELECTION_XPUB
#define LEDGER_FIXTURES_COIN_SELECTION_XPUB
#include <gtest/gtest.h>
#include <async/QtThreadDispatcher.hpp>
#include <src/database/DatabaseSessionPool.hpp>
#include <NativePathResolver.hpp>
#include <unordered_set>
#include <src/wallet/pool/WalletPool.hpp>
#include <CoutLogPrinter.hpp>
#include <src/api/DynamicObject.hpp>
#include <wallet/common/CurrencyBuilder.hpp>
#include <wallet/bitcoin/BitcoinLikeWallet.hpp>
#include <wallet/bitcoin/database/BitcoinLikeWalletDatabase.h>
#include <wallet/bitcoin/database/BitcoinLikeTransactionDatabaseHelper.h>
#include <wallet/common/database/AccountDatabaseHelper.h>
#include <wallet/pool/database/PoolDatabaseHelper.hpp>
#include <utils/JSONUtils.h>
#include <wallet/bitcoin/explorers/api/TransactionParser.hpp>
#include <async/async_wait.h>
#include <wallet/bitcoin/BitcoinLikeAccount.hpp>
#include <api/BitcoinLikeOperation.hpp>
#include <api/BitcoinLikeTransaction.hpp>
#include <api/BitcoinLikeInput.hpp>
#include <api/BitcoinLikeOutput.hpp>
#include <api/BigInt.hpp>
#include <CppHttpLibClient.hpp>
#include <events/LambdaEventReceiver.hpp>
#include <soci.h>
#include <api/Account.hpp>
#include <api/BitcoinLikeAccount.hpp>

namespace ledger {
	namespace testing {
		namespace coin_selection_xpub {
			extern core::api::ExtendedKeyAccountCreationInfo XPUB_INFO;
			extern const std::string TX_1;
			extern const std::string TX_2;
			extern const std::string TX_3;
			extern const std::string TX_4;
			extern const std::string TX_5;

			std::shared_ptr<core::BitcoinLikeAccount> inflate(const std::shared_ptr<core::WalletPool>& pool, const std::shared_ptr<core::AbstractWallet>& wallet);
		}
	}
}

#endif // LEDGER_FIXTURES_COIN_SELECTION_XPUB
