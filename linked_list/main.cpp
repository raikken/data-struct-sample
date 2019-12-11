/**
* @file: linkedList.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-10-30 22:14:08
* @brief
**/

#include "linkedlist_header.hpp"

int main() {
    vector<int> testArr = {1,2,3,4,5,6,7,8,9,0};

    LinkedNode* headptr = LinkedNode::build(&testArr);
    LinkedNode* newptr = LinkedNode::rotate(headptr, 3);
    cout << "after ratate: " << endl;
    LinkedNode::printList(newptr);
   

    vector<int> arr1 = {1,4,5,6,9};
    vector<int> arr2 = {0,2,3,7,8};
    LinkedNode* headptr1 = LinkedNode::build(&arr1);
    LinkedNode* headptr2 = LinkedNode::build(&arr2);

    LinkedNode* nodeptr = LinkedNode::mergeOrderedList(headptr1, headptr2);
    cout << "nodeptr: " << endl;
    LinkedNode::printList(nodeptr);
    
    
    vector<int> arr3 = {1,5,2,7};
    LinkedNode* complexHead1 = LinkedNode::build(&arr1);
    complexHead1->setOther(complexHead1->getNext()->getNext());

    LinkedNode* copyPtr = LinkedNode::complexCopy(complexHead1);
    
    
    LinkedNode* tmpPtr = new LinkedNode();
    tmpPtr->tmp = headptr;
    bool result = tmpPtr->checkPalindrome(headptr);

    cout << "is palidrome: " << result << endl;
    
    return 0;
}


