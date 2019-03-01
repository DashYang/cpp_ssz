#include <iostream>
#include "cpp_ssz_bool.h"
#include "cpp_ssz_uint.h"
#include "cpp_ssz_bytes.h"
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

	BOOL myb = true;
	BOOL myc(false);

	print_encoded_hexary(myb.to_bytes(1, little), 4);
	print_encoded_hexary(myc.to_bytes(1, little), 4);

	uint8 a(255);
	uint8 b = 255;
	uint8 c(257);
	uint8 d = 257;

	a.print_hex();
	b.print_hex();
	c.print_hex();
	d.print_hex();

	bytes4 enc4 = "abcdefgh";
	printf("%s\n", enc4.get_bytes());

	bytes8 enc8 = bytes8("abcdefghijklmnop");
	printf("%s\n", enc8.get_bytes());

        bytes4 enc_uint = d.to_bytes(d.size(), little);
	print_encoded_hexary(enc_uint.get_bytes(), enc_uint.size());

	byte* enc;
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
