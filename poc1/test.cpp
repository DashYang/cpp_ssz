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
	bool val = false;
	cpp_ssz_codec<bool> codec;
	codec.m_value = &val;
	codec.m_count = 1;

       	byte* enc = codec.to_bytes(1, little);
	print_encoded_hexary(enc, 3+1);
	delete enc;

	val = true;
       	enc = codec.to_bytes(1, little);
	print_encoded_hexary(enc, 3+1);
	delete enc;

// uint section
	uint8 a(255);
	const int N = a.size();
	cpp_ssz_codec<uint8> codec1;
	codec1.m_count = 1;
	codec1.m_value = &a;

	byte* enc1 = codec1.to_bytes(a.size(), little);
	print_encoded_hexary(enc1, 3+a.size());
	delete enc1;

// bytes section
	bytes4 b = "abcdefgh";
	cpp_ssz_codec<bytes4> codec2;
	codec2.m_count = 1;
	codec2.m_value = &b;
	byte* enc2 = codec2.to_bytes(b.size(), little);
	print_encoded_hexary(enc2, 3+b.size());
	delete enc2;

// list section
	bool list[2] = {true, false};
	cpp_ssz_codec<bool> codec3;
	codec3.m_value = list;
	codec3.m_count = 2;
	byte* enc3 = codec3.to_bytes(sizeof(bool),little);
	print_encoded_hexary(enc3, 8);
	delete enc3;

	bytes4 list1[2] = {"abcd", "efgh"};
	cpp_ssz_codec<bytes4> codec4;
	codec4.m_value = list1;
	codec4.m_count = 2;
	byte* enc4 = codec4.to_bytes(list1[0].size(),little);
	print_encoded_hexary(enc4, (3+list1[0].size()) * codec4.m_count);
	delete enc4;

}
