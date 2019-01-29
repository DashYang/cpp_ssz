test: test.o 
	g++ -g -o test test.o
test.o:
	g++ -g -o test.o -c test.cpp
clean:
	rm test_ssz *.o
