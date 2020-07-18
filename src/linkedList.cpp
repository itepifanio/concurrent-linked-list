#include "../include/linkedList.h"
#include <thread>
#include <algorithm>
#include <list>
#include <iostream>
#include <mutex>

LinkedList::LinkedList()
{
    this->removes = 0;
    this->searchs = 0;
    this->inserts = 0;
    this->searchOrInsertOperations = 0;
    this->canRemove = false;
}
LinkedList::~LinkedList() {}

/** used by threads b
 * can be used concurrently others threads */
bool LinkedList::search(int value)
{
    while (this->searchOrInsertOperations > 3 && this->removes > 0 && this->canRemove == false)
    {
        this->canRemove = true;
    } // every three search or insert the threads waiting for a removal

    while(this->canRemove == true){

    } // wait removes for removes

    this->searchOrInsertOperations += 1;
    this->searchs += 1;

    std::cout << "thread id: " << std::this_thread::get_id() << " searching for value: " << value << std::endl;
    std::list<int>::iterator it = std::find(this->list.begin(), this->list.end(), value);

    this->searchs -= 1;

    return it != this->list.end(); // return true if find
}

/** used by threads i
 * can run with threads b, but not concurrenty with threads r and itself */
void LinkedList::insert(int data)
{
    while (this->searchOrInsertOperations > 3 && this->removes > 0 && this->canRemove == false)
    {
        this->canRemove = true;
    } // every three search or insert the threads waiting for a removal

    while(this->canRemove == true){

    } // wait removes for removes

    this->searchOrInsertOperations += 1;

    this->mutexI.lock(); // inserts must be mutal exclusive
    this->inserts += 1;

    std::cout << "thread id: " << std::this_thread::get_id() << " inserting data: " << data << std::endl;
    this->list.push_back(data);

    this->inserts -= 1;
    this->mutexI.unlock();
}

/** used be threads r
 * once used this could not be used by any other threads */
void LinkedList::remove(int index)
{
    this->removes += 1;
    if (this->inserts == 0 && this->searchs == 0)
    {
        this->canRemove = true;
    }

    while (!this->canRemove)
    {
        if (this->inserts == 0 && this->searchs == 0)
        {
            this->canRemove = true;
        }
    } // wait until can remove

    this->mutexR.lock(); // removes must be mutual exclusive
    if (index != -1)
    {
        if (index < this->end())
        {
            std::cout << "thread id: " << std::this_thread::get_id() << " removing index: " << index << std::endl;
            std::list<int>::iterator it = this->list.begin();
            std::advance(it, index);
            this->list.erase(it);
        }
        else
        {
            std::cout << "thread id: " << std::this_thread::get_id()
                      << " not removing. Index (" << index << ") is invalid" << std::endl;
        }
    }
    this->mutexR.unlock();
    this->canRemove = false;
    this->removes -= 1;
    this->searchOrInsertOperations = 0;
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