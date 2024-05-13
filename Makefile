# ID: 319055430
# Email: noa.fishman@gmail.com

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11 -Werror

# Source files
SRCS = Graph.cpp Algorithms.cpp Demo.cpp TestCounter.cpp Test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable files
DEMO = Demo
TEST = Test

# Targets
all: $(DEMO) $(TEST)

$(DEMO): $(filter-out TestCounter.o Test.o doctest.o, $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@

$(TEST): TestCounter.o Test.o Graph.o Algorithms.o
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(DEMO) $(TEST)
