/**
* @file: linkedList.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-10-30 22:14:08
* @brief
**/
#include "linkedlist_header.hpp"

//reverse print
void LinkedNode::reversePrintList(LinkedNode* nodeptr) {
    if (nodeptr == nullptr) {
        return ;
    }

    LinkedNode::reversePrintList(nodeptr->getNext());
    nodeptr->printData();
}

//递归链表反转1
LinkedNode* LinkedNode::reverseLinkedNodeList1(LinkedNode* nodeptr, LinkedNode* objptr) {
    if (nodeptr == nullptr) {
        return objptr;
    }
    //resultPtr为5, nodeptr为5
    LinkedNode* resultPtr = LinkedNode::reverseLinkedNodeList1(nodeptr->getNext(), nodeptr);
    
    //resultPtr->setNext(objptr);
    nodeptr->setNext(objptr);
    return resultPtr;
}

//递归反转链表2
LinkedNode* LinkedNode::reverseLinkedNodeList2(LinkedNode* nodeptr) {
    if (nodeptr == nullptr || nodeptr->getNext() == nullptr){
        return nodeptr;
    }

    LinkedNode* resultPtr = LinkedNode::reverseLinkedNodeList2(nodeptr->getNext());
    nodeptr->getNext()->setNext(nodeptr);
    nodeptr->setNext(nullptr);
    return resultPtr;
}


//反转链表-非递归
LinkedNode* LinkedNode::reverseLinkedNodeList3(LinkedNode* nodeptr) {

    LinkedNode* workptr = nodeptr->getNext();
    //头结点setNext为nullptr
    nodeptr->setNext(nullptr);
    //workptr->setNext(nodeptr);
    while(workptr) {
        LinkedNode* tmpptr = workptr->getNext();
        workptr->setNext(nodeptr);
        nodeptr = workptr;
        if (tmpptr) {
            workptr = tmpptr;
        }else{
            break;
        }
    }

    return workptr;
}


