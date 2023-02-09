#ifndef INC_1LAB_NODE2_H
#define INC_1LAB_NODE2_H
#include "object.h"

struct Node1 {

    Node1* next{}; // ссылка на следующий
    struct object obj; // имя и адрес

    // создание узла
    Node1 (char n[20], char a[50])
    {
        strcpy(this->obj.name, n);
        strcpy(this->obj.adress, a);

        this->next = nullptr;
    }
};
#endif //INC_1LAB_NODE2_H
