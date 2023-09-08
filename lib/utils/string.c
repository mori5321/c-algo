#include "./string.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


String* newString(const char* str) {
    String *string = malloc(sizeof(String)); // 構造体のメモリを確保
    string->length = strlen(str);
    string->str = malloc(sizeof(char) * (string->length + 1)); // 文字列のメモリを確保
    strcpy(string->str, str);
    return string;
}

void freeString(String **string) {
    if (*string == NULL) {
        return;
    } 

    if ((*string)->str != NULL) {
        free((*string)->str);
        (*string)->str = NULL;
    }

    free(*string);
    *string = NULL;
}

