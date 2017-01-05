CC=g++
VERSION=c++11
CFLAGS=@conanbuildinfo.gcc
DEPS = detect_cycles.h
DATA_STRUCTURES_OBJ = graph.o
OBJ = tests/tests_detect_cycles.o tests/tests_dfs.o detect_cycles.o dfs.o
GRAPH = ../../../data_structures/graph/c++
INCLUDE=-I$(GRAPH)

conan:
	conan install

%.o: %.cpp $(DEPS) conan
		$(CC) -std=$(VERSION) -c -o $@ $< $(INCLUDE) $(CFLAGS)

compile: conan $(OBJ)
	make graph.o --directory $(GRAPH)
	$(CC) -std=$(VERSION) -o tests/run_tests tests/main_tests.cpp $(CFLAGS) $(OBJ) $(GRAPH)/graph.o

run_tests: compile
	./tests/run_tests

clean:
	rm -f *.o tests/*.o tests/run_tests conanbuildinfo.gcc conaninfo.txt .*.swp tests/.*.swp
