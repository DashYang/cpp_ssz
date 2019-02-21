test: test.o cpp_ssz_uint.o 
	g++ -g -o test test.o cpp_ssz_uint.o 
test.o:
	g++ -g -o test.o -c test.cpp 
cpp_ssz_uint.o:
	g++ -g -o cpp_ssz_uint.o -c cpp_ssz_uint.cpp
clean:
	rm test *.o
