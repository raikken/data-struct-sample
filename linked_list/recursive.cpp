/**
* @file: recursive.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-09 15:38:19
* @brief
**/


#include "linkedlist_header.hpp"

LinkedNode* LinkedNode::mergeOrderedList(LinkedNode* headptr1, LinkedNode* headptr2) {
    if (!headptr1) {
        return headptr2;
    } else if(!headptr2) {
        return headptr1;
    }

    LinkedNode* resultptr = nullptr;

    if (headptr1->getData() < headptr2->getData()) {
        resultptr = headptr1;
        resultptr->setNext(LinkedNode::mergeOrderedList(headptr1->getNext(), headptr2));
    } else {
        resultptr = headptr2;
        resultptr->setNext(LinkedNode::mergeOrderedList(headptr1, headptr2->getNext()));
    }

    return resultptr;
}

bool LinkedNode::checkPalindrome(LinkedNode* nodeptr) {
    if (!nodeptr) {
        return true;
    }

    bool result = true;
    result = checkPalindrome(nodeptr->getNext()) & (nodeptr->getData() == this->tmp->getData());

    this->tmp = this->tmp->getNext();

    return result;
}
