#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <list>
#include <vector>
#include <mutex>

class LinkedList{
    private:
        std::list<int> list;
    public:

        LinkedList();
        ~LinkedList();
        mutable std::mutex m1;
        int searchs;
        int inserts;
        int removes;
        bool search(int value);
        void insert(int data);
        void remove(int index);
        void print();
        int end();
};

#endif