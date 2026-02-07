// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.20;

import {IHorseStore} from "./IHorseStore.sol";

contract HorseStoreYul is IHorseStore {
    uint256 numberOfHorses;

    function updateHorseNumber(uint256 newNumberOfHorses) public {
        //numberOfHorses = newNumberOfHorses;
        assembly {
            sstore(numberOfHorses.slot, newNumberOfHorses)
        }
    }

    function readNumberOfHorses() public view returns (uint256) {
        //return numberOfHorses;
        assembly {
            let numberOfHorsesValue := sload(numberOfHorses.slot)
            mstore(0x00, numberOfHorsesValue)
            return(0x00, 0x20)
        }
    }
}
