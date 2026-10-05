#include <stdio.h>
#include <stdlib.h>
#include "string26.h"

int main () {


    String *DS = newStr("listening");

    printf("The string is %s, its size is %zu, and its capacity is %zu\n", DS->letters,DS->count,DS->capacity);
    
    //    DS = strRemoveChunk(DS, 6, 3);

    // printf("After chunk removal, The string is %s, its size is %zu, and its capacity is %zu\n", DS->letters,DS->count,DS->capacity);
    
        String *newTest = newStr("fun");
    
    printf("The string before adding letters is: %s",newTest->letters);
    
    // passing a string pointer, a string
    strAppend(newTest, "cki",2);

    printf("The string after the append is: %s", newTest->letters);
    

    strDelete(DS);
    
    printf("After deletion: %s\n",DS->letters);


    return 0;
}
