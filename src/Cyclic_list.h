/**
* @author Filip Konieczny
*/
#include <iostream>

#ifndef CYCLIC_LIST_H
    #define CYCLIC_LIST_H
#endif

class Cyclic_list {

    class Node {
    public:
        int value;
        Node *next;
        Node(int val = 0): value(val), next(nullptr) {};
    };

public:

    void push(int);
    int push(int, unsigned);
    int pushAfter(int, int);

    int remove(int);
    int remove(int, int);
    int removeIndex(unsigned);

    int find(int);
    int get(unsigned);

    unsigned getLength() const { return length; };

    void empty();
    void uniquify();

    friend std::ostream & operator<<(std::ostream &, const Cyclic_list &);
    friend Cyclic_list operator+(const Cyclic_list &, const Cyclic_list &);
    friend Cyclic_list operator-(const Cyclic_list &, const Cyclic_list &);
    friend Cyclic_list & operator-=(Cyclic_list &, const Cyclic_list &);
    friend Cyclic_list & operator-=(Cyclic_list &, const int);
    friend Cyclic_list & operator+=(Cyclic_list &, const Cyclic_list &);
    friend Cyclic_list & operator+=(Cyclic_list &, const int);
    friend bool operator==(const Cyclic_list &, const Cyclic_list &);
    friend bool operator!=(const Cyclic_list &, const Cyclic_list &);
    int operator[](unsigned);
    Cyclic_list & operator=(const Cyclic_list &);

    Cyclic_list(): length(0), last() {};
    Cyclic_list(const Cyclic_list &);
    Cyclic_list(std::initializer_list<int>);
    ~Cyclic_list();

private:

    Node *last;
    unsigned length; //list length
};