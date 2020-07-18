#include "../include/handler.h"
#include "../include/linkedList.h"
#include <thread>
#include <iostream>

Handler::Handler() {}

Handler::Handler(int numThreads)
{
    LinkedList l;
    std::thread t1[numThreads]; // inserts
    std::thread t2[numThreads / 2]; // removes
    std::thread t3[numThreads]; // searchs

    for (int i = 0; i < numThreads; ++i)
    {
        t1[i] = std::thread(&LinkedList::insert, &l, std::rand() % 100);
        t3[i] = std::thread(&LinkedList::search, &l, std::rand() % 100);
        
        int rand = std::rand();
        int index = l.end() == 0 ? -1 : std::rand() % l.end();
        if (i % 2 == 0)
        {
            t2[i% (numThreads/2)] = std::thread(&LinkedList::remove, &l, index);
        }
    }

    for (int i = 0; i < numThreads; ++i)
    {
        t1[i].join();
        t3[i].join();

        if (i < numThreads / 2)
        {
            t2[i].join();
        }
    }
    l.print();
}
