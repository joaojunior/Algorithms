CC=g++
VERSION=c++11
CFLAGS=@conanbuildinfo.gcc
DEPS = detect_cycles.h
OBJ = tests/tests_detect_cycles.o tests/tests_dfs.o graph.o detect_cycles.o dfs.o

conan:
	conan install

%.o: %.cpp $(DEPS)
		$(CC) -std=$(VERSION) -c -o $@ $< $(CFLAGS)

compile: conan $(OBJ)
	$(CC) -std=$(VERSION) -o tests/run_tests tests/main_tests.cpp $(OBJ) $(CFLAGS)

run_tests: compile
	./tests/run_tests

clean:
	rm -f *.o tests/*.o tests/run_tests conanbuildinfo.gcc conaninfo.txt .*.swp tests/.*.swp
