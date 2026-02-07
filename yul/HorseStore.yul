
object "HorseStoreYul" {
    code {
        //Contract Deployment
        datacopy(0, dataoffset("runtime"), datasize("runtime"))
        return(0, datasize("runtime"))
    }
    object "runtime" {
        code {
            //function selector 
            switch selector()
            //updateHorseNumber(uint256)
            case 0xcdfea2de {
                //store the new number of horses in storage slot 0
                sstore(0, decodeAsUint(0))
            }
            //readNumberOfHorses
            case 0xe026c017 {
                returnUint(readNumber())
            }
            default {
                //revert if the function selector does not match any of the above cases
                revert(0, 0)
            }

            function storeNumber(newNumber) {
                sstore(0, newNumber)
            }

            function readNumber() -> storedNumber {
                storedNumber := sload(0)
            }

            function selector() -> s {
                s := div(calldataload(0), 0x100000000000000000000000000000000000000000000000000000000000000)
            }

            function decodeAsUint(offset) -> v {
                let positionInCalldata := add(4, mul(offset, 0x20)) // skip the function selector
                if lt(calldatasize(), add(positionInCalldata, 0x20)) {
                    revert(0, 0) // revert if the calldata is too short
                }

                v := calldataload(positionInCalldata)
            }

            function returnUint(v) {
                mstore(0,v)
                return (0, 0x20)
            }
        }
    }
}