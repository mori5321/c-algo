#ifndef __CLOSEDHASH_H
#define __CLOSEDHASH_H

#include "./Member.h"

typedef enum {
    Occupied, Empty, Deleted
} Status;

typedef struct {
    Member data;
    Status stat;
} Bucket;

typedef struct {
    int size;
    Bucket *table;
} ClosedHash;

int ClosedHash_Initialize(ClosedHash *h, int size);

Bucket *ClosedHash_Search(const ClosedHash *h, const Member *x);

int ClosedHash_Add(ClosedHash *h, const Member *x);

int ClosedHash_Remove(ClosedHash *h, const Member *x);

void ClosedHash_Dump(const ClosedHash *h);

void ClosedHash_Clear(ClosedHash *h);

void ClosedHash_Terminate(ClosedHash *h);


#endif
