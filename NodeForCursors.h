#ifndef INC_1LAB_NODEFORCURSORS_H
#define INC_1LAB_NODEFORCURSORS_H
#include "object.h"

 struct NodeForCursors {

    int next{}; // номер следующего элемента
    struct object obj; // имя и адрес

    // создание узла
    NodeForCursors (char n[20], char a[50])
    {
        if (n && a) { // если не nullptr
            strcpy(this->obj.name, n);
            strcpy(this->obj.adress,a);
        }

        this->next = 0;
    }
};

#endif //INC_1LAB_NODEFORCURSORS_H
