#include <stdio.h>
#include <stdlib.h>
#include "string26.h"

int main () {

	String *DS = newStr("listening");

	printf("Initial string: \n");
	stringInfo(DS);

     	// test remove
	strRemoveChunk(DS, 4, 2);

	printf("\nPost first chunk removal: \n");
	stringInfo(DS);
    	
	// test remove
	strRemoveChunk(DS, 4, 1000);
	
	printf("\nPost second chunk removal: \n");
	stringInfo(DS);
    



    	String *newTest = newStr("fun");	
	printf("\nNew string: \n");
	stringInfo(newTest);

	// test concat function 
    	strAppend(newTest, " shit!",1000);
	printf("\nNew string after first append:\n");
	stringInfo(newTest);

    	// test inside part
    	strAppend(newTest, "cki",2);
    	printf("\nNew string after second append:\n");
	stringInfo(newTest);
    
	// test delete
    	strDelete(DS);
    	printf("After deletion: %s\n",DS->letters); // should cause segfault
    	return 0;
}
