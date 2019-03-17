/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bool.h"
using namespace std;
using namespace ssz;

//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x", a[i]);
		printf("\n");
}

#define CHECK_SUCESS(testname, a,b){ cout<< testname << " "; a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n";}

int main()
{
/*
@pytest.mark.parametrize(
    'value,expected',
    (
        (True, b'\x01'),
        (False, b'\x00'),
    ),
)
*/

    {
        Bool testval(true);
        bytes enc = testval.to_bytes(1,little);
        print_hex(enc);

        Bool dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("bool true", testval, dec);
    }
    {
        Bool testval(false);
        bytes enc = testval.to_bytes(1,little);
        print_hex(enc);

        Bool dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("bool false", testval, dec);
    }
}

