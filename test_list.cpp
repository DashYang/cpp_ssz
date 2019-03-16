/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bytes.h"
#include "cpp_ssz_uint.h"
#include "cpp_ssz_list.h"
using namespace std;
using namespace ssz;

//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x", a.data()[i]);
		printf("\n");
}

#define CHECK_SUCESS(a,b){ a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n;";}

int main()
{

/*
    List<bytes8> a;
// initial values  
    string s_over = "abcdefghijk";
    string s_fit = "abcdefgh";
    string s_under = "abcde";

    bytes b_over(s_over.begin(), s_over.end());
    bytes b_fit(s_fit.begin(), s_fit.end());
    bytes b_under(s_under.begin(), s_under.end());

    a.data().push_back(bytes8(b_over));
    a.data().push_back(bytes8(b_fit));
    a.data().push_back(bytes8(b_under));

    bytes enc = a.to_bytes(0, little);
    print_hex(enc);


    uint256 testval1("0x1111111111111111111111111111111111111111111111111111111111111111");
    uint256 testval2("0x2222222222222222222222222222222222222222222222222222222222222222");
    uint256 testval3("0x3333333333333333333333333333333333333333333333333333333333333333");
    List<uint256> b;
    b.data().push_back(testval1);
    b.data().push_back(testval2);
    b.data().push_back(testval3);

    bytes enc1 = b.to_bytes(0, little);
    print_hex(enc1);
*/
    
}

