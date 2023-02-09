#include "list.h" //1
#include "array.h" //2
#include "linkedList2.h" //3
#include "listOnCursors.h" //4

#include "del.h"

int main() {
    setlocale(LC_ALL, "RUS");
    std::ifstream in ("input.txt");

    int m; // какой АТД
    in >> m;

    // 1 - array,   2 - list1,   3 - 2linked list,    4 - list on cursors
    if (m == 1) {
            array A = array(in);
            del::Deliting1(&A);

            std::cout << "array: ";
            A.printList();

    }   else if (m == 2) {
            list L = list(in);
            del::Deliting2(&L);

            std::cout << "1 linked list: ";
            L.printList();

    }   else if (m == 3) {
            linkedList2 L2 = linkedList2(in);
            del::Deliting3(&L2);

            std::cout << "2 linked list: ";
            L2.printList();

    }   else if (m == 4) {
            listOnCursors::constructor(); // список пустых создаем

            listOnCursors L3 = listOnCursors(in);
            del::Deliting4(&L3);

            std::cout << "list on cursors: ";
            L3.printList();
    }

    return 0;
}
