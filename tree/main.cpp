/**
* @file: main.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-12-05 15:39:38
* @brief
**/
#include "binary_tree.h"

int main(){
    vecint vecarr = {0,1,2,3,4,5,6,7,8,9};
    NodeElem* nodePtr = BinaryTree::build(&vecarr);
    
    cout << nodePtr->val << endl;
    cout << "haa" <<  endl;
    cout << "preorder: ";

    BinaryTree::preorder(nodePtr);
    //cout << "leftNode: " << nodePtr->left->val << " right: " << nodePtr->right->val << endl;
    //vecint vecstaticarr = {};
    //BinaryTree::orderArr = &vecstaticarr;
    printArr(BinaryTree::preOrderArr);
    cout << "inOrder: ";
    BinaryTree::inorder(nodePtr);
    printArr(BinaryTree::inOrderArr);
    //printArr(vecResult);
    /*NodeElem* currentPtr = nodePtr;
    cout << "###############" << endl;
    while(currentPtr){
        cout << currentPtr->val << endl;
        currentPtr = currentPtr->left;
    }*/
    return 0;
}


