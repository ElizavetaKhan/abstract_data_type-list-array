#ifndef INC_1LAB_NODE_H
#define INC_1LAB_NODE_H
#include "object.h"

struct Node {

    struct object obj; // имя и адрес

    // создание узла
    Node (char n[20], char a[50])
    {
        strcpy(this->obj.name, n);
        strcpy(this->obj.adress, a);
    }
};

#endif //INC_1LAB_NODE_H
