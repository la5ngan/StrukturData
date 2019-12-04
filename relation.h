#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include "child.h"
#include "parent.h"
#include <iostream>

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

using namespace std;

typedef struct elmRelation *adrRelation;

struct elmRelation
{
    adrRelation next;
    adrChild child;
    adrParent parent;
};

struct listRelation
{
    adrRelation first;
};


void createList(listRelation &L);
void insertFirst(listRelation &L, adrRelation P);
void insertLast(listRelation &L, adrRelation P);
void deleteFirst(listRelation &L, adrRelation P);
void deleteLast(listRelation &L, adrRelation &P);
void deallocate(adrRelation &P);
void printInfo(listRelation L);
adrRelation findParentRel(listRelation L, adrParent Q);
adrRelation findChildRel(listRelation L, adrChild Q);

#endif // RELATION_H_INCLUDED
