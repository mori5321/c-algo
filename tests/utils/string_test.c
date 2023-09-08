#include "../../lib/utils/string.h"
#include "../test_util.h"
#include <string.h>

void test_newString(TestState *t) {
    String *string = newString("hello");
    size_t length = 5;
    cexpect_size_t(string->length, length, t);

    char *str = "hello";
    cassert(strcmp(string->str, str) == 0, t);
    freeString(&string);
}

void test_freeString(TestState *t) {
    String *string = newString("hello");
    freeString(&string);
    cassert(string == NULL, t);
}

void string_tests(TestState *t) {
    test_newString(t);
    test_freeString(t);
}
