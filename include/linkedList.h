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
        mutable std::mutex mutexR;
        mutable std::mutex mutexI;
        int searchs;
        int inserts;
        int removes;
        bool sendSignalToStopRemoveOperation;
        bool waitForSearchOrInserts;
        bool canContinueRemoval;
        
        // calculate the number of iterations that has been executed 
        // when the threads are waiting
        int searchOrInsertOperation;
        int removeOperation;
        
        bool search(int value);
        void insert(int data);
        void remove(int index);
        void print();
        int end();
};

#endif