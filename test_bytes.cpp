#include <iostream>
#include "cpp_ssz.h"
using namespace std;

void print_encoded_hexary(byte* source, int size)
{
	for(int i=0; i<size; i++)
		printf("%02x ", source[i]);
	printf("\n");
}

int main()
{

	bytes4 enc4 = "abcdefgh";
	printf("%s\n", enc4.get_bytes());

	bytes8 enc8 = bytes8("abcdefghijklmnop");
	printf("%s\n", enc8.get_bytes());
}
