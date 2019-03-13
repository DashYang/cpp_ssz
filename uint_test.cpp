#include "Common.h"
using namespace std;

//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x ", a.data()[i]);
		printf("\n");
}

#define CHECK_SUCESS(a,b){ a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n;";}

int main()
{
    u256 c(8);
    cout << c << endl;
}

