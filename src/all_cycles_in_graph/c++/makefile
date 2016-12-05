CC=g++
CFLAGS=@conanbuildinfo.gcc
DEPS = detect_cycles.h
OBJ = tests/tests_detect_cycles.o detect_cycles.o

conan:
	conan install

%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

compile: conan $(OBJ)
	$(CC) -o tests/run_tests tests/main_tests.cpp $(OBJ) $(CFLAGS)

run_tests: compile
	./tests/run_tests

clean:
	rm -f *.o tests/*.o tests/run_tests conanbuildinfo.gcc conaninfo.txt
