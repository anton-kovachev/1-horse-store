// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.20;

import {Test} from "forge-std/Test.sol";
import {HorseStore} from "../../src/horseStoreV1/HorseStore.sol";
import {IHorseStore} from "../../src/horseStoreV1/IHorseStore.sol";

abstract contract Base_TestV1 is Test {
    IHorseStore horseStore;

    function setUp() public virtual {
        horseStore = IHorseStore(address(new HorseStore()));
    }

    function testReadValue() public view {
        uint256 numberOfHorses = horseStore.readNumberOfHorses();
        assertEq(numberOfHorses, 0);
    }

    function testWriteValue(uint256 newNumberOfHorses) public {
        horseStore.updateHorseNumber(newNumberOfHorses);
        assertEq(horseStore.readNumberOfHorses(), newNumberOfHorses);
    }
}
