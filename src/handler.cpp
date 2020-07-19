#include "../include/handler.h"
#include "../include/linkedList.h"
#include <thread>
#include <iostream>

Handler::Handler() {}

// Handler::Handler(int numThreads)
// {
//     LinkedList l;
//     std::thread threads[numThreads];

//     for (int i = 0; i < numThreads; ++i)
//     {
//         int op = std::rand() % 3;
//         if(op == 0){
//             threads[i] = std::thread(&LinkedList::insert, &l, std::rand() % 100);
//         }else if(op == 1){
//             threads[i] = std::thread(&LinkedList::search, &l, std::rand() % 100);
//         }else if(op == 2){
//             threads[i] = std::thread(&LinkedList::remove, &l, std::rand() % 100);
//         }
//     }

//     for (int i = 0; i < numThreads; ++i)
//     {
//         threads[i].join();
//     }
//     l.print();
// }


Handler::Handler(int numThreads)
{
    LinkedList l;
    std::thread t1 = std::thread(&LinkedList::remove, &l, std::rand() % 100);
    std::thread t2 = std::thread(&LinkedList::remove, &l, std::rand() % 100);
    std::thread t4 = std::thread(&LinkedList::insert, &l, std::rand() % 100);
    std::thread t3 = std::thread(&LinkedList::remove, &l, std::rand() % 100);
    std::thread t5 = std::thread(&LinkedList::insert, &l, std::rand() % 100);
    std::thread t6 = std::thread(&LinkedList::insert, &l, std::rand() % 100);
    std::thread t7 = std::thread(&LinkedList::insert, &l, std::rand() % 100);
    std::thread t8 = std::thread(&LinkedList::insert, &l, std::rand() % 100);
    std::thread t10 = std::thread(&LinkedList::remove, &l, std::rand() % 100);
    std::thread t9 = std::thread(&LinkedList::insert, &l, std::rand() % 100);
    std::thread t11 = std::thread(&LinkedList::remove, &l, std::rand() % 100);
    std::thread t12 = std::thread(&LinkedList::remove, &l, std::rand() % 100);
    std::thread t13 = std::thread(&LinkedList::remove, &l, std::rand() % 100);
    std::thread t14 = std::thread(&LinkedList::remove, &l, std::rand() % 100);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();
    t13.join();
    t14.join();
    l.print();
}