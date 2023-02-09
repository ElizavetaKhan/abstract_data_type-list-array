#ifndef INC_1LAB_LINKEDLIST2_H
#define INC_1LAB_LINKEDLIST2_H
#include "nodeFor2linkedList.h"
#include <cstring>

#include <iostream>
#include <fstream>

            // СПИСОК НА ДВУСВЯЗНОМ СПИСКЕ

struct resultIsundefined : public std::exception {
    [[nodiscard]] const char* what() const noexcept override
    {
        std::cout << std::endl << std::endl;
        return "!! результат не определен !!";
    }
};

class linkedList2 {
public:
    typedef nodeFor2link* position; // псевдоним для Node* position

private:
    position start = nullptr;
    position end = nullptr;

private:
    bool findPosition(position p); // возвращает true - если есть такой элемент, иначе false

public:
    explicit linkedList2 (std::ifstream& in); // конструктор с одним параметром

    ~linkedList2(); // вызывает destruct()

    void destruct(); // удаляет все new Node

    void insert(object* x, position p); // в список в position p вставить объект х

    position locate(object* x); // возвращает position первого вхождения x в списке L

    object* retrieve(position p); // возвращает объект в position p

    position next(position p); // получить position, следующую за p в списке L

    position previous(position p); // получить position, предыдущую position p в списке L

    position Delete(position p); // удаление элемента из списка L в position p

    void makeNull(); // делает список L пустым ( не содержащим элементов ) - вызов destruct

    position first(); // возвращает position первого элемента списка - start

    static position End() ; // возвращает position после последнего - end->next

    void printList(); // выводит список на экран

};


#endif //INC_1LAB_LINKEDLIST2_H
