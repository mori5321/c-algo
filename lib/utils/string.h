#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

typedef struct {
    char *str;
    size_t length;
} String;

String* newString(const char* str);

void freeString(String **s);

#endif
