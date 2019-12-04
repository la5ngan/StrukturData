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
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev

typedef struct elmChild *adrChild;

struct elmChild {
	string info;
	adrChild next;
	adrChild prev;
};

struct listChild {
	adrChild first;
	adrChild last;
};

adrChild allocate(string x);
void deallocate(adrChild &P);
void createList(listChild &L);

// INSERT
void insertFirst(listChild &L, adrChild P);
void insertLast(listChild &L, adrChild P);
void insertAfter(adrChild Prec, adrChild P);
void insertSort(listChild &L, adrChild P);

// DELETE
void deleteFirst(listChild &L);
void deleteLast(listChild &L);
void deleteAfter(listChild &L, adrChild Prec, adrChild &P);
void deleteChild(listChild &L, adrChild &P);

void printInfo(listChild L);
adrChild findElm(listChild L, string x);



#endif // CHILD_H_INCLUDED
