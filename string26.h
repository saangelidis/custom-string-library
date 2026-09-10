#ifndef STRING_26
#define STRING_26

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct String {
    char *letters; // pointer to string's first letter
    size_t count;        // how m
    size_t capacity;     //
} String;

String *newStr(const char *l);

void strAppend(String *s, char* x, int pos, bool Behind);

void strRemoveChunk(String s, char *x, int pos, int chunkSize);

void strDelete(String *s);

void strPrint(String *s);

#endif