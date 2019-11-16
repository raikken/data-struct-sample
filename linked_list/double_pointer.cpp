/**
* @file: double_pointer.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-07 19:15:05
* @brief
**/
#include "linkedlist_header.hpp"


bool LinkedNode::checkRing(LinkedNode* headptr){
    if (!headptr) {
        return false;
    }
    LinkedNode* slowptr = headptr;
    LinkedNode* fastptr = headptr->getNext();

    while(slowptr && fastptr) {
        if (slowptr == fastptr){
            return true;
        }

        slowptr = slowptr->getNext();
        fastptr = fastptr->getNext();
        if (fastptr) {
            fastptr = fastptr->getNext();
        }
    }

    return false;
}


LinkedNode* LinkedNode::getnthLast(LinkedNode* headptr,int n){
    if(!headptr || n <= 0) {
        return headptr;
    }
    LinkedNode* fastptr = headptr;
    for(int i = 0;i < n; i++) {
        fastptr = fastptr->getNext();
        if (!fastptr) {
            return nullptr;
        }
    }

    LinkedNode* slowptr = headptr;
    while(fastptr) {
        slowptr = slowptr->getNext();
        fastptr = fastptr->getNext();
    }

    return slowptr;
}
