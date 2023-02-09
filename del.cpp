#include "del.h"

void del::Deliting1 (array* L)
{
    array::position p = L->first(), q;

    while (p != L->end()) {
        q = L->next(p);
        while(q != L->end()) {
            if (*(L->retrieve(p)) == *(L->retrieve(q))) // перегрузка ==
                L->Delete(q);

            else q = L->next(q);
        }
        p = L->next(p);
    }
}

void del::Deliting2 (list* L)
{
    list::position p = L->first(), q;

    while (p != L->end()) {
        q = L->next(p);
        while(q != L->end()) {
            if (*(L->retrieve(p)) == *(L->retrieve(q))) // перегрузка ==
                q = L->Delete(q);

            else q = L->next(q);
        }
        p = L->next(p);
    }
}

void del::Deliting3 (linkedList2* L)
{
    linkedList2::position p = L->first(), q;

    while (p != L->End()) {
        q = L->next(p);
        while(q != L->End()) {
            if (*(L->retrieve(p)) == *(L->retrieve(q))) // перегрузка ==
                q = L->Delete(q);

            else q = L->next(q);
        }
        p = L->next(p);
    }
}

void del::Deliting4 (listOnCursors* L)
{
    array::position p = L->first(), q;

    while (p != L->end()) {
        q = L->next(p);
        while(q != L->end()) {
            if (*(L->retrieve(p)) == *(L->retrieve(q))) // перегрузка ==
                q = L->Delete(q);

            else q = L->next(q);
        }
        p = L->next(p);
    }
}