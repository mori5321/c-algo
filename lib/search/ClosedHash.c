#include <stdio.h>
#include <stdlib.h>
#include "./Member.h"
#include "./ClosedHash.h"

static int hash(int key, int size) {
    return key % size;
}

static int rehash(int key, int size) {
    return (key + 1) % size;
}

static void SetBucket(Bucket *n, const Member *x, Status stat) {
    n->data = *x;
    n->stat = stat;
}

int ClosedHash_Initialize(ClosedHash *h, int size) {
    if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {
        h->size = 0;
        return 0;
    }

    h->size = size;
    for (int i = 0; i < size; i++) {
        h->table[i].stat = Empty;
    }

    return 1;
}

Bucket *ClosedHash_Search(const ClosedHash *h, const Member *x) {
    int key = hash(x->no, h->size);
    Bucket *b = &h->table[key];

    // Empty なら xは存在しない
    // Occupied かつ一致ならばxは探索成功
    // Occupied or Deletedかつ一致しないならば再度ハッシュ(次のBucketを見にいく)
    for (int i = 0; b->stat != Empty && i < h->size; i++) {
        if (b->stat == Occupied && b->data.no == x->no) {
            return b;
        }

        key = rehash(key, h->size);
        b = &h->table[key];
    }

    return NULL;
}

int ClosedHash_Add(ClosedHash *h, const Member *x) {
    int key = hash(x->no, h->size);
    Bucket *p = &h->table[key];

    if (ClosedHash_Search(h, x)) { // xはすでに存在している
        return 1;
    }

    for (int i = 0; i < h->size; i++) {
        if (p->stat == Empty || p->stat == Deleted) {
            SetBucket(p, x, Occupied);
            return 0;
        }
        key = rehash(key, h->size); // rehash
        p = &h->table[key];
    }

    return 2; // ハッシュが満杯でrehash失敗
}

int ClosedHash_Remove(ClosedHash *h, const Member *x) {
    Bucket *p = ClosedHash_Search(h, x);

    if (p == NULL)
        return 1;

    p->stat = Deleted;

    return 0;
}

void ClosedHash_Dump(const ClosedHash *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%02d : ", i);
        switch (h->table[i].stat) {
            case Occupied  : printf("%d (%s)\n", h->table[i].data.no, h->table[i].data.name);
                             break;
            case Empty:
                             printf("Empty\n"); break;
            case Deleted:
                             printf("Deleted\n"); break;
        }
    }
}

void ClosedHash_Clear(ClosedHash *h) {
    for (int i = 0; i < h->size; i++) {
        h->table[i].stat = Empty;
    }
}

void ClosedHash_Terminate(ClosedHash *h) {
    ClosedHash_Clear(h);
    free(h->table);
    h->size = 0;
};
