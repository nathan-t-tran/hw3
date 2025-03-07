CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

# Object files
OBJS = llrec.o llrec-test.o

all: llrec-test

# Compile llrec-test
llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o llrec-test

# Compile llrec.o
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp -o llrec.o

# Compile llrec-test.o
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp -o llrec-test.o

# Run the program with an input file
run: llrec-test llrec-test1.in
	./llrec-test llrec-test1.in

# Run with Valgrind (memory check) and input file
valgrind: llrec-test llrec-test1.in
	$(VALGRIND) ./llrec-test llrec-test1.in

# Clean up compiled files
clean:
	rm -f *.o llrec-test *~

.PHONY: clean run valgrind
