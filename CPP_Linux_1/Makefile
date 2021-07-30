# make a program where there is nothing special 
COMPILER = c++
FLAGS = 

all: main.out

headers.o: headers.h headers.cpp
	$(COMPILER) -c $^

main.out: main.cpp headers.o
	$(COMPILER) $^ -o $@

clean: 
	rm *.o *.out