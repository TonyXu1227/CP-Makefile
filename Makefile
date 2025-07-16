CXX = g++
CXXFLAGS = -std=c++20

SRCS = code.cpp

# Object formatting
OBJS = $(SRCS:.cpp=.o)

EXEC = run

all: $(EXEC)

# Object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Linker
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Clean up object files and executable
.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)

# run cat input.txt | ./run once finished