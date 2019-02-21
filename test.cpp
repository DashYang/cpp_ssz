#include <iostream>
#include "cpp_ssz_uint.h"
using namespace std;

void print_encoded_hexary(byte* source, int size)
{
	for(int i=0; i<size; i++)
		printf("%02x ", source[i]);
	printf("\n");
}

int main()
{
	std::vector<byte> data;

	uint8 a(255);
	uint8 b = 255;
	uint8 c(257);
	uint8 d = 257;

	a.print_hex();
	b.print_hex();
	c.print_hex();
	d.print_hex();

	// encoding test
	// byte* will be replaced by bytes type
	byte* enc;
        enc = d.to_bytes(1, little);
	print_encoded_hexary(enc, 3+1);
	delete enc;

	uint256 e = 0xabcdef01;
       	enc = e.to_bytes(1, little);
	print_encoded_hexary(enc, 3+1);
	delete enc;

	enc = e.to_bytes(2, little);
	print_encoded_hexary(enc, 3+2);
	delete enc;

	 enc = e.to_bytes(3, little);
	print_encoded_hexary(enc, 3+3);
	delete enc;

	enc = e.to_bytes(4, little);
	print_encoded_hexary(enc, 3+4);
	delete enc;
}
