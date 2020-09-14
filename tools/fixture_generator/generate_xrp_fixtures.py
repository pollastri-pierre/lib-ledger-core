#!/usr/bin/env python3

import sys
import requests
import json
import datetime
import dateutil.parser
import time

if len(sys.argv) < 4:
    print("Should have at least two params <name> <address> <pubKey> <chainCode>")
    sys.exit(-1)

path = "../../core/test/fixtures/"

arguments = sys.argv[1:]
namespace = str(arguments[0])
address = (arguments[1])
pubKey = (arguments[2])
chainCode = (arguments[3])

def getHashs(txsHash):
  syncUrl = "https://s2.ripple.com:51234"
  #Get txs related to address
  params = "{\"method\":\"account_tx\",\"params\":[{\"account\":\"" + address + "\"}]}"
  call = requests.post(syncUrl, params)
  bytes = call.content
  text = bytes.decode('utf8')
  response = json.loads(text)
  transactions = response['result']['transactions']
  for i in range(len(transactions)) :
    hash = transactions[i]['tx']['hash']
    txsHash.append(hash)

  return txsHash

def getTxs(hashs):
  txs = []
  url = "https://s2.ripple.com:51234"
  for i in range(len(hashs)):
    params = "{\"method\":\"tx\",\"params\":[{\"transaction\":\"" + hashs[i] + "\"}]}"
    bytes = requests.post(url, params).content
    text = bytes.decode('utf8')

    tx = json.loads(text)['result']
    txs.append(tx)
  return txs

start = time.time()

classPrefix = 'Ripple'
extension = '.h'
parser = 'RippleLikeTransactionParser'

def makeH(namespace, txs):
  data = ['// This file was GENERATED by command:\n', '//     generate_fixtures.py\n', '// DO NOT EDIT BY HAND!!!\n', '#ifndef LEDGER_FIXTURES_TOTO_H\n', '#define LEDGER_FIXTURES_TOTO_H\n', '#include <gtest/gtest.h>\n', '#include <async/QtThreadDispatcher.hpp>\n', '#include <src/database/DatabaseSessionPool.hpp>\n', '#include <NativePathResolver.hpp>\n', '#include <unordered_set>\n', '#include <src/wallet/pool/WalletPool.hpp>\n', '#include <CoutLogPrinter.hpp>\n', '#include <src/api/DynamicObject.hpp>\n', '#include <wallet/common/CurrencyBuilder.hpp>\n', '#include <wallet/'+ classPrefix.lower()+'/explorers/api/'+parser+'.h>\n' , '#include <wallet/'+ classPrefix.lower()+'/'+classPrefix+'LikeWallet'+extension+'>\n', '#include <wallet/'+ classPrefix.lower() +'/database/'+ classPrefix +'LikeTransactionDatabaseHelper.h>\n', '#include <wallet/common/database/AccountDatabaseHelper.h>\n', '#include <wallet/pool/database/PoolDatabaseHelper.hpp>\n', '#include <utils/JSONUtils.h>\n', '#include <async/async_wait.h>\n', '#include <wallet/'+ classPrefix.lower() +'/'+classPrefix+'LikeAccount'+extension+'>\n', '#include <api/'+classPrefix+'LikeOperation.hpp>\n', '#include <api/'+classPrefix+'LikeTransaction.hpp>\n', '#include <api/BigInt.hpp>\n', '#include <CppHttpLibClient.hpp>\n', '#include <events/LambdaEventReceiver.hpp>\n', '#include <soci.h>\n', '#include <utils/hex.h>\n', '#include <api/Account.hpp>\n', '#include <api/'+classPrefix+'LikeAccount.hpp>\n']
  externs = []
  externs.append("\t\t\textern core::api::AccountCreationInfo XPUB_INFO;\n")
  for i in range(len(txs)):
    externs.append("\t\t\textern const std::string TX_"+str(i+1)+";\n")
  externs.append("\n")
  externs.append("\t\t\tstd::shared_ptr<core::"+classPrefix+"LikeAccount> inflate(const std::shared_ptr<core::WalletPool>& pool, const std::shared_ptr<core::AbstractWallet>& wallet);\n")
  newLines = ["namespace ledger {\n","\tnamespace testing {\n","\t\tnamespace "+namespace+" {\n"]+externs+["\t\t}\n","\t}\n", "}\n"]
  result = data+["\n"]+newLines+["\n"]
  result[3] = "#ifndef LEDGER_FIXTURES_"+namespace.upper()+"\n"
  result[4] = "#define LEDGER_FIXTURES_"+namespace.upper()+"\n"
  result.append("#endif // LEDGER_FIXTURES_"+namespace.upper()+"\n")

  with open(path+namespace+'_fixtures.h', 'w+') as file:
    file.writelines(result)
    file.close()



def makeCPP(namespace, txs):
  data = [
    "// This file was GENERATED by command:\n",
    "//     generate_fixtures.py\n",
    "// DO NOT EDIT BY HAND!!!\n"
  ]
  newLines = []
  newLines.append("#include \""+namespace+'_fixtures.h'+"\"\n")
  newLines.append("\n")
  newLines.append("namespace ledger {\n")
  newLines.append("\tnamespace testing {\n")
  newLines.append("\t\tnamespace "+namespace+" {\n")
  apiCalls = []
  apiCalls.append("core::api::AccountCreationInfo XPUB_INFO(\n")
  apiCalls.append('        0, {"xrp"}, {"44\'/144\'/0\'"}, \n')
  apiCalls.append('{ledger::core::hex::toByteArray("' + pubKey + '")} , {ledger::core::hex::toByteArray("' + chainCode + '")}\n')
  apiCalls.append(');\n')
  apiCalls.append("std::shared_ptr<core::"+classPrefix+"LikeAccount> inflate(const std::shared_ptr<core::WalletPool>& pool, const std::shared_ptr<core::AbstractWallet>& wallet) {\n")
  apiCalls.append("\tauto account = std::dynamic_pointer_cast<core::"+classPrefix+"LikeAccount>(wait(wallet->newAccountWithInfo(XPUB_INFO)));\n")
  apiCalls.append("\tsoci::session sql(pool->getDatabaseSessionPool()->getPool());\n")
  apiCalls.append("\tsql.begin();")
  for i,tx in enumerate(txs):
    apiCalls.append("\taccount->putTransaction(sql, *core::JSONUtils::parse<core::"+parser+">(TX_" + str(i+1) + "));\n")
  apiCalls.append("\tsql.commit();\n")
  apiCalls.append("\treturn account;\n")
  apiCalls.append("}\n")
  txLines = []
  for i,tx in enumerate(txs):
    txLines.append(('const std::string TX_'+str(i+1)+' = "'+json.dumps(tx).replace('"','\\"')+'";\n'))
  namespacedLines = apiCalls+txLines
  for idx, line in enumerate(namespacedLines):
    namespacedLines[idx] = "\t\t\t"+line
  newLines += namespacedLines + ["\t\t}\n","\t}\n", "}\n"]
  result = data+newLines
  with open(path+namespace+'_fixtures.cpp', 'w+') as file:
    file.writelines(result)
    file.close()


makeH(namespace, getTxs(getHashs([])))

end = time.time()

print("make H over after "+str(end-start))

makeCPP(namespace, getTxs(getHashs([])))

end2 = time.time()

print("make cpp over after "+str(end2-start))
