// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.20;
import {IHorseStore} from "./IHorseStore.sol";

contract HorseStore is IHorseStore {
    uint256 numberOfHorses;

    function updateHorseNumber(uint256 newNumberOfHorses) public {
        numberOfHorses = newNumberOfHorses;
    }

    function readNumberOfHorses() public view returns (uint256) {
        return numberOfHorses;
    }
}
