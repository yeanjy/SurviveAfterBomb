# Define directories
SRC_DIR:= src
BIN_DIR:= bin
INCLUDE_DIR:= include

# Define compiler and flags
CXX:= g++
CXXFLAGS:= -Wall -g -std=c++17 -I$(INCLUDE_DIR)

# Define object files and executable
OBJECTS:= $(SRC_DIR)/*.cpp:$(OBJ_DIR)/%.o
OBJ_DIR:= obj
EXEC:= $(BIN_DIR)/run

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    @mkdir -p $(@D)
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
