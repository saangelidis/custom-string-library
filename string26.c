#include <stdio.h>
    // get string
    // make a bunch of chars

    // have them point at one and other
        // for each char, 2 hex/2 bytes -> one stores char the next one points to the address

    struct sink { // 9 bytes total
        char data // 1 byte
        struct sink* nextLetter // 8 bytes


    };

    struct stringHead {
        int length
        struct sink firstLetter
        struct sink* nextLetter

        
    };


// add characters after OR before
void string.append() { // positions: 0 (start), 1-[n-2] , n-1 (end) 
    
    // backward loop of defining 

    // allocate new 9 bytes

    // update address of Head

    // new 9 bytes -> 1 (char), 8 (pointer to tail's address)

}