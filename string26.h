#ifndef STRING26_H
#define STRING26_H
#endif

typedef struct String {
    const char **letters;
    size_t count;
    size_t capacity;
} String;

#define strAppend(s, x)\
   do{\
    if (s.count >= s.capacity) {\ 
        if (s.capacity==0) s.capacity = 256;\
        else s.capacity *= 2;\
        s.items = realloc(s.items, s.capacity*sizeof(*s.items));\
    }\
    s.letters[s.count++] = x;\
} while(0)
