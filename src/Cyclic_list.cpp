/**
* @author Filip Konieczny
*/
#include <stdexcept>
#include "Cyclic_list.h"

//add item on the end of the list
void Cyclic_list::push(int value) {
    Node *newNode = new Node(value);

    if(length == 0) {
        last = newNode;
        last->next = last;
        ++length;
        return;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    ++length;
}

int Cyclic_list::push(int value, unsigned index) {
    Node *newNode, *it;
    unsigned inx = 0;

    if (index == length) {
        push(value);
        return 0;
    }

    newNode = new Node(value);

    it = last;
    do {
        if(inx == index) {
            newNode->next = it->next;
            it->next = newNode;
            ++length;
            return 0;
        }
        ++inx;
        it = it->next;
    } while(it != last);

    return -1;
}

int Cyclic_list::pushAfter(int value, int after) {
    Node *newNode, *it;

    newNode = new Node(value);
    it = last->next;

    while(it != last) {
        if(it->value == after) {
            newNode->next = it->next;
            it->next = newNode;
            ++length;
            return 0;
        }
        it = it->next;
    }
    if(it->value == after) {
        newNode->next = it->next;
        it->next = newNode;
        ++length;
        return 0;
    }

    return -1;
}

int Cyclic_list::remove(int value) {
    return remove(value, value);
}

int Cyclic_list::remove(int min, int max) {
    Node *it, *tmp;
    int removed = -1;

    if(length == 0)
        return -1;

    it = last;
    while(it->next != last) {
        if((it->next->value >= min) && (it->next->value <= max)) {
            tmp = it->next;
            it->next= it->next->next;
            delete tmp;
            --length;
            removed = 0;
            continue;
        }
        it = it->next;
    }
    if(last->value >= min && last->value <= max) {
        it->next = last->next;
        delete last;
        last = it;
        --length;
        removed = 0;
    }
    return removed;
}

int Cyclic_list::removeIndex(unsigned index) {
    Node *it, *tmp;
    unsigned inx;

    if(length == 0 || index >= length)
        return -1;

    it = last;
    for(inx = 0; inx < length-1; ++inx) {
        if(inx == index) {
            tmp = it->next;
            it->next = it->next->next;
            delete tmp;
            --length;
            return 0;
        }
        it = it->next;
    }
    if(inx == index) {
        tmp = last;
        it->next = last->next;
        delete tmp;
        last = it;
        --length;
        return 0;
    }
    return -1;
}

int Cyclic_list::find(int value) {
    Node *it = last->next;
    unsigned inx = 0;

    for(; inx < length; ++inx) {
        if(it->value == value)
            return inx;
        it = it->next;
    }
    return -1;
}

int Cyclic_list::get(unsigned index) {
    return operator[](index);
}

void Cyclic_list::empty() {
    Node *it;

    it = last;
    while(length) {
        it = last->next;
        delete last;
        last = it;
        --length;
    }
}

void Cyclic_list::uniquify() {
    Node *it, *jt, *tmp;

    it = last->next;
    while(it != last) {
        jt = it;

        while(jt->next != last) {
            if(it->value == jt->next->value) {
                tmp = jt->next;
                jt->next = jt->next->next;
                delete tmp;
                --length;
            }
            else
                jt = jt->next;
        }
        if(last->value == it->value) {
            tmp = jt->next;
            jt->next = jt->next->next;
            delete tmp;
            last = jt;
            --length;
        }

        it = it->next;
    }
}

Cyclic_list::Cyclic_list(std::initializer_list<int> rList) : Cyclic_list() {
    for(auto const item : rList)
        push(item);
}

std::ostream & operator<<(std::ostream &os, const Cyclic_list &list) {

    if(list.length == 0) {
        os << "[ empty ]";
        return os;
    }

    Cyclic_list::Node *it = list.last->next;
    os << "-> ";
    while(it != list.last) {
        os << it->value << ", ";
        it = it->next;
    }
    os << it->value << " ->";
    return os;
}

Cyclic_list operator+(const Cyclic_list &l, const Cyclic_list &r) {
    Cyclic_list sum;
    Cyclic_list::Node *it;

    it = l.last->next;
    for(int i = 0; i < l.length; ++i) {
        sum.push(it->value);
        it = it->next;
    }

    it = r.last->next;
    for(int i = 0; i < r.length; ++i) {
        sum.push(it->value);
        it = it->next;
    }

    return sum;
}

Cyclic_list & operator+=(Cyclic_list &l, const Cyclic_list &r) {
    return (l = l + r);
}

Cyclic_list & operator+=(Cyclic_list &l, const int value) {
    l.push(value);
    return l;
}

Cyclic_list operator-(const Cyclic_list &l, const Cyclic_list &r) {
    Cyclic_list diff;
    Cyclic_list::Node *it;

    it = l.last->next;
    for(int i = 0; i < l.length; ++i) {
        diff.push(it->value);
        it = it->next;
    }

    it = r.last->next;
    for(int i = 0; i < r.length; ++i) {
        diff.remove(it->value);
        it = it->next;
    }

    return diff;
}

Cyclic_list & operator-=(Cyclic_list &l, const Cyclic_list &r) {
    return (l = l - r);
}

Cyclic_list & operator-=(Cyclic_list &l, const int value) {
    l.remove(value);
    return l;
}

int Cyclic_list::operator[](unsigned index) {
    Node *it = last->next;
    unsigned inx = 0;

    if(index < 0 || index >= length)
        throw std::out_of_range("Index is out of range.");

    for(; inx < length; ++inx) {
        if(inx == index)
            return it->value;
        it = it->next;
    }
}

bool operator==(const Cyclic_list &l, const Cyclic_list &r) {
    Cyclic_list::Node *lit, *rit;
    unsigned inx;

    if(l.length != r.length)
        return false;

    lit = l.last->next;
    rit = r.last->next;
    for(inx = 0; inx < l.length; inx++) {
        if(lit->value != rit->value)
            return false;

        lit = lit->next;
        rit = rit->next;
    }

    return true;
}

bool operator!=(const Cyclic_list &l, const Cyclic_list &r) {
    return !operator==(l, r);
}

Cyclic_list::Cyclic_list(const Cyclic_list &source) : Cyclic_list() {
    Node *it = source.last->next;

    for(int i = 0; i < source.length; ++i) {
        this->push(it->value);
        it = it->next;
    }
}

Cyclic_list& Cyclic_list::operator=(const Cyclic_list &list) {
    Node *it;

    empty();

    it = list.last->next;
    for(int i = 0; i < list.length; ++i) {
        this->push(it->value);
        it = it->next;
    }

    return *this;
}

Cyclic_list::~Cyclic_list() {
    empty();
}
