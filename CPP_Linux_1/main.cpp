#include "headers.h"
#include <iostream>
#include <assert.h>


int main(int argc, char* args[])
{
    std::cout << "What is 1 + 2?" << std::endl;
    std::cout << "It's: " << add(1, 2) << std::endl;    
    #ifdef MAKE_BUG
        assert(false); // breaks it if this macro is passed from the comppiler 
    #else
        //bruh
    #endif
}