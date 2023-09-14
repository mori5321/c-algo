#include <stdio.h>
#include "../lib/search/Member.h"
#include "../lib/search/ClosedHash.h"

typedef enum {
    TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

Menu SelectMenu(void) {
    int ch;
    do {
        printf("1. Add, 2. Delete, 3. Search, 4. Clear, 5. Dump, 0. Terminate: ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > DUMP);

    return (Menu)ch;
}

int main(void) {
    Menu menu;
    ClosedHash hash;
    ClosedHash_Initialize(&hash, 13);
    do {
        int result;
        Member x;
        Bucket *temp;
        switch (menu = SelectMenu()) {
            case ADD:
                x = ScanMember("Add", MEMBER_NO | MEMBER_NAME);
                result = ClosedHash_Add(&hash, &x);

                break;
            case DELETE:
                x = ScanMember("Delete", MEMBER_NO);
                result = ClosedHash_Remove(&hash, &x);
                if (result == 1)
                    puts("該当データはありません。");

                break;
            case SEARCH:
                x = ScanMember("Search", MEMBER_NO);
                temp = ClosedHash_Search(&hash, &x);
                if (temp != NULL) {
                    printf("該当データは以下の通りです。\n");
                    PrintLnMember(&temp->data);
                } else {
                    puts("該当データはありません。");
                }

                break;
            case CLEAR:
                ClosedHash_Clear(&hash);

                break;
            case DUMP:
                ClosedHash_Dump(&hash);

                break;
            case TERMINATE:
                break;
        }
    } while (menu != TERMINATE);
    ClosedHash_Terminate(&hash);
    return 0;
}
