# 1. Configuration
CXX      := g++
CXXFLAGS := -Wall -Wextra -Isrc
LDFLAGS  := -lgtest -lgtest_main -pthread

# 2. Directory Setup
# This finds all .cpp files inside 'test' and its subdirectories
TEST_DIR := test
SRC_DIR  := src
TESTS    := $(shell find $(TEST_DIR) -name "*.cpp")

# 3. Output
TARGET   := run_all_tests

# 4. Rules
all: $(TARGET)

$(TARGET): $(TESTS)
	@echo "Found test files: $(TESTS)"
	$(CXX) $(CXXFLAGS) $(TESTS) $(LDFLAGS) -o $(TARGET)

# Run the tests
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET)

.PHONY: all run clean