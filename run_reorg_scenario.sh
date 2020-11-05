
function press_enter {
	read -n 1 -r -s -p $'Press enter to continue...\n'
}

function btccli {
	docker exec -it ledger-bitcoin-rpc bitcoin-cli $*
}

address=`btccli getnewaddress | tr -dc '[[:print:]]'`

echo "BEGIN $address END"

echo "Create some blocks"
btccli generatetoaddress 100 "$address"
echo "Send 20BTC"
btccli  sendtoaddress "msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG" 10
btccli sendtoaddress "msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG" 10
press_enter
echo "Send 10 BTC and validate 1 block"
btccli generatetoaddress 100 $address
btccli  sendtoaddress "msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG" 10
block_hash=`btccli generatetoaddress 1 "$address" | jq -r '.[0]'`
press_enter
echo "Invalidate last block and mine another one"
echo "Remove block " $block_hash
address=`btccli getnewaddress | tr -dc '[[:print:]]'`

btccli invalidateblock $block_hash
btccli generatetoaddress 2 $address
echo "Done"
