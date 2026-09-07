#include <stdio.h>
#include <stdlib.h>
#include "string26.h"


typedef struct String {
    const char *letters;
    size_t count;
    size_t capacity;
} String;


// Make new string
String newStr(const char* l, size_t c, size_t s) {

    String *str = (String*)malloc(sizeof(String));
    str.letters = l;
    str.count = c;
    str.capacity = s;
    return str;

}

// Convert c string to regular string
String cStrToStr26(char * cs) {

    String newStr;
    newStr.letters = cs;
    newStr.count = sizeof(cs);
    
}


// add characters
void strAppend(String s, char *x, bool Behind) {  

    // string capacity, vs (current size + size of string to be added)
    // bigger -> realloc and double mem, else -> proceed

    do{
        if (s.count >= s.capacity) { 
        if (s.capacity==0) s.capacity = 256;
        else s.capacity *= 2;
        
        // reallocate memory
        s.items = realloc(s.items, s.capacity*sizeof(*s.items));
        }

    s.letters[s.count++] = x;
    } while(0)

}

void deleteStr(String *s) {
    free(s->data);
    free(s);
}