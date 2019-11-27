/*
 *
 * RIppleLikeTransactionDatabaseHelper
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


#include "CosmosLikeTransactionDatabaseHelper.h"
#include <database/soci-option.h>
#include <database/soci-date.h>
#include <database/soci-number.h>
#include <crypto/SHA256.hpp>
#include <wallet/common/database/BlockDatabaseHelper.h>
#include <wallet/currencies.hpp>

using namespace soci;

namespace ledger {
    namespace core {

        bool CosmosLikeTransactionDatabaseHelper::getTransactionByHash(soci::session &sql,
                                                                       const std::string &hash,
                                                                       cosmos::Transaction &tx) {

            rowset<row> rows = (sql.prepare << "SELECT tx.transaction_uid, tx.hash, tx.time, "
                    "tx.gas_price, tx.gas_limit, tx.memo, tx.gas_used, "
                    "block.height, block.hash, block.time, block.currency_name, "
                    "msg.message_type, msg.from_address, msg.to_address, msg.amount_value, msg.fees "
                    "FROM cosmos_transactions AS tx "
                    "LEFT JOIN blocks AS block ON tx.block_uid = block.uid "
                    "LEFT JOIN cosmos_messages AS msg ON msg.transaction_uid = tx.transaction_uid "
                    "WHERE tx.hash = :hash "
                    "ORDER BY msg.msg_index ASC", use(hash));

            for (auto &row : rows) {
                inflateTransaction(sql, row, tx);
                return true;
            }

            return false;
        }

        bool CosmosLikeTransactionDatabaseHelper::inflateTransaction(soci::session &sql,
                                                                     const soci::row &row,
                                                                     cosmos::Transaction &tx) {
//            tx.uid = row.get<std::string>(0);
//            tx.hash = row.get<std::string>(1);
//            tx.timestamp = row.get<std::chrono::system_clock::time_point>(3);
//            tx.gasPrice = BigInt(row.get<std::string>(4));
//            tx.gasLimit = BigInt(row.get<std::string>(5));
//            tx.memo = row.get<std::string>(6);
//            tx.gasUsed = BigInt(row.get<std::string>(7));
//             //TODO: gas limit and price
//            if (row.get_indicator(7) != i_null) {
//                CosmosLikeBlockchainExplorer::Block block;
//                block.height = get_number<uint64_t>(row, 8);
//                block.hash = row.get<std::string>(9);
//                block.time = row.get<std::chrono::system_clock::time_point>(10);
//                block.currencyName = row.get<std::string>(11);
//                tx.block = block;
//            }
//
//            CosmosLikeBlockchainExplorerMessage msg;
//            msg.type = row.get<std::string>(12);
//            msg.sender = row.get<std::string>(13);
//            msg.recipient = row.get<std::string>(14);
//            msg.amount = row.get<std::string>(15);
//            msg.fees = row.get<std::string>(16);
//            tx.messages.push_back(msg);
            return true;
        }

        bool CosmosLikeTransactionDatabaseHelper::transactionExists(soci::session &sql,
                                                                    const std::string &cosmosTxUid) {
            int32_t count = 0;
            sql << "SELECT COUNT(*) FROM cosmos_transactions WHERE transaction_uid = :cosmosTxUid", use(cosmosTxUid), into(
                    count);
            return count == 1;
        }

        std::string CosmosLikeTransactionDatabaseHelper::createCosmosTransactionUid(const std::string &accountUid,
                                                                                    const std::string &txHash) {
            auto result = SHA256::stringToHexHash(fmt::format("uid:{}+{}", accountUid, txHash));
            return result;
        }

        std::string CosmosLikeTransactionDatabaseHelper::createCosmosMessageUid(const std::string &txUid,
                                                                                uint64_t msgIndex) {
            auto result = SHA256::stringToHexHash(fmt::format("uid:{}+{}", txUid, msgIndex));
            return result;
        }

        std::string CosmosLikeTransactionDatabaseHelper::putTransaction(soci::session &sql,
                                                                        const std::string &accountUid,
                                                                        const cosmos::Transaction &tx) {
//            auto blockUid = tx.block.map<std::string>([](const CosmosLikeBlockchainExplorer::Block &block) {
//                return block.getUid();
//            });
//
//            auto cosmosTxUid = createCosmosTransactionUid(accountUid, tx.hash);
//
//            if (transactionExists(sql, cosmosTxUid)) {
//                // UPDATE (we only update block information)
//                if (tx.block.nonEmpty()) {
//                    sql << "UPDATE cosmos_transactions SET block_uid = :uid WHERE hash = :tx_hash",
//                            use(blockUid), use(tx.hash);
//                }
//                return cosmosTxUid;
//            } else {
//                // Insert
//                if (tx.block.nonEmpty()) {
//                    BlockDatabaseHelper::putBlock(sql, tx.block.getValue());
//                }
//
//                auto gasPrice = tx.gasPrice.toString();
//                auto gasLimit = tx.gasLimit.toString();
//                auto gasUsed = tx.gasUsed->toString();
//                sql << "INSERT INTO cosmos_transactions VALUES(:tx_uid, :hash, :block_uid, :time, :gas_price, :gas_limit, :memo, :gas_used)",
//                        use(cosmosTxUid),
//                        use(tx.hash),
//                        use(blockUid),
//                        use(tx.timestamp),
//                        use(gasPrice),
//                        use(gasPrice),
//                        use(tx.memo),
//                        use(gasUsed);
//
//                std::string type;
//                std::string sender;
//                std::string recipient;
//                BigInt amount;
//                BigInt fees;
//
//                int msgIndex = 0;
//                std::list<CosmosLikeBlockchainExplorerMessage>::iterator it;
//
//                std::for_each(tx.messages.begin(), tx.messages.end(), [&](const CosmosLikeBlockchainExplorerMessage &msg) {
//                    auto amount = msg.amount.toString();
//                    auto fees = msg.fees.toString();
//
//                    // TODO COSMOS Right hardcoded to use onely one msg log
//                    auto uid = createCosmosMessageUid(cosmosTxUid, msgIndex);
//                    auto isSuccess = tx.logs.front().success ? 1 : 0;
//                    auto logMessage = tx.logs.front().log;
//                    sql << "INSERT INTO cosmos_messages VALUES (:uid, :tx_uid, :message_type, :from_address, :to_address, :amount_value, :fees, :log, :success, :msg_index)",
//                            use(uid),
//                            use(cosmosTxUid),
//                            use(msg.type),
//                            use(msg.sender),
//                            use(msg.recipient),
//                            use(amount),
//                            use(fees),
//                            use(logMessage),
//                            use(isSuccess),
//                            use(msgIndex);
//                    ++msgIndex;
//                });
//                for (it = tx.messages.begin(); it != tx.messages.end(); ++it) {
//                    auto amount = it->amount.toString();
//                    auto fees = it->fees.toString();
//                    sql << "INSERT INTO cosmos_messages VALUES (:tx_uid, :message_type, :from_address, :to_address, :amount_value, :fees, :log, :success, :msg_index)",
//                            use(cosmosTxUid),
//                            use(it->type),
//                            use(it->sender),
//                            use(it->recipient),
//                            use(amount),
//                            use(fees),
//                            use(msgIndex);
//
//                    ++msgIndex;
//                }

                //return cosmosTxUid;
            //}
        }
    }
}
