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
    cout << "preorder: ";
    BinaryTree::preorder(nodePtr);
    printArr(BinaryTree::preOrderArr);
    
    cout << "inOrder: ";
    BinaryTree::inorder(nodePtr);
    printArr(BinaryTree::inOrderArr);
    
    vecint preorderArr = {0, 1, 3, 7, 8, 4, 9, 2, 5, 6};
    vecint inorderArr = {7, 3, 8, 1, 9, 4, 0, 5, 2, 6};
    size_t len = preorderArr.size();

    //build binary tree by preorder and inorder
    NodeElem* nodeAfterPtr = BinaryTree::buildByOrder(&(preorderArr[0]), &(preorderArr[len-1]), &(inorderArr[0]), &(inorderArr[len-1]));
    BinaryTree::preorder(nodeAfterPtr);
    printArr(BinaryTree::preOrderArr);

    return 0;
}


