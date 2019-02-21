test: test.o cpp_ssz_tuple.o cpp_ssz_bool.o
	g++ -g -o test test.o cpp_ssz_tuple.o cpp_ssz_bool.o
test.o:
	g++ -g -o test.o -c test.cpp 
cpp_ssz_tuple.o:
	g++ -g -o cpp_ssz_tuple.o -c cpp_ssz_tuple.cpp
cpp_ssz_bool.o:
	g++ -g -o cpp_ssz_bool.o -c cpp_ssz_bool.cpp
clean:
	rm test *.o
