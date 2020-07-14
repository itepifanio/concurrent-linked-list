#include "../include/linkedList.h"
#include <iostream>

int main(){
    LinkedList l;
    
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    l.print();

    std::cout << l.search(2) << std::endl;

    l.remove(2);

    l.print();

    return 0;
}