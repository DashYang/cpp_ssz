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

	cpp_ssz_codec<bool,1> codec;
	codec.m_type = type_BOOL;
	codec.m_value = true;

       	byte* enc = codec.to_bytes(1, little);
	print_encoded_hexary(enc, 3+1);
	delete enc;

	codec.m_value = false;
       	enc = codec.to_bytes(1, little);
	print_encoded_hexary(enc, 3+1);
	delete enc;

}
