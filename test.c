#include <stdio.h>
#include <stdlib.h>
#include "string26.h"

int main () {


    String *DS = newStr("listening");
    

    printf("The string is %s, its size is %zu, and its capacity is %zu\n", DS->letters,DS->count,DS->capacity);
    return 0;
}