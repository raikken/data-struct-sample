/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-01 22:22:09
* @brief
**/
#include "linkedlist_header.hpp"

LinkedNode::LinkedNode(const LinkedNode& obj){
    //this->setData(obj.getData());
    //this->setNext(obj.getNext());
    //this->setOther(obj.getOther);
    //this->_other = obj.getOther();
    this->_data = obj._data;
    this->_next = obj._next;
    this->_other = obj._other;
}


int LinkedNode::getData(){
    return this->_data;
}

void LinkedNode::printData(){
    cout << this->_data << endl;
}

void LinkedNode::setOther(LinkedNode* other){
    this->_other = other;
}


LinkedNode* LinkedNode::getOther(){
    return this->_other;
}

void LinkedNode::setNext(LinkedNode* next){
    this->_next = next;
}


void LinkedNode::setData(int data) {
    this->_data = data;
}


LinkedNode* LinkedNode::getNext(){
    return this->_next;
}


void LinkedNode::printList(LinkedNode* headptr){
    if (headptr == nullptr) {
        return ;
    }

    LinkedNode* currentptr = headptr;

    while(currentptr){
        currentptr->printData();
        currentptr = currentptr->getNext();
    }
}

LinkedNode* LinkedNode::build(vector<int>* vecintptr) {
    unordered_map<int, LinkedNode*> linkNodeMap;
    LinkedNode* headptr = nullptr;
    for (int i = 0; i < vecintptr->size(); i++) {
        LinkedNode* nodeptr = new LinkedNode(vecintptr->at(i));
        linkNodeMap[i] = nodeptr;
        if (!i) {
            headptr = nodeptr;
            continue;
        }
    }

    for(int i=0; i < vecintptr->size()-1; i++) {
        linkNodeMap[i]->setNext(linkNodeMap[i+1]);
    }
    return headptr;
}
vector<int> testArr = {1,2,3,4,5,6,7,8,9,0};
