#ifndef INC_1LAB_OBJECT_H
#define INC_1LAB_OBJECT_H
#include <cstring>

struct object {
    char name[20]{};
    char adress[50]{};

    friend bool operator== (object& first, object& second) { // перегрузка оператора ==
        size_t f = strlen(first.name);
        size_t s = strlen(second.name);

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < s; ++j) {
                if (first.name[i] != second.name[j])
                    return false;
                else ++i;
            }
        }
        return true;
    };

    object& operator= (object* second) { // перегрузка оператора ==
        strcpy(this->name, second->name);
        strcpy(this->adress, second->adress);

        return *this;
    }
};

#endif //INC_1LAB_OBJECT_H
