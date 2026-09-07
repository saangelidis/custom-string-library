#ifndef STRING_26
#define STRING_26

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct String String;

String newStr(const char* l, size_t c, size_t s);

String cStrToStr26(char * cs);

void strAppend(String *s, char* x);

void deleteStr(String *s);


#endif