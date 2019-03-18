/*
   This file is part of cpp_ssz.
   @author SigmoiD <alphabet@hotmail.co.kr>
 */ 

#ifndef __CPP_SSZ_TEST_H__
#define __CPP_SSZ_TEST_H__

#include <stdio.h>
#include <iostream>

#define CHECK_SUCESS(testname, a,b) \ 
        { cout<< testname << " "; \
          a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n";}

//pretty printer section
void print_hex(const bytes& a) {
    for(int i=0; i<a.size(); i++)
        printf("%02x", a[i]);
    printf("\n");
}
#endif
