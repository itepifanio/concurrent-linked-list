#include "../include/handler.h"
#include "../include/linkedList.h"
#include <thread>
#include <iostream>

Handler::Handler() {}

Handler::Handler(int numThreads)
{
    LinkedList l;
    std::thread threads[numThreads*2];

    for (int i = 0; i < numThreads; ++i)
    {
        threads[i] = std::thread(&LinkedList::insert, l, 1);
        // threads[i+1] = std::thread(&LinkedList::remove, l, rand() % l.end());
        std::cout << l.end() << std::endl;
        if(l.end() > 0){
            threads[i+1] = std::thread(&LinkedList::search, l, 0);
        }
    }

    for (int i = 0; i < numThreads; ++i)
    {
        threads[i].join();
    }
}
