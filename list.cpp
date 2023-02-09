#include "list.h"

list::list(std::ifstream& in)
{
    char n[20], a[50];

    while (!in.eof())
    {
        in >> n >> a;
        Node1* node = new Node1(n,a);
        insert(&node->obj, end()); // вставляем в конец списка
    }
}

list::~list()
{
    destruct();
}

void list::destruct()
{
    if (!head)
        return;

    Node1* currentNode = head;

    while (currentNode) {
        Node1* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
}

list::position list::findPosition(position p)
{
    if (p == head) // если голова
        return head;

    position t = head;
    position prev = head;

    while (t) {
        if (p == t)
            return prev;

        prev = t;
        t = t->next;
    }
    return nullptr;
}

list::position list::findLast()
{
    position temp = head;
    position prev;

    while (temp) {
        prev = temp;
        temp = temp->next;
    }

    return prev;
}

void list::insert(struct object* x, position p)
{
    if (!head) {
        Node1 *node;
        node = new Node1(x->name, x->adress); // первый узел определяем как голову
        this->head = node;
        return;
    }

    if (!p) { // если nullptr - вставка после последнего элемента списка
        position last = findLast(); // последний элемент

        Node1 *node1; // создаем новый узел для вставки
        node1 = new Node1(x->name,x->adress);
        last->next = node1; // теперь это последний
    }

    else {

        Node1 *node1; // создаем новый узел и копируем инфу из узла с позицией р
        node1 = new Node1(p->obj.name, p->obj.adress);

        node1->next = p->next; // он продолжает указывать на следующий за ним
        p->obj = x;

        p->next = node1;
    }
}

list::position list::end()
{
    return nullptr;
}

list::position list::locate(object* x)
{
    position cur = head; // cur - позиция первого узла

    while (cur) {
        if (cur->obj == *x)           // ЗДЕСЬ РАБОТАЕТ ПЕРЕГРУЗКА ==
            return cur;
        cur = cur->next;
    }

    return nullptr;
}

object* list::retrieve(position p) // возвращает объект(имя и адрес) в позиции p
{
    if (!findPosition(p))
        throw resultIsUndefined(); // если не существует или p=end(L)

    return &p->obj;
}

list::position list::next(position p)
{
    if (!findPosition(p))
        throw resultIsUndefined(); // если р не существует или р = end(L)

    return p->next;
}

list::position list::previous(position p)
{
    position m = findPosition(p); // предыдущий за p храним

    if (m == head || !m) // если первый или не существует такой позиции
        throw resultIsUndefined();

    return m;
}

list::position list::Delete(position p)
{
    position m = findPosition(p); // сохраняем позицию перед р

    if (!m) // нет такой позиции
        return p;

    position temp = p->next; // сохраняем позицию после р

    if (p == head){ // если голова
        head = head->next;
        delete p;
        return temp; // возвращаем элемент после удаленного

    } if (p->next == nullptr){ // если последний элемент
        delete p;
        m->next = nullptr;
        return temp; // возвращаем элемент после удаленного

    } else { // если элемент не head и не last
        m->next = p->next;
        delete p;
        return temp; // возвращаем элемент после удаленного
    }
}

void list::makeNull()
{
    destruct();
}

list::position list::first()
{
    return head;
}

void list::printList()
{
    std::cout << std::endl;

    if (!head)
        throw resultIsUndefined();

    for  (position i = head; i != nullptr; i = i->next)
    {
        std::cout << i->obj.name << " - " <<  i->obj.adress << std::endl;
    }
}