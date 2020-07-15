#ifndef _HANDLER_H_
#define _HANDLER_H_

#include "linkedList.h"
#include <vector>
#include <thread>

class Handler
{
    public:
        Handler();
        Handler(int numThreads);
        // makes search over the list
        std::vector<std::thread> b;
        // insert data to the list
        std::vector<std::thread> i;
        // removes data from the list
        std::vector<std::thread> r;
};

#endif