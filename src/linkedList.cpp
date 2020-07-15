#include "../include/linkedList.h"
#include <thread>
#include <algorithm>
#include <list>
#include <iostream>

LinkedList::LinkedList() {}
LinkedList::~LinkedList() {}

/** used by threads b
 * can be used concurrently others threads */
bool LinkedList::search(int value)
{
    std::cout << "thread id: " << std::this_thread::get_id() << " searching for value: " << value << std::endl;
    std::list<int>::iterator it = std::find(this->list.begin(), this->list.end(), value);
    return it != this->list.end(); // return true if find
}

/** used by threads i
 * can run with threads b, but not concurrenty with threads r and itself */
void LinkedList::insert(int data)
{
    std::cout << "thread id: " << std::this_thread::get_id() << " inserting data: " << data << std::endl;
    this->list.push_back(data);
}

/** used be threads r
 * once used this could not be used by any other threads */
void LinkedList::remove(int index)
{
    std::cout << "thread id: " << std::this_thread::get_id() << " removing index: " << index << std::endl;
    std::list<int>::iterator it = this->list.begin();
    std::advance(it, index);
    this->list.erase(it);
}

void LinkedList::print()
{
    std::cout << "[ ";

    for (std::list<int>::iterator it = this->list.begin(); it != this->list.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "]" << std::endl;
}

int LinkedList::end()
{
    return *this->list.end();
}