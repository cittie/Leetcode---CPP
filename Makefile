# Makefile for Leetcode C++ Test Suite
# Author: Generated for Leetcode---CPP project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -g -Wall
LDFLAGS = -lgtest -lpthread

# Directories
SRC_DIR = .
BUILD_DIR = build
TEST_DIR = .

# Find all test files
TEST_SOURCES = $(wildcard *_test.cpp)
TEST_EXECUTABLES = $(TEST_SOURCES:%.cpp=$(BUILD_DIR)/%)

# Find all header files
HEADERS = $(wildcard *.hpp)

# Main gtest runner
GTEST_MAIN = gtest_main.cpp

# Default target
.PHONY: all clean run-test help setup

all: setup $(TEST_EXECUTABLES)

# Create build directory
setup:
	@mkdir -p $(BUILD_DIR)

# Rule to build individual test executables
$(BUILD_DIR)/%_test: %_test.cpp $(GTEST_MAIN) $(HEADERS)
	@echo "Building $@..."
	$(CXX) $(CXXFLAGS) -o $@ $(GTEST_MAIN) $< $(LDFLAGS)

# Special rule for tests that don't follow the standard naming pattern
$(BUILD_DIR)/1309_test: 1309_test.cpp $(GTEST_MAIN) 1309_decrypt-string-from-alphabet-to-integer-mapping.hpp
	@echo "Building $@..."
	$(CXX) $(CXXFLAGS) -o $@ $(GTEST_MAIN) $< $(LDFLAGS)

# Run all tests
run-test: all
	@echo "Running all tests..."
	@echo "===================="
	@for test_exe in $(TEST_EXECUTABLES); do \
		if [ -f $$test_exe ]; then \
			echo "Running $$test_exe..."; \
			./$$test_exe; \
			echo ""; \
		fi; \
	done
	@echo "All tests completed!"

# Run a specific test
run-%: $(BUILD_DIR)/%
	@echo "Running $<..."
	./$<

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILD_DIR)
	rm -f *.o *.dSYM
	rm -rf *.o.dSYM

# Show help
help:
	@echo "Available targets:"
	@echo "  all        - Build all test executables"
	@echo "  run-test   - Build and run all tests"
	@echo "  run-X      - Run specific test X (e.g., make run-1309_test)"
	@echo "  clean      - Remove all build artifacts"
	@echo "  help       - Show this help message"
	@echo ""
	@echo "Test files found:"
	@for test in $(TEST_SOURCES); do \
		echo "  - $$test"; \
	done

# Prevent make from deleting intermediate files
.PRECIOUS: $(TEST_EXECUTABLES)
