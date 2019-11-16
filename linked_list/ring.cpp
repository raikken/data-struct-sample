/**
* @file: ring.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-08 20:07:43
* @brief
**/
#include "linkedlist_header.hpp"

LinkedNode* LinkedNode::rotate(LinkedNode* headptr,int n) {
    LinkedNode* finalptr = headptr;
    LinkedNode* newHeadptr = headptr;
    while(finalptr) {
        if (!finalptr->getNext()) {
            break;
        }
        finalptr = finalptr->getNext();
    }

    finalptr->setNext(headptr);
    
    for(int i=0; i < n; i++) {
        newHeadptr = newHeadptr->getNext();
        finalptr = finalptr->getNext();
    }
    finalptr->setNext(nullptr);
    return newHeadptr;
}

