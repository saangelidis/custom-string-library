#include "string26.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // built on top of string.h


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

String *strRemoveChunk(String *s, size_t pos, size_t chunk) { // chunk is the range of elements to be deleted
    // if chunk size at pos is less than the rest of the string
    if (((pos + chunk) < s->capacity) && pos > 0) {
        
        // go to position   
        char *i = s->letters;


        // move everything after [pos, pos+chunkSize] "chunkSize" registers back
        
        
    }
    // if chunk size is greater than capacity
    else if (((pos + chunk) > s->capacity) && (pos == 0)) {
        strDelete(s);
    }   
    // else ((chunkSize + pos) >= s->capacity)
    else {
        s->letters[pos] = '\0';
        // 
        char *dest = NULL;
        // copy contents
        strcpy(dest, s->letters);
        
        strDelete(s);
        
        return newStr(dest);

    }
}

void strDelete(String *s) {
    free(s->letters);
    free(s);
    s=NULL;
    return s;
}

void strPrint(String *s) {

    printf("%s",s->letters);

}