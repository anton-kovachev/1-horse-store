.PHONY: install build test test-v1 test-v2 snapshot clean fmt help

# Default target
help:
	@echo "Available commands:"
	@echo "  make install      - Install project dependencies (forge-std, foundry-huff, huffmate, openzeppelin)"
	@echo "  make build        - Build all contracts"
	@echo "  make test         - Run all tests"
	@echo "  make test-v1      - Run V1 tests only"
	@echo "  make test-v2      - Run V2 tests only"
	@echo "  make snapshot     - Create gas snapshot"
	@echo "  make fmt          - Format code"
	@echo "  make clean        - Clean build artifacts"

# Install dependencies
install:
	@echo "Installing Foundry dependencies..."
	forge install foundry-rs/forge-std@v1.14.0
	forge install huff-language/foundry-huff@7d1ce15ccf92bd68458c7e28e0ae847b64b4fc74
	forge install huff-language/huffmate@4e2c9bd3412ab8cc65f6ceadafc01a1ff1815796
	forge install OpenZeppelin/openzeppelin-contracts@01ef448981be9d20ca85f2faf6ebdf591ce409f3 
	@echo "Installation complete!"

# Build contracts
build:
	forge build

# Run all tests
test:
	forge test

# Run V1 tests
test-v1:
	forge test --match-path test/v1/*

# Run V2 tests
test-v2:
	forge test --match-path test/v2/*

# Run V2 Huff tests with verbose output
test-v2-huff:
	forge test --match-contract HorseStoreHuffV2 -vvvv

# Create gas snapshot
snapshot:
	forge snapshot

# Format code
fmt:
	forge fmt

# Clean build artifacts
clean:
	forge clean
	rm -rf cache out
