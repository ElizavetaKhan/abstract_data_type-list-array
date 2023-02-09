#include "array.h"

array::array(std::ifstream& in)
{
    char n[20], a[50];

    while (!in.eof()) {
        in >> n >> a;
        Node* node = new Node(n,a); // создаем узел с именем и адресом

        insert(node->obj,end());
    }
}

array::~array()
{
    destruct();
}

void array::destruct()
{
    if (last == -1)
        return;

    for (position i = 0; i <= last; ++i) {
        delete A[i];
    }

    last = -1;
}

void array::insert(object& x, position p)
{
    for (position i = last; i > p; i--)
    {
        A[i] = A[i-1];
    }

    last++;
    A[p] = new Node(x.name, x.adress);
}

array::position array::end() const
{
    return last+1;
}

array::position array::locate(object& x)
{
    position cur = 0; // cur - позиция первого узла

    while(cur <= last) {
        if (x == retrieve(cur))
            return cur;

        cur++;
    }

    return 0;
}

object& array::retrieve(position p) // возвращает объект в позиции p
{
    if (p > last)
        throw resultisUndefined(); // если не существует или p = end(А)

    else return A[p]->obj;
}

array::position array::next(position p) const
{
    if (p < last) { // если все ок
        return p+1;
    }
    else if (p == last) { // если последний элемент
        return end();
    }
    else {
        throw resultisUndefined(); // если р не существует или р = end(А)
    }
}

array::position array::previous(position p)
{
    if (p > 0)
        return p-1;
    else
        throw resultisUndefined(); // если p = end(А)
}

void array::Delete(position p)
{
    if (p < 0 || p > last)
        throw resultisUndefined();// p не существует или p = end(А), то результат не определен.

    for (int i = p; i < last+1; ++i)
        A[i] = A[i+1];

    last--;
}

void array::makeNull()
{
    destruct();
}

array::position array::first() const
{
    if (last > -1)
        return 0;
    else
        return end();
}

void array::printList()
{
    std::cout << std::endl;

    if (last == -1) // если нет элементов массива
        throw resultisUndefined();

    for (position i = 0; i <= last; i++)
    {
        std::cout << A[i]->obj.name << " - " << A[i]->obj.adress << std::endl;
    }
}