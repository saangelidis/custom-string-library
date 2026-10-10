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
  	printf("String->count: %u \n", s->count);
	printf("String->capacity: %u\n",s->capacity);
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

    	size_t xLength = strLen(x);    // size of string x including '\0' null terminator
 	char * tmpLet = s->letters;  // pointer to the first letter of string
	
	// Memory check
    	//
    	// REALLOC if not enough memory
	if (s->count + xLength >= s->capacity) { 
        	s->capacity = s->count + xLength-1;
		// reallocate memory for letters of s
	        s->letters = (char *) realloc(s->letters, s->capacity);
        
		// if memory allocation failed
		if (s->letters == NULL) {
        	 	printf("MEMORY ALLOCATION ERROR");
          		s->letters = NULL;
        	}
	 }	

   	char * traverser = s->letters; // pointer to first byte of allocated mem
				
	if (pos < 0) pos = s->capacity - pos;

	// Addition handling 
	//
    	// CONCATENATE if pos is out of range
    	if (pos >= s->count) {
		// add the old letters WITHOUT terminator
		while (*tmpLet != '\0') {
			*traverser = *tmpLet;	
			tmpLet++;
			traverser++;
		}

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

		while (count<pos) {
      			// place the old letters until pos
			*traverser = *tmpLet;
	
      			// go to next item
			count++;
			tmpLet++;
			traverser++;
	     	}
	
		count = 0;

    		char * remaining = (char *) malloc(strLen(tmpLet));
	
		// copy rest of old letters to temp string
		while(*tmpLet != '\0') {
			*remaining = *tmpLet;
			remaining++;
			tmpLet++;
			count++;
		}
	
		remaining = remaining - count;
	
	      	// place the new letters at pos
      		while (*x != '\0') {
			*traverser = *x;
	        	x++;
			traverser++;
	      	} 
   		count = 0;
		// place the rest of the letters
	 	while (*remaining != '\0') {
			*traverser = *remaining;
			remaining++;
			traverser++;
			count++;
		}
	
		// place terminator
		*traverser = '\0';
		remaining = remaining - count;
       		free(remaining); 
	} 

	// update string size
	s->count = strLen(s->letters);
	
} 

// remove a chunk from a string
void strRemoveChunk(String *s, size_t pos, size_t chunk) { // chunk is the range of elements to be deleted
    
    // CHECK if pos negative, pos = s->capacity - pos
    if (pos < 0) pos = s->capacity-pos;

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
