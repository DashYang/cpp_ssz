#include <iostream>
#include "cpp_ssz.h"
#include "cpp_ssz_tuple.h"
#include "cpp_ssz_bool.h"
using namespace std;

int main()
{
	//tuple [dog,horse]
	Tuple in_t("dog","horse");
	Tuple out_t;

	CppSsz* codec = new CppSszTuple();
	byte* enc_data = codec->Encode(&in_t);

	delete enc_data;
	delete codec;

	// bool true;
	bool in_b_t = true;
	bool in_b_f = false;
	codec = new CppSszBool();
	enc_data = codec->Encode(&in_b_t);
	delete enc_data;
	enc_data = codec->Encode(&in_b_f);
	delete enc_data;
	delete codec;
}
