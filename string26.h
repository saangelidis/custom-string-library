#ifndef STRING_26
#define STRING_26

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct String {
    char *letters; // pointer to string's first letter
    size_t count;        // size 
    size_t capacity;     // for realloc
} String;

String *newStr(const char *l);

void strAppend(String *s, char* x, size_t pos);

String *strRemoveChunk(String *s, size_t pos, size_t chunkSize);

void strDelete(String *s);

void strPrint(String *s);

#endif
