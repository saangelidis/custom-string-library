#ifndef STRING_26
#define STRING_26

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct String String;

String *newStr(const char *l);

void strAppend(String *s, char* x, int pos, bool Behind);

void strRemoveChunk(String s, char *x, int pos, int chunkSize);

void strDelete(String *s);

void strPrint(String *s);

#endif