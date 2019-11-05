/*
 *
 * CosmosLikeTransactionApi
 *
 * Created by El Khalil Bellakrid on  14/06/2019.
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

#include "CosmosLikeMessage.h"

#include <algorithm>
#include <functional>

#include <api/ErrorCode.hpp>
#include <collections/DynamicArray.hpp>

namespace ledger {
	namespace core {

		namespace {
			constexpr auto kMsgSend = "cosmos-sdk/MsgSend";
			constexpr auto kMsgDelegate = "cosmos-sdk/MsgDelegate";
			constexpr auto kMsgUndelegate = "cosmos-sdk/MsgUndelegate";
			constexpr auto kMsgRedelegate = "cosmos-sdk/MsgBeginRedelegate";
			constexpr auto kMsgSubmitProposal = "cosmos-sdk/MsgSubmitProposal";
			constexpr auto kMsgVote = "cosmos-sdk/MsgVote";
			constexpr auto kMsgDeposit = "cosmos-sdk/MsgDeposit";
			constexpr auto kMsgWithdrawDelegationReward = "cosmos-sdk/MsgWithdrawDelegationReward";
			
			constexpr auto kType = "type";
			constexpr auto kFromAddress = "from_address";
			constexpr auto kToAddress = "to_address";
			constexpr auto kAmount = "amount";
			constexpr auto kDenom = "denom";

			inline auto containsKeys(std::shared_ptr<api::DynamicObject> object) {
				return [=](auto const& key) {
					return object->contains(key);
				};
			}
		}

		CosmosLikeMessage::CosmosLikeMessage(const std::shared_ptr<DynamicObject> &content) : _content(content) {

		}

		api::CosmosLikeMsgType CosmosLikeMessage::getMessageType() {
			auto msgType = _content->get<std::string>(kType).value_or("");

			if (msgType == kMsgSend) {
				return api::CosmosLikeMsgType::MSGSEND;
			} else if (msgType == kMsgDelegate) {
				return api::CosmosLikeMsgType::MSGDELEGATE;
			} else if (msgType == kMsgUndelegate) {
				return api::CosmosLikeMsgType::MSGDELEGATE;
			} else if (msgType == kMsgRedelegate) {
				return api::CosmosLikeMsgType::MSGREDELEGATE;
			} else if (msgType == kMsgSubmitProposal) {
				return api::CosmosLikeMsgType::MSGSUBMITPROPOSAL;
			} else if (msgType == kMsgVote) {
				return api::CosmosLikeMsgType::MSGVOTE;
			} else if (msgType == kMsgDeposit) {
				return api::CosmosLikeMsgType::MSGDEPOSIT;
			} else if (msgType == kMsgWithdrawDelegationReward) {
				return api::CosmosLikeMsgType::MSGWITHDRAWDELEGATIONREWARD;
			}  else {
				return api::CosmosLikeMsgType::UNKNOWN;
			}
		}

		std::shared_ptr<api::CosmosLikeMessage> api::CosmosLikeMessage::wrapMsgSend(const api::CosmosLikeMsgSend & msg) {
			auto object = std::make_shared<::ledger::core::DynamicObject>();

			object->putString(kType, kMsgSend);
			object->putString(kFromAddress, msg.fromAddress);
			object->putString(kToAddress, msg.toAddress);
			
			{
				auto amounts = std::make_shared<::ledger::core::DynamicArray>();

				std::for_each(std::begin(msg.amounts), std::end(msg.amounts), [&amounts](auto const& x) {
					auto amount = std::make_shared<::ledger::core::DynamicObject>();

					amount->putString(kAmount, x.amount);
					amount->putString(kDenom, x.denom);

					amounts->pushObject(amount);
				});

				object->putArray(kAmount, amounts);
			}

			return std::make_shared<::ledger::core::CosmosLikeMessage>(object);
		}

    	api::CosmosLikeMsgSend api::CosmosLikeMessage::unwrapMsgSend(const std::shared_ptr<CosmosLikeMessage> & msg) {
			static const char* keys[] = { kFromAddress, kToAddress, kAmount };

			auto implMsg = std::dynamic_pointer_cast<::ledger::core::CosmosLikeMessage>(msg);

			if (!std::all_of(std::begin(keys), std::end(keys), containsKeys(implMsg->_content))) {
				throw Exception(api::ErrorCode::RUNTIME_ERROR, "unable to unwrap MsgSend");
			}

			auto underlyingMsg = api::CosmosLikeMsgSend{};

			underlyingMsg.fromAddress = implMsg->_content->getString(kFromAddress).value();
			underlyingMsg.toAddress = implMsg->_content->getString(kToAddress).value();

			{
				static const char* amountKeys[] = { kAmount, kDenom };

				auto amounts = std::dynamic_pointer_cast<::ledger::core::DynamicArray>(
					implMsg->_content->getArray(kAmount));

				for (auto size = amounts->size(), i = decltype(size){0}; i < size; ++i) {
					auto amount = amounts->getObject(i);

					if (!std::all_of(std::begin(amountKeys), std::end(amountKeys), containsKeys(amount))) {
						throw Exception(api::ErrorCode::RUNTIME_ERROR, "unable to unwrap MsgSend: bad amount fields");
					}

					underlyingMsg.amounts.push_back(CosmosLikeAmount{
						amount->getString(kAmount).value(),
						amount->getString(kDenom).value()
					});
				}
			}

			return underlyingMsg;
		}
	}
}
