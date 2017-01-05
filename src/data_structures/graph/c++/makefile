CC=g++
VERSION=c++11
OBJ = graph.o

%.o: %.cpp
	$(CC) -std=$(VERSION) -c -o $@ $< $(INCLUDE)

clean:$
	rm -f *.o .*.swp conanbuildinfo.gcc conaninfo.txt
