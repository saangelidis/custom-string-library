#include "string26.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // built on top of string.h


// Make new string
String *newStr(const char* l) {
    
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

    // allocate memory for str
    str->letters = malloc(sizeof(letterLength));
    
    // error handling
    if (str->letters==NULL){ 
        perror("Allocation failed.");
        free(str->letters);
        return NULL;
    }

    // copy l into str->letters

    strcpy(str->letters,l);

    str->count = letterLength;
    str->capacity = letterLength+1;

    return str;
}


void testPoints(String *s) {

  char * tmp = s->letters;
  printf("fuck this shit %s \n", tmp);
  free(tmp);
}

// add characters
void strAppend(String *s, char *x, size_t pos) {  

    // string capacity, vs (current size + size of string to be added)
    // bigger -> realloc and double mem, else -> proceed
	
    	// size of string x
	  size_t lenx = sizeof(*x);
    	// Pointer to addy of s->letters because it (s->l) will be overrided
	  char* tmpLet = s->letters;
    
    // How to handle mem?
    // REALLOC if not enough memory
    if (s->count + lenx >= s->capacity) { 
        // if capacity is 0
        if (s->capacity <= 0) s->capacity = s->count + sizeof(*x); // if capacity is uninitialized, make it the size of the string + the chunk to be added
        // if it just don't fit x2 the size
        else s->capacity *= 2;
        
	      // size of final string
        size_t newSizeOfString = s->capacity*sizeof(s->letters);
	
	      // reallocate memory for letters of s
        s->letters = (char *) realloc(s->letters, newSizeOfString);
        if (s->letters == NULL){
          printf("MEMORY ALLOCATION ERROR");
          s->letters = NULL;
        }
    }
    
    // concatenate if pos is out of range
    if (pos >= s->count) {
	  // add the old letters
      strcat(s->letters, tmpLet);
      // remove null terminator
      // s->letters sizeof(s->letters)-1 = ' ';
      // add the new word x
      strcat(s->letters, x); // x adds the null terminator as well?
      strcat(s->letters, '\0');
    }
      
    else { 
    // move every element after pos, including the NULL terminator, "lenx" positions ahead	
	
    	// pointer to s->letters, for traversal
	char* tmpAddrS = s->letters;
	size_t count = 0;
	do {
      	// place the old letters until pos
	*tmpAddrS = *tmpLet;
	//s->letters++;
      	// go to next item
	count++;
	tmpLet++;
	tmpAddrS++;
     	} while (count<pos);
    	
	// copy rest of old letters to temp string
	char * remaining = NULL;
	strcpy(remaining, tmpLet);

      // place the new letters at pos
      do {
        *tmpAddrS = *x;
        pos++;
        x++;
	tmpAddrS++;
      } while (*x);
   
	// place the rest of the letters
 	do {
	*tmpAddrS = *remaining;
	remaining++;
	tmpAddrS++;
	} while (*remaining != '\0');
	
      	// free all defined inside else loop	
       	free(tmpAddrS);
	      tmpAddrS = NULL;
        free(remaining);
      	remaining = NULL;
      	free(tmpLet);
      	tmpLet = NULL;
	
	// update string size
      	s->count = sizeof(s->letters);
      }
     //deallocate x + pointers
    free(x);
    x = NULL;

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
	// free pointers
	//free(start);
	//free(end);
   

	//
	//
	// add possible memory reallocation here
	//
	//

       }

    // if pos is 0 & chunk size is greater than the actual string
    else if ((pos == 0) && ((pos + chunk) > s->count) ) {
        strDelete(s);
    }   
    // else ((chunkSize + pos) >= s->capacity)
    else if ((pos+chunk)> s->capacity) {
        
        char * tmp =  s->letters + pos;
	      *tmp = '\0';
  
    // get new size 
   	free(tmp);
    }
    size_t size = 0;
    size = s->count - chunk;
    s->count = size;

}

void strDelete(String *s) {
    free(s->letters);
    free(s);
    s=NULL;
}

void strPrint(String *s) {
    printf("%s",s->letters);
}
