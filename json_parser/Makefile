# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -g -Wall -Wextra

# Directories
SRC_DIR := .
OBJ_DIR := obj
BIN_DIR := bin

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Header files
HDRS := $(wildcard $(SRC_DIR)/*.h)
TPLTS := $(wildcard $(SRC_DIR)/*.tcc)

# Target binary
TARGET := $(BIN_DIR)/main

# Default target
all: $(TARGET)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS) $(TPLTS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into target binary
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up object files and target binary
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
