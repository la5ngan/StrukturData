#include "child.h"

adrChild allocate(string x)
{
    adrChild P = new elmChild;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void deallocate(adrChild &P)
{
    delete P;
}

void createList(listChild &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(listChild &L, adrChild P)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(listChild &L, adrChild P)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        prev(P) = last(L);
        prev(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(adrChild Prec, adrChild P)
{
    if (first(L) != NULL)
    {
        if (Prec == last(L))
        {
            insertLast(L,P);
        }
        else
        {
            prev(next(Prec)) = P;
            next(P) = next(Prec);
            prev(P) = Prec;
            next(Prec) = P;
        }
    }

}

void insertSort(listChild &L, adrChild P)
{
    if (first(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        if (info(P) <= info(first(L)))
        {
            insertFirst(L,P);
        }
        else if (info(P) > info(last(L)))
        {
            insertLast(L,P);
        }
        else
        {
            adrChild Q = first(L);
            while (info(P) > info(next(Q)))
            {
                Q = next(Q);
            }
            insertAfter(L, Q, P);
        }
    }
}

void deleteFirst(listChild &L)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        cout << "[-] Data not found.." << endl;
    } else if (first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        adrChild P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteLast(listChild &L)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        cout << " KOSONG! " << endl;
    } else if (first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        adrChild P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfter(listChild &L, adrChild Prec, adrChild &P)
{
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
    deallocate(P);
}

void deleteChild(listChild &L, adrChild &P)
{
    adrChild Q = first(L);
    if (P == first(L) && P == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    } else if (P == first(L))
    {
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    } else if (P == last(L)) {
        while (next(Q) != P) {
            Q = next(Q);
        }
        last(L) = Q;
        next(Q) = NULL;
        prev(P) = NULL;
    } else {
        while (next(Q) != P) {
            Q = next(Q);
        }
        next(Q) = next(P);
        prev(next(P)) = Q;
        prev(P) = NULL;
        next(P) = NULL;
    }

    deallocate(P);
}

void printInfo(listChild L)
{
    if (first(L) != NULL)
    {
        adrChild P = first(L);
        while (P != NULL) {
            cout << "-> " << info(P) << endl;
            P = next(P);
        }
    } else
    {

     cout << "[-] Data tidak ditemukan.." << endl;

    }
}

adrChild findElm(listChild L, string x)
{
    if (first(L) != NULL)
    {
        adrChild P = first(L);
        while (P != NULL && info(P) != x)
        {
            P = next(P);
        }
        return P;
    }
}
