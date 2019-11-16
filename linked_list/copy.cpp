/**
* @file: ring.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-08 20:07:43
* @brief
**/
#include "linkedlist_header.hpp"

LinkedNode* LinkedNode::complexCopy(LinkedNode* headptr) {
    if (!headptr) {
        return headptr;
    }
    LinkedNode* currentPtr = headptr;
    int len = 0;
    while(currentPtr){
       LinkedNode* currentTmpPtr =  new LinkedNode(*currentPtr);
       //LinkedNode* currentNextPtr = currentPtr->getNext();
       currentPtr->setNext(currentTmpPtr);
       currentPtr = currentTmpPtr->getNext();
       len += 1;
    }

    currentPtr = headptr;
    int i = 0;
    while(currentPtr){
        if (!(i%2)) {
            i++;
            continue;
        }
        if (currentPtr->getOther()) {
            currentPtr->setOther(currentPtr->getOther()->getNext());
        }
        currentPtr = currentPtr->getNext();
        i++;
    }

    currentPtr = headptr;
    LinkedNode* retPtr = currentPtr->getNext();
    while(currentPtr){
        //拆链操作
        LinkedNode* tmpNextPtr = currentPtr->getNext();
        if (currentPtr->getNext() && currentPtr->getNext()->getNext()) {
            currentPtr->setNext(currentPtr->getNext()->getNext());
        } else {
            currentPtr->setNext(nullptr);
        }
        currentPtr = tmpNextPtr;
    }
    return retPtr;
}

