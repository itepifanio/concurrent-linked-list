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
    this->sendSignalToStopRemoveOperation = false;
    this->waitForSearchOrInserts = false;
    this->searchOrInsertOperation = 0;
    this->removeOperation = 0;
    this->canContinueRemoval = false;
}
LinkedList::~LinkedList() {}

/** used by threads b
 * can be used concurrently others threads */
bool LinkedList::search(int value)
{
    while (this->removes != 0 || this->waitForSearchOrInserts)
    {
        if (this->removeOperation > 3)
        {
            this->sendSignalToStopRemoveOperation = true;
        }
    } // wait removes
    this->searchs += 1;
    this->searchOrInsertOperation += 1;
    std::cout << "thread id: " << std::this_thread::get_id() << " searching for value: " << value << std::endl;
    std::list<int>::iterator it = std::find(this->list.begin(), this->list.end(), value);
    this->searchs -= 1;
    this->searchOrInsertOperation += 1;

    if (this->searchOrInsertOperation > 3)
    {
        this->canContinueRemoval = true;
    }

    return it != this->list.end(); // return true if find
}

/** used by threads i
 * can run with threads b, but not concurrenty with threads r and itself */
void LinkedList::insert(int data)
{
    while (this->removes != 0 || this->waitForSearchOrInserts)
    {
        if (this->removeOperation > 3)
        {
            this->sendSignalToStopRemoveOperation = true;
        }
    } // wait removes

    this->mutexI.lock(); // inserts must be mutal exclusive
    this->inserts += 1;
    std::cout << "thread id: " << std::this_thread::get_id() << " inserting data: " << data << std::endl;
    this->list.push_back(data);
    this->inserts -= 1;
    this->searchOrInsertOperation += 1;
    this->mutexI.unlock();

    if (this->searchOrInsertOperation > 3)
    {
        this->canContinueRemoval = true;
    }
}

/** used be threads r
 * once used this could not be used by any other threads */
void LinkedList::remove(int index)
{
    if (this->sendSignalToStopRemoveOperation)
    {
        this->waitForSearchOrInserts = true;
        this->removeOperation = 0;
        while (this->waitForSearchOrInserts)
        {
            if (this->canContinueRemoval)
            {
                this->waitForSearchOrInserts = false;
                this->sendSignalToStopRemoveOperation = false;
                this->canContinueRemoval = false;
                break;
            }
        } // wait for inserts or search not starves
    }

    this->removes += 1;
    while (this->inserts != 0)
    {
    } // wait inserts done

    this->mutexR.lock(); // removes must be mutual exclusive

    this->removeOperation += 1;

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

    this->removes -= 1;
    this->mutexR.unlock();
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