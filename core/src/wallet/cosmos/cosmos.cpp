/*
 *
 * cosmos.cpp
 * ledger-core
 *
 * Created by Pierre Pollastri on 03/12/2019.
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

#include "cosmos.h"

namespace ledger {
    namespace core {
        namespace cosmos {

            static const std::string kMsgSendString = "cosmos-sdk/MsgSend";
            static const std::string kMsgDelegateString = "cosmos-sdk/MsgDelegate";
            static const std::string kMsgUndelegateString = "cosmos-sdk/MsgUndelegate";
            static const std::string kMsgRedelegateString = "cosmos-sdk/MsgRedelegate";
            static const std::string kMsgSubmitProposalString = "cosmos-sdk/MsgSubmitProposal";
            static const std::string kMsgVoteString = "cosmos-sdk/MsgVote";
            static const std::string kMsgDepositString = "cosmos-sdk/MsgDeposit";
            static const std::string kMsgWithdrawDelegationRewardString = "cosmos-sdk/MsgWithdrawDelegationReward";

            std::string msgTypeToString(MsgType type) {
                switch (type) {
                    case api::CosmosLikeMsgType::MSGSEND:
                        return kMsgSendString;
                    case api::CosmosLikeMsgType::MSGDELEGATE:
                        return kMsgDelegateString;
                    case api::CosmosLikeMsgType::MSGUNDELEGATE:
                        return kMsgUndelegateString;
                    case api::CosmosLikeMsgType::MSGREDELEGATE:
                        return kMsgRedelegateString;
                    case api::CosmosLikeMsgType::MSGSUBMITPROPOSAL:
                        return kMsgSubmitProposalString;
                    case api::CosmosLikeMsgType::MSGVOTE:
                        return kMsgVoteString;
                    case api::CosmosLikeMsgType::MSGDEPOSIT:
                        return kMsgDepositString;
                    case api::CosmosLikeMsgType::MSGWITHDRAWDELEGATIONREWARD:
                        return kMsgWithdrawDelegationRewardString;
                    case api::CosmosLikeMsgType::UNKNOWN:
                        return "";
                }
            }

            MsgType stringToMsgType(const std::string& string) {
                if (string == kMsgSendString) {
                    return cosmos::MsgType::MSGSEND;
                } else if (string == kMsgDelegateString) {
                    return cosmos::MsgType::MSGDELEGATE;
                } else if (string == kMsgUndelegateString) {
                    return cosmos::MsgType::MSGUNDELEGATE;
                } else if (string == kMsgRedelegateString) {
                    return cosmos::MsgType::MSGREDELEGATE;
                } else if (string == kMsgSubmitProposalString) {
                    return cosmos::MsgType::MSGSUBMITPROPOSAL;
                } else if (string == kMsgVoteString) {
                    return cosmos::MsgType::MSGVOTE;
                } else if (string == kMsgDepositString) {
                    return cosmos::MsgType::MSGDEPOSIT;
                } else if (string == kMsgWithdrawDelegationRewardString) {
                    return cosmos::MsgType::MSGWITHDRAWDELEGATIONREWARD;
                } else {
                    return cosmos::MsgType::UNKNOWN;
                }
            }

        }
    }
}