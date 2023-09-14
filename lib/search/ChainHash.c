#include <stdio.h>
#include <stdlib.h>
#include "./Member.h"
#include "./ChainHash.h"

static int hash(int key, int size) {
    return key % size;
};

static void SetNode(Node *n, const Member *x, Node *next) {
    n->data = *x;
    n->next = next;
};

int Initialize(ChainHash *h, int size) {
    if ((h->table = calloc(size, sizeof(Node *))) == NULL) {
        h->size = 0;
        return 0;
    }

    h->size = size;
    for (int i = 0; i < size; i++) {
        h->table[i] = NULL;
    }

    return 1;
}

Node *Search(const ChainHash *h, const Member *x) {
    int key = hash(x->no, h->size);
    Node *p = h->table[key];

    while (p != NULL) {
        if (p->data.no == x->no)
            return p;

        p = p->next; 
    }

    return NULL;
}

int Add(ChainHash *h, const Member *x) {
    int key = hash(x->no, h->size);

    const Node *p = h->table[key];
    Node *temp;

    while (p != NULL) {
        if (p->data.no == x->no)
            return 1; // 追加失敗(登録済み)

        p = p->next;
    }

    if ((temp = calloc(1, sizeof(Node))) == NULL)
        return 2; // calloc失敗

    SetNode(temp, x, h->table[key]); // 新たなNodeChainをつくる。新しい値は先頭に。過去の値はnextに格納
    h->table[key] = temp; // リストの先頭を新たなNodeChainで更新
    return 0;
}

int Remove(ChainHash *h, const Member *x) {
    int key = hash(x->no, h->size);
    Node *p = h->table[key];
    Node **pp = &h->table[key];

    while (p != NULL) {
        if (p->data.no == x->no) {
            // Nextを現在NodeChainのpointerに付け替える
            *pp = p->next;
            free(p);
            return 0;
        }

        // 次のNodeChainを探索しにいく
        pp = &p->next;
        p = p->next;
    }

    return 1;
};

void Dump(const ChainHash *h) {
    for (int i = 0; i < h->size; i++) {
        Node *p = h->table[i];
        printf("%02d ", i);
        while (p != NULL) {
            printf("->%d (%s)", p->data.no, p->data.name);
            p = p->next;
        }
        putchar('\n');
    }
}

void Clear(ChainHash *h) {
    for (int i = 0; i < h->size; i++) {
        Node *p = h->table[i]; // 着目Node
        while (p != NULL) {
            Node *next = p->next;
            free(p); // 着目Nodeを解放
            p = next; // 後続Nodeに着目
        }
        h->table[i] = NULL; // 着目NodeをNULLに
    }
}

void Terminate(ChainHash *h) {
    Clear(h);
    free(h->table);
    h->size = 0;
}
