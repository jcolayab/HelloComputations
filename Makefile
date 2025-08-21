# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2

# Project structure
TARGET := test
SRC := Main.cpp Computation.cpp
OBJ := $(SRC:.cpp=.o)
DEPS := Computation.hpp

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	del /Q Main.o Computation.o test 2>nul
	

# Convenience
run: all
	./$(TARGET)