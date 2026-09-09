#include <stdio.h>
#include <stdlib.h>
#include "string26.h"


typedef struct String {
    const char *letters;
    size_t count;
    size_t capacity;
} String;


// Make new string
String newStr(const char* l) {

    String *str = (String*)malloc(sizeof(String));

    // assign head pointer to letter var
    str->letters = l;

    // define size of string (i.e. abc is:  [a, b, c, \0,] )
    
    size_t c = sizeof(*str->letters);

    str->count = c;
    str->capacity = c;

    return *str;

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

void strRemoveChunk(String s, char *x, int pos, int chunkSize)
{
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
}

void strPrint(String *s) {
    printf("%s",s->letters);
}