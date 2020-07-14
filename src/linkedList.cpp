#include "../include/linkedList.h"
#include <thread>

LinkedList::LinkedList(){}

/** used by threads b
 * can be used concurrently others threads */
void search(int value){}
        
/** used by threads i
 * can run with threads b, but not concurrenty with threads r and itself */
void insert(int data){}

/** used be threads r
 * once used this could not be used by any other threads */
void remove(int index){}