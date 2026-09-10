#include "string26.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // built on top of string.h

typedef struct String {
    char *letters; // pointer to string's first letter
    size_t count;        // how m
    size_t capacity;     //
} String;


// Make new string
String *newStr(const char* l) {
    
    // allocate memory the size of a string struct
    String *str = malloc(sizeof(*str));
    
    // error handling
    if (str==NULL){ 
        perror("Allocation failed.");
        free(str);
        return NULL;
    }
    
    // initialize var to get string size
    size_t letterLength = 0;

    // get string size
    while (l[letterLength] != '\0') letterLength++;

    // allocate memory for str
    str->letters = malloc(sizeof(letterLength));
    
    // error handling
    if (str->letters==NULL){ 
        perror("Allocation failed.");
        free(str->letters);
        return NULL;
    }

    // copy l into str->letters

    strcpy(str->letters,l);

    str->count = letterLength;
    str->capacity = letterLength+1;

    return str;
}


// add characters
void strAppend(String *s, char *x, int pos, bool Behind) {  

    // string capacity, vs (current size + size of string to be added)
    // bigger -> realloc and double mem, else -> proceed

    do{
        if (s->count >= s->capacity) { 
            if (s->capacity==0) s->capacity = 256;
            else s->capacity *= 2;
        
            // reallocate memory
            s->letters = realloc(s->letters, s->capacity*sizeof(*s->letters));
        }

    // 
    } while(0);
}

// remove a chunk from a string

void strRemoveChunk(String s, char *x, int pos, int chunkSize) {
    do {
        // look at pos, count chunk size
            // if chunk size at pos is less than the rest of the string
                // move everything after [pos, pos+chunkSize] "chunkSize" registers back

            // else ((chunkSize + pos) > s->capacity)
                // remove everything until the \0 terminator
                // move terminator to (pos + 1)

    } while(0);
}

void strDelete(String *s) {
    free(s->letters);
    free(s);
    s=NULL;
}

void strPrint(String *s) {

    printf("%s",s->letters);

}