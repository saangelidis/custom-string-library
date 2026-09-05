#include <stdio.h>
#include <sidlib.h>
    // get string
    // make a bunch of chars

    // have them point at one and other
        // for each char, 2 hex/2 bytes -> one stores char the next one points to the address

// basically building a self referential structure



typedef struct Letter {   // 9 bytes total, that are next to each other
    char data;             // 1 byte
    struct Letter *next;   // 8 bytes
} Letter;


// Modify content of letter
void changeLetter(Letter *l, char newChar) {
    if (l!=NULL) {
        l -> data = newChar;
    }
    else perror("Error");
}

// Modify pointer of letter
void changePointer(Letter *l, Letter *newAddy) {
    if (l!=NULL) {
        l -> next = newAddy; 
    }
    else perror("Error");
}


void newString(const char str, int size = sizeof(str)) {
    for (int i = 0; i < size; i++)
    {
        // allocate memory?

        Letter *l = (Letter *)malloc(sizeof(Letter));
        
        if (i == 0) {
            Letter head
        }
    }
}


// add characters after OR before
void string.append() { // positions: 0 (start), 1-[n-2] , n-1 (end) 
    
    // backward loop of defining 
    
    // allocate new 9 bytes

    // update address of Head

    // new 9 bytes -> 1 (char), 8 (pointer to tail's address)

}