#ifndef INC_1LAB_LISTONCURSORS_H
#define INC_1LAB_LISTONCURSORS_H
#include "NodeForCursors.h"

#include <iostream>
#include <fstream>

            // СПИСОК НА КУРСОРАХ

struct resultIsUndefineD : public std::exception {
    [[nodiscard]] const char* what() const noexcept override
    {
        std::cout << std::endl << std::endl;
        return "!! результат не определен !!";
    }
};

class listOnCursors {
public:
    typedef int position; // псевдоним для int position

private:
    static inline NodeForCursors* array[26]{}; // список пустых
    static inline position space = 0; // точка входа в список пустых

    position heaD = 0;

private:
    // возвращает элемент до p или же 0 - если такой позиции нет
    position findPosition(position p) const;

    // возвращает позицию последнего элемента списка
    position findLast() const;

    // взять память из списка пустых
    position takeMemory();

    // добавляет узел в список пустых
    void giveMemory(position node);

public:
    explicit listOnCursors(std::ifstream &in); // конструктор - создание списка пустых

    ~listOnCursors();

    static void constructor(); // создание списка пустых

    void insert(object* x, position p); // в position p вставить x

    listOnCursors::position Delete(position p); // удаление элемента в position p, возвращает p, если такой позиции нет

    position locate(object* x) const; // возвращает position первого вхождения x

    object* retrieve(position p); // возвращает объект в position p

    position next(position p); // получить position, следующую за p

    static position end(); // возвращает position после последнего

    position previous(position p); // получить position перед p

    void makeNull(); // делает М пустым ( не содержащим элементов ).

    position first() const ; // возвращает position head. Если список пустой, то возвращает 0

    void printList() const; // выводит на экран.
};


#endif //INC_1LAB_LISTONCURSORS_H
