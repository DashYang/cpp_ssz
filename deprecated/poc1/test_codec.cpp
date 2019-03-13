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
// bool section
	cpp_ssz_codec<bool,1> codec;
	codec.m_value = true;

       	byte* enc = codec.to_bytes(1, little);
	print_encoded_hexary(enc, 3+1);
	delete enc;

	codec.m_value = false;
       	enc = codec.to_bytes(1, little);
	print_encoded_hexary(enc, 3+1);
	delete enc;

// uint section
	uint8 a(255);
	const int N = a.size();
	cpp_ssz_codec<uint8,1> codec1;
	codec1.m_value = a;

	byte* enc1 = codec1.to_bytes(a.size(), little);
	print_encoded_hexary(enc1, 3+a.size());
	//delete enc1;


// bytes section
	bytes4 b = "abcdefgh";
	cpp_ssz_codec<bytes4,1> codec2(b);
	byte* enc2 = codec2.to_bytes(b.size(), little);
	print_encoded_hexary(enc2, 3+b.size());
	//delete enc2;


}
