#include "relation.h"
#include "child.h"
#include "parent.h"

void createList(listRelation &L)
{
    first(L) = NULL;
}

void insertFirst(listRelation &L, adrRelation P)
{
    if (firt(L) == NULL)
    {
        first(L) = P;
        next(P) = first(L)
    } else
    {
        adrRelation Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;

    }
}

void insertLast(listRelation &L, adrRelation P)
{
    if (first(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        adrRelation Q = first(L);
        while (next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
    }
}

void deleteFirst(listRelation &L, adrRelation P)
{
    if (first(L) != NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(listRelation &L, adrRelation &P)
{
    if (first(L) != NULL)
    {
        P = first(L);
        if (next(P) == NULL)
        {
            deleteFirst(L,P);
        }
        else
        {
            while (next(next(P)) != NULL)
            {
                P = next(P);
            }
            adrRelation Q = P;
            P = next(Q);
            next(Q) = NULL;
        }
    }

}

void deallocate(adrRelation &P)
{
    delete P;
}
void printInfo(listRel L)
{
    if (first(L) != NULL) {
        adrRelation P = first(L);
        while (next(P) != first(L))
        {
            cout << "-> [ " << info(parent(P)).kode << " | " << info(parent(P)).nama << " ] <---> " << info(child(P)) << endl;
            P = next(P);
        }
        cout << "-> [ " << info(parent(P)).kode << " | " << info(parent(P)).nama << " ] <---> " << info(child(P)) << endl;
    }
    else
    {
        cout << "[-] Data tidak ditemukan.." << endl;
    }
}

adrRelation findParentRel(listRelation L, adrParent Q)
{
    adrRelation P = first(L);
    if (first(L) != NULL)
    {
        while (next(P) != first(L))
        {
            if (info(parent(P)).kode == info(Q).kode
            {
                return P;
                break;
            }
            P = next(P);
        }

        if (info(parent(P)).kode == info(Q).kode)
        {
            return P;
        }
        else return NULL;
    } else return NULL;
}

adrRelation findChildRel(listRelation L, adrChild Q)
{
    adrRelation P = first(L);
    if (first(L) != NULL)
    {
        while (next(P) != first(L))
        {
            if (info(child(P)) == info(Q))
            {
                return P;
                break;
            }
            P = next(P);
        }

        if (info(child(P)) == info(Q)
        {
            return P
        }
        else return NULL;
    } else return NULL;
}
