// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.20;

import {Base_TestV1, HorseStore} from "./Base_TestV1.t.sol";
import {HuffDeployer} from "foundry-huff/HuffDeployer.sol";
import {IHorseStore} from "../../src/horseStoreV1/IHorseStore.sol";
import {Test} from "forge-std/Test.sol";

contract HorseStoreHuffV is Base_TestV1 {
    string public constant HORSE_STORE_HUFF_PATH = "horseStoreV1/HorseStore";

    function setUp() public override {
        horseStore = IHorseStore(address(HorseStore(HuffDeployer.config().deploy(HORSE_STORE_HUFF_PATH))));
    }
}
