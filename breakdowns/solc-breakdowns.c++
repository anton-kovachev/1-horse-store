//contract creation 0x6080604052348015600e575f5ffd5b506101298061001c5f395ff3

//runtime fe6080604052348015600e575f5ffd5b50600436106030575f3560e01c8063cdfead2e146034578063e026c01714604c575b5f5ffd5b604a60048036038101906046919060a9565b6066565b005b6052606f565b604051605d919060dc565b60405180910390f35b805f8190555050565b5f5f54905090565b5f5ffd5b5f819050919050565b608b81607b565b81146094575f5ffd5b50565b5f8135905060a3816084565b92915050565b5f6020828403121560bb5760ba6077565b5b5f60c6848285016097565b91505092915050565b60d681607b565b82525050565b5f60208201905060ed5f83018460cf565b9291505056
//medata fea264697066735822122004d3ac746ce008bc0eae663a7c54bcf6bfab3b7a18e31eedcb9c07da493de7af64736f6c634300081e0033



// 1. Contract Creation
// 2. Contract Runtime
// 3. Metadata (Optional)


//Free Memory pointer
PUSH1 0x80 // [0x80]
PUSH1 0x40 // [0x40, 0x80]
MSTORE

// What this chunk do?
// If someone sents value with this call revert, otherwise jump to continue execution
CALLVALUE //[msg.value]
DUP1 // [msg.value, msg.value]
ISZERO //[msg.value == 0, msg.value]
PUSH1 0x0e // [0x0e, msg.value == 0, msg.value]
JUMPI //[msg.value]
PUSH0 //[0x00, msg.value]
PUSH0 //[0x00, msg.value]
REVERT //[msg.value]

//Jump dest if msg.value == 0
//Stick the runtime code on chain
JUMPDEST //[msg.value]
POP // []
PUSH2 0x0129 // [0x0129]
DUP1 // [0x0129, 0x0129]
PUSH2 0x001c // [0x001c, 0x0129, 0x0129]
PUSH0 // [0, 0x001c, 0x0129, 0x0129]
CODECOPY // [0x0129] //Memory runtime code
PUSH0 //[0x00, 0x]
RETURN //[]
INVALID //End of contract creation

//2. Runtime code
//Entry poiint of all calls
//free memory pointer
PUSH1 0x80
PUSH1 0x40
MSTORE

//Checking for msg.value if given revert, otherwise continue execution
CALLVALUE //[msg.value] 
DUP1 //[msg.value, msg.value]
ISZERO //[msg.value == 0, msg.value]
PUSH1 0x0e //[0x0E, msg.value == 0, msg.value]

JUMPI //[mgg.value] if msg.value == 0 continue, otherwise revert
// if calldata_size < 0x04 -> calldata_jump
PUSH0 //[0x00, msg.value]
PUSH0 //[0x00, 0x00, msg.value]
REVERT //[msg.value]

// If msg.value == 0, start here
//This is checking to see if there is enough calldata for a function selector
JUMPDEST //[msg.value]
POP //[]
PUSH1 0x04 // [0x04]
CALLDATASIZE // [calldata.size, 0x04]
LT // [calldata.size < 0x04]
PUSH1 0x30 // [0x30, calldata.size < 0x04] counter and conditiona;
JUMPI //[]
// if calldata_size < 0x04 -> calldata_junmp

//
PUSH0 //[0x00]
CALLDATALOAD // [32 bytes of calldata, 0x00]
PUSH1 0xe0 // [0xe0, 32 bytes of calldata, 0x00]
SHR // [function_selector, 0x00]
DUP1 //[function_selector, function_selector, 0x00]
PUSH4 0xcdfead2e // [0xcdfead2e, function_selector, function_selector, 0x00]
EQ // [function_selector == 0xcdfead2e, function_selector, 0x00]
PUSH1 0x34 // [0x34, function_selector == 0xcdfead2e, function_selector, 0x00]
JUMPI // [function_selector, 0x00] if function_selector == 0xcdfead2e jump to 0x34, otherwise continue

