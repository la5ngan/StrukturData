#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define Nil NULL
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef struct elmParent *adrParent;

struct infoParent
{
	string kode;
	string nama;
};

struct elmParent {
    infoParent info;
    adrParent next;
};

struct listParent {
    adrParent first;
};

adrParent allocate(infoParent x);
void deallocate(adrParent &P);
void createList(listParent &L);

// INSERT
void insertFirst(listParent &L, adrParent P);
void insertLast(listParent &L, adrParent P);
void insertAfter(listParent &L, adrParent Prec, adrParent P);

// DELETE
void deleteFirst(listParent &L, adrParent &P);
void deleteLast(listParent &L, adrParent &P);
void deleteAfter(listParent &L, adrParent Prec, adrParent &P);
void deleteParent(listParent &L, adrParent &P);

void printInfo(listParent L);
adrParent findElm(listParent L, infoParent x);



#endif // PARENT_H_INCLUDED
