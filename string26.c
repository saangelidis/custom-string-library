#include "string26.h"
#include <stdio.h>
#include <stdlib.h>

// Make new string
String *newStr(char* l) {
    
    	// allocate memory the size of a string struct
    	String *str = malloc(sizeof(*str));
    
    	// error handling
    	if (str==NULL){ 
        	perror("Allocation failed.");
        	free(str);
        	return NULL;
    	}
    
	// initialize var to get string size
    	size_t letterLength = 0;

    	// get string size
	while (l[letterLength] != '\0') letterLength++;
		letterLength++;
	    	// allocate memory for str
	    	str->letters = malloc(letterLength);
    
	// error handling
	if (str->letters==NULL){ 
        	perror("Allocation failed.");
	        free(str->letters);
        	return NULL;
    	}

    	// copy l into str->letters
	
	char* tmp  = str->letters;
	bool finish = false;
	
	while (!finish) {
		// 
		*tmp = *l;
        	if (*l=='\0') finish = true;
		tmp++;
		l++;
        }

    	str->count = letterLength;
    	str->capacity = letterLength;

    	return str;
}


void stringInfo(String *s) {
	printf("String->letters:  %s \n",s->letters);
  	printf("String->count: %zu \n", s->count);
	printf("String->capacity: %zu\n",s->capacity);
}

size_t strLen(char * x) {
// FUTURE: implement bool variable to include or not include NULL term
	size_t length = 0;
	do {
		length++;
		x++;
	} while (*x != '\0');
	length++;
	
	return length;
}

// add characters
void strAppend(String *s, char *x, size_t pos) {  

    	size_t xLength = strLen(x)-1;     // size of x without terminator
 		
	// Memory check
    	//
    	// REALLOC if not enough memory
	if (s->count + xLength >= s->capacity) { 
        	s->capacity = s->count + xLength;
		
		// reallocate memory for letters of s
		char * tmp = realloc(s->letters, s->capacity);
		
		// if memory allocation failed
		if (tmp == NULL) {
        	 	perror("MEMORY ALLOCATION ERROR");
			return;
        	}
		s->letters = tmp;
	 }	
	
	// Addition handling 
	//
    	// CONCATENATE if pos is out of range
    	if (pos >= s->count) {
		pos = s->count-1;	
		char * traverser = s->letters + pos; // pointer to letter at pos	
		
		// add the new word x WITHOUT terminator
		while (*x != '\0') {
			*traverser = *x;
			x++;
			traverser++;	
		}
	*traverser = '\0';	
	}
   	
	// POSITIONAL ADD if pos is in range
    	else { 
    	// move every element after pos, including the NULL terminator, "lenx" positions ahead	
    		size_t count = 0;
		char * traverser = s->letters + pos; // pointer to letter at pos
    		char * remaining = (char *) malloc(strLen(traverser));
	
		// copy rest of old letters to temp string
		while(*traverser != '\0') {
			*remaining = *traverser;
			printf("letter copied to remaining: %c\n",*remaining);
			remaining++;
			traverser++;
			count++;
		}
		size_t remainingCount = count;
		remaining = remaining - count;
		traverser = traverser - count;
	      	
		// place the new letters at pos
      		while (*x != '\0') {
			*traverser = *x;
	        	printf("letter copied to traverser: %c\n",*traverser);
			x++;
			traverser++;
	      	} 
   		count = 0;
		// place the rest of the letters
	 	while (count<remainingCount) {
			*traverser = *remaining;
			printf("letter copied to traverser: %c\n",*traverser);
			remaining++;
			traverser++;
			count++;
		}
	
		// place terminator
		*traverser = '\0';
		remaining = remaining - remainingCount;
       		free(remaining); 
	} 

	// update string size
	s->count = strLen(s->letters);
} 

// remove a chunk from a string
void strRemoveChunk(String *s, size_t pos, size_t chunk) { // chunk is the range of elements to be deleted


    // CHECK if chunk size at pos is less than the rest of the string
    //
    // AKA - is the chunk smaller than the word & is pos bigger than 0
    if (((pos + chunk) < s->capacity) && pos > 0) {

        // new pointer to letters
        char* start  = s->letters + pos;         // points to (s->letters)[pos]
	char* end    = s->letters + pos + chunk; // points to end of pos+chunk

	// move everything after [pos, pos+chunk] "chunk" registers back
	// (s->letters)[pos] = (s->letters)[pos+chunk]
        bool finish = false;
	while (!finish) {
		// 
		*start = *end;
        	if (*end=='\0') finish = true;
		start++;
		end++;
        };
	// FUTURE: could add possible memory reallocation here if we need to conserve mem.
  
    }

    // if pos is 0 & chunk size is greater than the actual string
    else if ((pos == 0) && (chunk > s->count)) {
        strDelete(s);
    }   
    // else ((chunkSize + pos) >= s->capacity)
    else if ((pos+chunk)> s->capacity) {
        
         char * tmp =  s->letters + pos;
	 *tmp = '\0';
  
    }
    
    s->count = strLen(s->letters);
}

void strDelete(String *s) {
    free(s->letters);
    free(s);
    s=NULL;
}

void strPrint(String *s) {
   printf("%s",s->letters); 
}
