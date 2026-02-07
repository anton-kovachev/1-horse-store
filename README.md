# 🐴 Horse Store

A comprehensive educational project demonstrating **gas-optimized smart contract development** using multiple low-level EVM languages. This repository implements the same contract functionality across different abstraction levels—from high-level Solidity to low-level Huff assembly—enabling direct comparison of gas costs and bytecode efficiency.

## 📋 Table of Contents

- [Overview](#overview)
- [Project Goal](#project-goal)
- [Technologies Used](#technologies-used)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Running Tests](#running-tests)
- [Contract Implementations](#contract-implementations)
- [Gas Comparison](#gas-comparison)
- [Learning Resources](#learning-resources)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

Horse Store is an educational smart contract project that demonstrates:

- **Multi-language EVM development**: Implementations in Solidity, Yul, and Huff
- **Gas optimization techniques**: Direct comparison of gas costs across different abstraction levels
- **Low-level EVM programming**: Deep dive into opcodes, stack manipulation, and memory management
- **NFT mechanics**: V2 includes ERC721-like functionality with unique horse feeding mechanics

### Version 1 (Basic)

A simple storage contract that demonstrates:

- Reading and writing a single storage variable
- Basic contract interaction patterns
- Gas cost differences across implementations

### Version 2 (Advanced)

An NFT-based contract implementing:

- ERC721-like token minting and management
- Time-based state mechanics (horse feeding)
- Complex storage patterns using hashmaps
- Advanced Huff programming with macros

## 🎯 Project Goal

The primary goal of this project is **education through implementation**:

1. **Understand EVM internals**: By implementing the same logic in progressively lower-level languages, developers gain deep insight into how the Ethereum Virtual Machine processes transactions.

2. **Master gas optimization**: Compare gas consumption across implementations to understand which patterns are most efficient and why.

3. **Learn Huff assembly**: Provide practical examples of Huff—the most gas-efficient way to write smart contracts—while maintaining readability through comprehensive macros.

4. **Bridge the abstraction gap**: Help developers understand what happens "under the hood" when they write Solidity code.

## 🛠️ Technologies Used

- **[Foundry](https://github.com/foundry-rs/foundry)** - Fast, portable, and modular toolkit for Ethereum application development
  - `forge` - Ethereum testing framework
  - `anvil` - Local Ethereum node
  - `cast` - Tool for performing Ethereum RPC calls
- **[Huff](https://github.com/huff-language/huff-rs)** - Low-level programming language for writing highly optimized smart contracts

- **[Huffmate](https://github.com/huff-language/huffmate)** - Library of common Huff contracts and utilities

- **[Solidity](https://soliditylang.org/)** - High-level language for implementing smart contracts

- **[Yul](https://docs.soliditylang.org/en/latest/yul.html)** - Intermediate language that can be compiled to bytecode

- **[OpenZeppelin Contracts](https://github.com/OpenZeppelin/openzeppelin-contracts)** - Library for secure smart contract development

## 📁 Project Structure

```
1-horse-store/
├── src/
│   ├── horseStoreV1/          # Version 1: Basic storage
│   │   ├── HorseStore.sol     # Solidity implementation
│   │   ├── HorseStore.huff    # Huff implementation
│   │   ├── HorseStoreYul.sol  # Yul implementation
│   │   └── IHorseStore.sol    # Interface
│   └── horseStoreV2/          # Version 2: NFT with feeding mechanics
│       ├── HorseStore.huff    # Huff ERC721 implementation
│       └── HorseStore.sol     # Solidity ERC721 implementation
├── test/
│   ├── v1/                    # V1 tests
│   │   ├── Base_TestV1.t.sol
│   │   ├── HorseStoreHuff.t.sol
│   │   ├── HorseStoreSolc.t.sol
│   │   └── HorseStoreYul.t.sol
│   └── v2/                    # V2 tests
│       ├── Base_TestV2.t.sol
│       ├── HorseStoreHuffV2.t.sol
│       └── HorseStoreSolcV2.t.sol
├── lib/                       # Dependencies
│   ├── forge-std/
│   ├── foundry-huff/
│   ├── huffmate/
│   └── openzeppelin-contracts/
├── breakdowns/                # Low-level bytecode analysis
├── yul/                       # Standalone Yul files
└── foundry.toml              # Foundry configuration
```

## ✅ Prerequisites

Before you begin, ensure you have the following installed:

- **[Git](https://git-scm.com/)** (v2.0+)
- **[Foundry](https://book.getfoundry.sh/getting-started/installation)**
  ```bash
  curl -L https://foundry.paradigm.xyz | bash
  foundryup
  ```
- **[Huff Compiler](https://docs.huff.sh/get-started/installing/)**
  ```bash
  curl -L get.huff.sh | bash
  huffup
  ```

## 🚀 Installation

1. **Clone the repository**

   ```bash
   git clone https://github.com/yourusername/1-horse-store.git
   cd 1-horse-store
   ```

2. **Install dependencies**

   ```bash
   forge install
   ```

3. **Build contracts**
   ```bash
   forge build
   ```

## 🧪 Running Tests

### Run All Tests

```bash
forge test
```

### Run Tests with Verbosity

```bash
forge test -vvvv
```

### Run Specific Test Contracts

**Version 1 Tests:**

```bash
# Test Solidity implementation
forge test --match-contract HorseStoreSolc

# Test Huff implementation
forge test --match-contract HorseStoreHuff

# Test Yul implementation
forge test --match-contract HorseStoreYul
```

**Version 2 Tests:**

```bash
# Test Huff V2 implementation
forge test --match-contract HorseStoreHuffV2 -vvvv

# Test Solidity V2 implementation
forge test --match-contract HorseStoreSolcV2
```

### Run Specific Test Functions

```bash
forge test --match-test testMintingHorseAssignsOwner
```

### Generate Gas Report

```bash
forge test --gas-report
```

### Create Gas Snapshot

```bash
forge snapshot
```

## 📝 Contract Implementations

### Version 1: Basic Storage Contract

**Interface:**

```solidity
interface IHorseStore {
    function updateHorseNumber(uint256 newNumberOfHorses) external;
    function readNumberOfHorses() external view returns (uint256);
}
```

**Implementations:**

- **Solidity** ([HorseStore.sol](src/horseStoreV1/HorseStore.sol)): Standard high-level implementation
- **Yul** ([HorseStoreYul.sol](src/horseStoreV1/HorseStoreYul.sol)): Inline assembly implementation
- **Huff** ([HorseStore.huff](src/horseStoreV1/HorseStore.huff)): Pure assembly implementation

### Version 2: NFT with Feeding Mechanics

**Features:**

- ERC721-compatible token minting
- Horse feeding with timestamp tracking
- Happiness state based on feeding frequency
- Total supply tracking

**Key Functions:**

- `mintHorse()`: Mint a new horse NFT to caller
- `feedHorse(uint256 horseId)`: Feed a horse and update timestamp
- `isHappyHorse(uint256 horseId)`: Check if horse was fed within 24 hours
- `horseIdToFedTimeStamp(uint256 horseId)`: Get last feeding timestamp
- `totalSupply()`: Get total number of minted horses

**Implementations:**

- **Huff** ([HorseStore.huff](src/horseStoreV2/HorseStore.huff)): Gas-optimized ERC721 with custom mechanics
- **Solidity** ([HorseStore.sol](src/horseStoreV2/HorseStore.sol)): Standard Solidity implementation

## ⛽ Gas Comparison

One of the primary goals of this project is to demonstrate gas efficiency differences:

| Implementation | Language Level | Typical Gas Cost | Control |
| -------------- | -------------- | ---------------- | ------- |
| Huff           | Assembly       | Lowest           | Maximum |
| Yul            | Intermediate   | Low-Medium       | High    |
| Solidity       | High-level     | Medium-High      | Medium  |

Run `forge snapshot` to generate precise gas measurements for your environment.

## 📚 Learning Resources

### Understanding the EVM

- [EVM Opcodes Reference](https://www.evm.codes/)
- [Ethereum Yellow Paper](https://ethereum.github.io/yellowpaper/paper.pdf)

### Huff Language

- [Huff Documentation](https://docs.huff.sh/)
- [Huffmate Library](https://github.com/huff-language/huffmate)

### Foundry Framework

- [Foundry Book](https://book.getfoundry.sh/)
- [Forge Testing Guide](https://book.getfoundry.sh/forge/tests)

### Gas Optimization

- [Gas Optimization Tips](https://github.com/iskdrews/awesome-solidity-gas-optimization)

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is unlicensed and available for educational purposes.

---

**Built with ❤️ for the Ethereum developer community**
