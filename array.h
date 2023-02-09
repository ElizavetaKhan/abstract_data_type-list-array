#ifndef INC_1LAB_ARRAY_H
#define INC_1LAB_ARRAY_H
#include "Node.h"

#include <iostream>
#include <fstream>

            // СПИСОК НА МАССИВЕ

struct resultisUndefined : public std::exception {
    [[nodiscard]] const char* what() const noexcept override
    {
        std::cout << std::endl << std::endl;
        return "!! результат не определен !!";
    }
};

class array {
public:
    typedef int position; // псевдоним для int position

private:
    position last = -1;
    Node* A[20]{};

public:
    explicit array (std::ifstream& in); // конструктор

    ~array();

    void destruct();

    void insert(object& x, position p); // в массив в position p вставить x

    position end() const; // возвращает position после последнего

    position locate(object& x); // возвращает position первого вхождения x в массиве A

    object& retrieve(position p); // возвращает объект в position p

    position next(position p) const ; // получить position, следующую за p в массиве A

    static position previous(position p); // получить position, предыдущую position p в массиве A

    void Delete(position p); // удаление элемента из массива A в position p

    void makeNull(); // делает массив А пустым ( не содержащим элементов ).

    position first() const ; // возвращает position первого элемента массива. Если массив пустой, то возвращает end(А).

    void printList(); // выводит массив на экран.

};

#endif //INC_1LAB_ARRAY_H
