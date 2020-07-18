#include "../include/handler.h"
#include "../include/linkedList.h"
#include <thread>
#include <iostream>

Handler::Handler() {}

// Handler::Handler(int numThreads)
// {
//     LinkedList l;
//     std::thread t1[numThreads];
//     std::thread t2[numThreads / 2];

//     for (int i = 0; i < numThreads; ++i)
//     {
//         // if (i % 2 != 0)
//         // {
//         t1[i] = std::thread(&LinkedList::insert, &l, std::rand() % 100);
//         // }
//         // if(i == 8){
//         // if (i % 2 == 0 && i != 0)
//         // {
//         int rand = std::rand();
//         int index = l.end() == 0 ? -1 : std::rand() % l.end();
//         if (i % 2 == 0)
//         {
//             t2[i] = std::thread(&LinkedList::remove, &l, index);
//         }
//         // }
//         // threads[i+2] = std::thread(&LinkedList::search, l, 0);
//         // }
//     }

//     for (int i = 0; i < numThreads; ++i)
//     {
//         t1[i].join();
//         if (i % 2 == 0)
//         {
//             t2[i].join();
//         }
//     }
//     l.print();
// }

Handler::Handler(int numThreads)
{
    LinkedList l;
    std::thread t1 = std::thread(&LinkedList::insert, &l, std::rand() % 100);
    std::thread t2 = std::thread(&LinkedList::insert, &l, std::rand() % 100);
    std::thread t3 = std::thread(&LinkedList::remove, &l, 1);
    t1.join();
    t2.join();
    t3.join();
    l.print();
}
