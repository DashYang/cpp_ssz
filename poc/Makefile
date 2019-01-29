test_ssz: test_ssz.o cpp_ssz_tuple.o cpp_ssz_bool.o
	g++ -g -o test_ssz test_ssz.o cpp_ssz_tuple.o cpp_ssz_bool.o
test_ssz.o:
	g++ -g -o test_ssz.o -c test_ssz.cpp 
cpp_ssz_tuple.o:
	g++ -g -o cpp_ssz_tuple.o -c cpp_ssz_tuple.cpp
cpp_ssz_bool.o:
	g++ -g -o cpp_ssz_bool.o -c cpp_ssz_bool.cpp
clean:
	rm test_ssz *.o
