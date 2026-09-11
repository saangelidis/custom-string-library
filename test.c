#include <stdio.h>
#include <stdlib.h>
#include "string26.h"

int main () {


    String *DS = newStr("listening");

    printf("The string is %s, its size is %zu, and its capacity is %zu\n", DS->letters,DS->count,DS->capacity);
    
    DS = strRemoveChunk(DS, 6, 3);

    printf("After chunk removal, The string is %s, its size is %zu, and its capacity is %zu\n", DS->letters,DS->count,DS->capacity);
        
    return 0;
}