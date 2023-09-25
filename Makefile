##
## EPITECH PROJECT, 2023
## B-SYN-400-LYN-4-1-abstractVM-keziah.picq
## File description:
## Makefile
##

# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++20 -Wall -Wextra

# Directories
SRCDIR := src
OPDIR := Operands

# Output executable
TARGET := abstractVM

# Source files
SRCS := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(OPDIR)/*.cpp)
# Object files
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to compile C++ files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files and create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJS) $(TARGET)