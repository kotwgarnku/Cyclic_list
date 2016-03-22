/**
* @author Filip Konieczny
*/
#include <iostream>
#include "src/Cyclic_list.h"

int main() {
    Cyclic_list myList, test, *otherList;

    otherList = new Cyclic_list();
    otherList->push(2);

    myList.push(5);
    myList.push(1);
    myList.push(3);
    myList.push(3);
    myList.push(1);
    myList.push(7);
    myList.push(12);
    myList.push(-1, 6);
    myList.pushAfter(99, 12);

    std::cout << myList << std::endl;
    std::cout << *otherList << std::endl;
    std::cout << otherList->getLength() << std::endl;
    test = *otherList + myList;
    std::cout << test << std::endl;

    return 0;
}
