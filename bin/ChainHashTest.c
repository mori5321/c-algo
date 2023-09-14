#include <stdio.h>
#include "../lib/search/Member.h"
#include "../lib/search/ChainHash.h"

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
    ChainHash hash;
    Initialize(&hash, 13);
    do {
        int result;
        Member x;
        Node *temp;
        switch (menu = SelectMenu()) {
            case ADD:
                x = ScanMember("Add", MEMBER_NO | MEMBER_NAME);
                result = Add(&hash, &x);

                break;
            case DELETE:
                x = ScanMember("Delete", MEMBER_NO);
                result = Remove(&hash, &x);
                if (result == 1)
                    puts("該当データはありません。");

                break;
            case SEARCH:
                x = ScanMember("Search", MEMBER_NO);
                temp = Search(&hash, &x);
                if (temp != NULL) {
                    printf("該当データは以下の通りです。\n");
                    PrintLnMember(&temp->data);
                } else {
                    puts("該当データはありません。");
                }

                break;
            case CLEAR:
                Clear(&hash);

                break;
            case DUMP:
                Dump(&hash);

                break;
            case TERMINATE:
                break;
        }
    } while (menu != TERMINATE);
    Terminate(&hash);
    return 0;
}
