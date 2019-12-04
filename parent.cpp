#include "parent.h"

adrParent allocate(infoParent x)
{
    adrParent P;
    P = new elmParent;
    info(P) = x;
    next(P) = NULL;
    return P;
}



void deallocate(adrParent &P)
{
    delete P;
}

void createList(listParent &L)
{
    first(L) = NULL;
}

void insertFirst(listParent &L, adrParent P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(listParent &L, adrParent P) {
    if (first(L) == NULL)
    {
        insertFirst(L, P);
    }
    else
    {
        adrParent Q = first(L);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter(listParent &L, adrParent Prec, adrParent P)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteFirst(listParent &L, adrParent &P)
{
    if (first(L) != NULL)
    {
        if (next(first(L)) == NULL)
        {
            P = first(L);
            first(L) = NULL;
        }
        else
        {
            P = first(L);
            first(L) = next(first(L));
            next(P) = NULL;
        }
    }

    deallocate(P);
}

void deleteLast(listParent &L, adrParent &P)
{
    if (first(L) != NULL) {
        if (next(first(L)) == NULL) {
            P = first(L);
            first(L) = NULL;
        }
        else
        {
            adrParent Q = L.first;
            while (next(next(Q)) != NULL)
            {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
    }

    deallocate(P);
}

void deleteAfter(listParent &L, adrParent Prec, adrParent &P)
{
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;

    deallocate(P);
}

void deleteParent(listParent &L, adrParent &P)
{
    if (first(L) != P)
    {
        adrParent X = first(L);
        while (next(X) != NULL && next(X) != P) {
            X = next(X);
        }

        next(X) = next(P);
        next(P) = NULL;
        deallocate(P);
    }
    else
    {
      deleteFirst(L, P);
    }
}

void printInfo(listParent L)
{
    if (first(L) == NULL)
    {
        cout << "[-] Data tidak ditemukan.." << endl;
    }
    else
    {
        adrParent P = first(L);
        while (P != NULL)
        {
            cout << "-> " << info(P).kode << endl;
            P = next(P);
        }
    }
}

adrParent findElm(listParent L, string x)
{
    adrParent P;
    if (first(L) != NULL)
    {
        P = first(L);
        while (next(P) != first(L) && info(P).kode != x.kode)
        {
            P = next(P);
        }
        if (info(P).kode = x.kode)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
}