DUP1 // [function_selector, function_selector, 0x00]
PUSH4 0xe026c017 // [0xe026c017, function_selector, function_selector, 0x00]
EQ // [function_selector == 0xe026c017, function_selector, 0x00]
PUSH1 0x4c // [0x4c, function_selector == 0xe026c017, function_selector, 0x00]
JUMPI // [function_selector, 0x00] if function_selector == 0xe026c017 jump to 0x4c, otherwise continue

// If function selector does not match any of the functions in the contract, revert
JUMPDEST
PUSH0
PUSH0
REVERT

//
JUMPDEST //[function_selector]
PUSH1 0x4a //[0x4a, function_selector]
PUSH1 0x04 // [0x04, 0x4a, function_selector]
DUP1 //[0x04, 0x04, 0x4a, function_selector]
CALLDATASIZE //[calldata.size, 0x04, 0x4a, function_selector]
SUB
DUP2
ADD
SWAP1
PUSH1 0x46
SWAP2
SWAP1
PUSH1 0xa9
JUMP
JUMPDEST
PUSH1 0x66
JUMP
JUMPDEST
STOP
JUMPDEST
PUSH1 0x52
PUSH1 0x6f
JUMP

//Read number of horses
JUMPDEST
PUSH1 0x40
MLOAD
PUSH1 0x5d
SWAP2
SWAP1
PUSH1 0xdc
JUMP
JUMPDEST
PUSH1 0x40
MLOAD
DUP1
SWAP2
SUB
SWAP1
RETURN

JUMPDEST
DUP1
PUSH0
DUP2
SWAP1
SSTORE
POP
POP
JUMP
JUMPDEST
PUSH0
PUSH0
SLOAD
SWAP1
POP
SWAP1
JUMP

//caldata jump
//Revert Jumpdest
JUMPDEST //[]
PUSH0 // [0x00]
PUSH0 // [0x00, 0x00]
REVERT //[]
JUMPDEST
PUSH0
DUP2
SWAP1
POP
SWAP2
SWAP1
POP
JUMP
JUMPDEST
PUSH1 0x8b
DUP2
PUSH1 0x7b
JUMP
JUMPDEST
DUP2
EQ
PUSH1 0x94
JUMPI
PUSH0
PUSH0
REVERT
JUMPDEST
POP
JUMP
JUMPDEST
PUSH0
DUP2
CALLDATALOAD
SWAP1
POP
PUSH1 0xa3
DUP2
PUSH1 0x84
JUMP
JUMPDEST
SWAP3
SWAP2
POP
POP
JUMP

//update_horsenumber jump dest 2
JUMPDEST //[0x04, calldata_size, 0x3f, 0x43, function_selector]
PUSH0 //[0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
PUSH1 0x20 // [0x20, 0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
DUP3 // [0x04, 0x20, 0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
DUP5 // [calldata_size, 0x04, 0x20, 0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
SUB //[calldata_size - 0x04, 0x20, 0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
//is there more calldata than just the function selector?
SLT //[calldata_size - 0x04 < 0x20, 0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
//is there more calldata than just the function selector? if not jump to 0xbb, otherwise continue
ISZERO  //[calldata_size - 0x04 < 0x20 == true, 0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
PUSH1 0xbb //[0xbb, calldata_size - 0x04 < 0x20 == true, 0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
JUMPI //[0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector] jump to the program counter marked with 0xbb
//We are going to just dest 3 if there is more calldata than func_selector
PUSH1 0x40
MSTORE
CALLVALUE
DUP1
ISZERO
PUSH1 0x0e

