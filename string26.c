#include <stdio.h>
#include <stdlib.h>
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

// Make new string
void newString(const char str[]) {
    if (str != NULL) continue;
    else perror("Error");

    Letter *start = NULL;
    Letter *prev = NULL;

    for (int i = 0; i != '\0'; i++)
    {
        // allocate memory?
        Letter *l = (Letter *)malloc(sizeof(Letter));
        l->data = str[i];
        l->next = NULL;

        if (i == 0) {
            head = l;
        }

        else {
            prev->next = l;
        }
        prev = l;
    }
}


// add characters after OR before
void string.append() { // positions: 0 (start), 1-[n-2] , n-1 (end) 
    
    // backward loop of defining 
    
    // allocate new 9 bytes

    // update address of Head

    // new 9 bytes -> 1 (char), 8 (pointer to tail's address)

}