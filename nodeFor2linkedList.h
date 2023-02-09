#ifndef INC_1LAB_NODEFOR2LINKEDLIST_H
#define INC_1LAB_NODEFOR2LINKEDLIST_H
#include "object.h"

struct nodeFor2link {

    nodeFor2link* next{}; // ссылка на следующий
    nodeFor2link* prev{}; // ссылка на предыдущий
    struct object obj; // имя и адрес

    // создание узла
    nodeFor2link (char n[20], char a[50])
    {
        strcpy(this->obj.name, n);
        strcpy(this->obj.adress, a);

        this->prev = nullptr;
        this->next = nullptr;
    }
};

#endif //INC_1LAB_NODEFOR2LINKEDLIST_H
