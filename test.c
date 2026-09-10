#include <stdio.h>
#include <stdlib.h>
#include "string26.h"

int main () {

    char test[] = "dead";
    printf("Old string: %s", test);

    char *ptr = test;

    String *DS = newStr(ptr);

    return 0;
}