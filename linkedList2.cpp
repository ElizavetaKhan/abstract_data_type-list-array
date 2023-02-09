#include "linkedList2.h"

linkedList2::linkedList2(std::ifstream& in)
{
    char n[20], a[50]; // имя адрес

    while (in >> n >> a) {
        in >> n >> a;
        nodeFor2link* node;
        node = new nodeFor2link(n,a);
        insert(&node->obj, End());
    }
}

linkedList2::~linkedList2()
{
    destruct();
}

void linkedList2::destruct()
{
    if (!start) // если пустой список
        return;

    nodeFor2link* currentNode = start;

    while (currentNode) {
        nodeFor2link* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    start = nullptr;
    end = nullptr;
}

bool linkedList2::findPosition(position p)
{
    position t = start;

    while (t) {
        if (p == t)
            return true;

        t = t->next;
    }

    return false;
}

void linkedList2::insert(struct object* x, position p)
{
    if (!start) { // если первый узел в списке
        nodeFor2link* node;
        node = new nodeFor2link(x->name,x->adress);
        this->start = node;
        this->end = node;
        return;
    }

    if (!findPosition(p)) { // если вставить после последнего - позиции р не существует
        position temp = end; // последний элемент

        nodeFor2link *node1; // создаем новый узел для вставки
        node1 = new nodeFor2link(x->name,x->adress);

        temp->next = node1;
        node1->prev = temp;

        end = node1;

    } else if (p == end) { // если вставить в end
        position temp = end;

        nodeFor2link *node1; // создаем новый узел для вставки, помещаем туда end
        node1 = new nodeFor2link(end->obj.name,end->obj.adress);

        temp->obj = x;

        temp->next = node1;
        node1->prev = temp;

        end = node1; // переназначаем end

    } else if (p) { // позиция р есть в данном списке и это не end

        nodeFor2link *node1; // создаем новый узел для вставки
        node1 = new nodeFor2link(p->obj.name, p->obj.adress); // переносим данные из р в node1

        node1->next = p->next; // он продолжает указывать на следующий за ним
        p->obj = x;

        node1->prev = p;
        p->next = node1;
    }
}

linkedList2::position linkedList2::End()
{
    return nullptr;
}


linkedList2::position linkedList2::locate(object* x)
{
    position cur = start; // cur - позиция первого узла

    while (cur) {
        if (cur->obj == *x)           // ЗДЕСЬ РАБОТАЕТ ПЕРЕГРУЗКА ==
            return cur;
        cur = cur->next;
    }

    return nullptr;
}

object* linkedList2::retrieve(position p)
{
    if (!findPosition(p))
        throw resultIsundefined(); // если не существует или p=end(L)

    return &p->obj;
}

linkedList2::position linkedList2::next(position p)
{
    if (!findPosition(p))
        throw resultIsundefined(); // если р не существует или р = end(L)

    return p->next;
}

linkedList2::position linkedList2::previous(position p)
{
    if (p != start && p)
        return p->prev;
    else
        throw resultIsundefined();
}

linkedList2::position linkedList2::Delete(position p)
{
    if (!findPosition(p)) // нет такой позиции
        return p;

    position next = p->next; // позиция после р
    position previous = p->prev; // позиция перед р

    if (p == start) { // если голова

        if (p == end) { // если совпадает с хвостом - то есть один элемент
            start = nullptr;
            end = nullptr;
            delete p;
            return nullptr;
        } else { // если просто голова, но не хвост
            start = start->next;
            start->prev = nullptr;
            delete p;
            return next; // возвращаем элемент следующий после удаленного
        }

    } if (p == end){ // если последний элемент
        previous->next = nullptr;
        end = previous;
        delete p;
        return next; // возвращаем элемент следующий после удаленного

    } else { // если элемент не start и не end
        previous->next = p->next;
        next->prev = previous;
        delete p;
        return next; // возвращаем элемент следующий после удаленного
    }
}

void linkedList2::makeNull()
{
    destruct();
}

linkedList2::position linkedList2::first()
{
    return start;
}

void linkedList2::printList()
{
    if (!start) // если в списке нет элементов
        throw resultIsundefined();
    std::cout << std::endl;

    for  (position i = start; i != nullptr; i = i->next)
    {
        std::cout << i->obj.name << " - " <<  i->obj.adress << std::endl;
    }
}