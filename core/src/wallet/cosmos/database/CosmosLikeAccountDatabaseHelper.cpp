/*
 *
 * CosmosLikeAccountDatabaseHelper
 *
 * Created by El Khalil Bellakrid on 06/01/2019.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */


#include "CosmosLikeAccountDatabaseHelper.h"
#include <wallet/common/database/AccountDatabaseHelper.h>

using namespace soci;

namespace ledger {
    namespace core {
        void CosmosLikeAccountDatabaseHelper::createAccount(soci::session &sql,
                                                            const std::string walletUid, int32_t index,
                                                            const std::string &address) {
            auto uid = AccountDatabaseHelper::createAccountUid(walletUid, index);
            sql << "INSERT INTO cosmos_accounts VALUES(:uid, :wallet_uid, :idx, :address)", use(uid), use(
                    walletUid), use(index), use(address);
        }

        bool CosmosLikeAccountDatabaseHelper::queryAccount(soci::session &sql,
                                                           const std::string &accountUid,
                                                           CosmosLikeAccountDatabaseEntry &entry) {
            rowset<row> rows = (sql.prepare << "SELECT idx, address FROM cosmos_accounts WHERE uid = :uid", use(
                    accountUid));
            for (auto &row : rows) {
                entry.index = row.get<int32_t>(0);
                entry.address = row.get<std::string>(1);
                return true;
            }
            return false;
        }

        std::size_t
        CosmosLikeAccountDatabaseHelper::queryOperations(soci::session &sql,
                                                         const std::string &accountUid,
                                                         std::vector<Operation> &operations,
                                                         std::function<bool(const std::string &address)> filter) {
            throw Exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Missing Implementation");

            /*
            std::string query = "";
            rowset<row> rows = (sql.prepare << query, use(accountUid));

            auto filterList = [&](const std::vector<std::string> &list) -> bool {
                for (auto &elem : list) {
                    if (filter(elem)) {
                        return true;
                    }
                }
                return false;
            };

            std::size_t c = 0;
            for (auto &row : rows) {
                auto type = api::from_string<api::OperationType>(row.get<std::string>(2));
                auto senders = strings::split(row.get<std::string>(4), ",");
                auto recipients = strings::split(row.get<std::string>(5), ",");
                if ((type == api::OperationType::SEND && row.get_indicator(4) != i_null && filterList(senders)) ||
                    (type == api::OperationType::RECEIVE && row.get_indicator(5) != i_null && filterList(recipients))) {
                    operations.resize(operations.size() + 1);
                    auto &operation = operations[operations.size() - 1];
                    operation.amount = BigInt::fromHex(row.get<std::string>(0));
                    operation.fees = BigInt::fromHex(row.get<std::string>(1));
                    operation.type = type;
                    operation.date = DateUtils::fromJSON(row.get<std::string>(3));
                    operation.uid = row.get<std::string>(6);
                    c += 1;
                }
            }

            return c;
            */
        }

    }
}