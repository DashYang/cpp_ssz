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

	uint8 a(255);
	uint8 b = 255;
	uint8 c(257);
	uint8 d = 257;

	a.print_hex();
	b.print_hex();
	c.print_hex();
	d.print_hex();

}
