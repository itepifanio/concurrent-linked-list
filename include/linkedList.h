#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <list>
#include <thread>
#include <vector>

class LinkedList{
    private:
        std::list<int> list;
        // makes search over the list
        std::vector<std::thread> b;
        // insert data to the list
        std::vector<std::thread> i;
        // removes data from the list
        std::vector<std::thread> r;
    public:
        LinkedList();
        void search(int value);
        void insert(int data);
        void remove(int index);
};

#endif