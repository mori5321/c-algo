#ifndef __CHAIN_HASH_H__
#define __CHAIN_HASH_H__

#include "Member.h"

typedef struct __node {
    Member data;
    struct __node *next;
} Node;

typedef struct {
    int size;
    Node **table;
} ChainHash;

int ChainHash_Initialize(ChainHash *h, int size);

Node *ChainHash_Search(const ChainHash *h, const Member *x);

int ChainHash_Add(ChainHash *h, const Member *x);

int ChainHash_Remove(ChainHash *h, const Member *x);

void ChainHash_Dump(const ChainHash *h);

void ChainHash_Clear(ChainHash *h);

void ChainHash_Terminate(ChainHash *h);

#endif 