JUMPI
PUSH0
PUSH0
REVERT
JUMPDEST
POP
PUSH1 0x04
CALLDATASIZE
LT
PUSH1 0x30
JUMPI
PUSH0
CALLDATALOAD
PUSH1 0xe0
SHR
DUP1
PUSH4 0xcdfead2e
EQ
PUSH1 0x34
JUMPI
DUP1
PUSH4 0xe026c017
EQ
PUSH1 0x4c
JUMPI
JUMPDEST
PUSH0
PUSH0
REVERT
JUMPDEST
PUSH1 0x4a
PUSH1 0x04
DUP1
CALLDATASIZE
SUB
DUP2
ADD
SWAP1
PUSH1 0x46
SWAP2
SWAP1
PUSH1 0xa9
JUMP
JUMPDEST
PUSH1 0x66
JUMP
JUMPDEST
STOP
JUMPDEST
PUSH1 0x52
PUSH1 0x6f
JUMP
JUMPDEST
PUSH1 0x40
MLOAD
PUSH1 0x5d
SWAP2
SWAP1
PUSH1 0xdc
JUMP
JUMPDEST
PUSH1 0x40
MLOAD
DUP1
SWAP2
SUB
SWAP1
RETURN
JUMPDEST
DUP1
PUSH0
DUP2
SWAP1
SSTORE
POP
POP
JUMP
JUMPDEST
PUSH0
PUSH0
SLOAD
SWAP1
POP
SWAP1
JUMP
JUMPDEST
PUSH0
PUSH0
REVERT
JUMPDEST
PUSH0
DUP2
SWAP1
POP
SWAP2
SWAP1
POP
JUMP
JUMPDEST
PUSH1 0x8b
DUP2
PUSH1 0x7b
JUMP
JUMPDEST
DUP2
EQ
PUSH1 0x94
JUMPI
PUSH0
PUSH0
REVERT
JUMPDEST
POP
JUMP
JUMPDEST
PUSH0
DUP2
CALLDATALOAD
SWAP1
POP
PUSH1 0xa3
DUP2
PUSH1 0x84
JUMP
JUMPDEST
SWAP3
SWAP2
POP
POP
JUMP
JUMPDEST
PUSH0
PUSH1 0x20
DUP3
DUP5
SUB
SLT
ISZERO
PUSH1 0xbb
JUMPI
PUSH1 0xba
PUSH1 0x77
JUMP
JUMPDEST
JUMPDEST
PUSH0
PUSH1 0xc6
DUP5
DUP3
DUP6
ADD
PUSH1 0x97
JUMP
JUMPDEST
SWAP2
POP
POP
SWAP3
SWAP2
POP
POP
JUMP
JUMPDEST
PUSH1 0xd6
DUP2
PUSH1 0x7b
JUMP
JUMPDEST
DUP3
MSTORE
POP
POP
JUMP
JUMPDEST
PUSH0
PUSH1 0x20
DUP3
ADD
SWAP1
POP
PUSH1 0xed
PUSH0
DUP4
ADD
DUP5
PUSH1 0xcf
JUMP

//updateNumberOfHorses jump dest 3
JUMPDEST //[0x00, 0x04, calldata_size, 0x3f, 0x43, function_selector]
SWAP3
SWAP2
POP
POP
JUMP
INVALID
LOG2
PUSH5 0x6970667358
INVALID
SLT
KECCAK256
DIV
INVALID
INVALID
PUSH21 0x6ce008bc0eae663a7c54bcf6bfab3b7a18e31eedcb
SWAP13
SMOD
INVALID
BLOBHASH
RETURNDATASIZE
INVALID
INVALID
PUSH5 0x736f6c6343
STOP
ADDMOD
CLZ
STOP
CALLER
PUSH1 0xba
PUSH1 0x77
JUMP
JUMPDEST
JUMPDEST
PUSH0
PUSH1 0xc6
DUP5
DUP3
DUP6
ADD
PUSH1 0x97
JUMP
JUMPDEST
SWAP2
POP
POP
SWAP3
SWAP2
POP
POP
JUMP
JUMPDEST
PUSH1 0xd6
DUP2
PUSH1 0x7b
JUMP
JUMPDEST
DUP3
MSTORE
POP
POP
JUMP
JUMPDEST
PUSH0
PUSH1 0x20
DUP3
ADD
SWAP1
POP
PUSH1 0xed
PUSH0
DUP4
ADD
DUP5
PUSH1 0xcf
JUMP
JUMPDEST
SWAP3
SWAP2
POP
POP
JUMP
INVALID
LOG2
PUSH5 0x6970667358
INVALID
SLT
KECCAK256
DIV
INVALID
INVALID
PUSH21 0x6ce008bc0eae663a7c54bcf6bfab3b7a18e31eedcb
SWAP13
SMOD
INVALID
BLOBHASH
RETURNDATASIZE
INVALID
INVALID
PUSH5 0x736f6c6343
STOP
ADDMOD
CLZ
STOP
CALLER




















