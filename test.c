#include <stdio.h>
#include <stdlib.h>
#include "string26.h"

typedef struct String {
    const char **letters;
    size_t count;
    size_t capacity;
} String;

#define strAppend(s, x)\
   do{\
    if (s.count >= s.capacity) {\ 
        if (s.capacity==0) s.capacity = 256;\
        else s.capacity *= 2;\
        s.items = realloc(s.items, s.capacity*sizeof(*s.items));\
    }\
    s.letters[s.count++] = x;\
} while(0)


int main () {

    char fkst[20] = "making me suffer!"
    printf("This project is %s",fkst)
    
    return 0;
}