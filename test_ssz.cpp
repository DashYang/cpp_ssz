#include <iostream>
#include "cpp_ssz.h"
#include "cpp_ssz_tuple.h"
using namespace std;

int main()
{
	//[dog,horse]
	Tuple in_t("dog","horse");
	Tuple out_t;

	CppSsz* codec = new CppSszTuple();
	byte* enc_data = codec->Encode(&in_t);

	delete enc_data;
	delete codec;
}
