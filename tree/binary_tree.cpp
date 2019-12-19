/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "binary_tree.h"

vecint vecstaticarr = {};
vecint* BinaryTree::preOrderArr = &vecstaticarr;

vecint vecstaticarr1 = {};
vecint* BinaryTree::inOrderArr = &vecstaticarr1;


NodeElem* BinaryTree::build(vecint* vecarr){
    int len = vecarr->size();
    vector<NodeElem*> vectorNodeList;
    for(int i=0; i < len; i++){
        NodeElem* elem = new NodeElem(vecarr->at(i));
        vectorNodeList.push_back(elem);
    }

    for(int i=0; i< len/2; i++){
        int leftNodeIndex = 2*i+1;
        int rightNodeIndex = 2*i+2;
        
        if(leftNodeIndex < len){
            vectorNodeList.at(i)->left = vectorNodeList.at(leftNodeIndex);
        }
        if(rightNodeIndex < len){
            vectorNodeList.at(i)->right = vectorNodeList.at(rightNodeIndex);
        }
    }
    
    return vectorNodeList[0];
}


NodeElem* BinaryTree::buildByOrder(int* preorderStart, int* preorderEnd, int* inorderStart, int* inorderEnd){
    if((!preorderStart || !preorderStart) || (!inorderStart ||!inorderEnd)) {
        return nullptr;
    }
    NodeElem* rootElem = new NodeElem(*preorderStart);
    int* rootIndex = findIndex(inorderStart, inorderEnd, *preorderStart);
    
    int leftLen = rootIndex - inorderStart; 
    int rightLen = inorderEnd - rootIndex;
    
    if (leftLen > 0) {
        //
        rootElem->left = BinaryTree::buildByOrder(preorderStart+1, preorderStart+leftLen, inorderStart, inorderStart+leftLen-1); 
    }

    if (rightLen > 0) {
        rootElem->right = BinaryTree::buildByOrder(preorderStart+leftLen+1, preorderStart+leftLen+rightLen, inorderStart+leftLen+1, inorderStart+leftLen+rightLen);
    }

    return rootElem;
}


void BinaryTree::preorder(NodeElem* node){
    if (!node) {
        return ;
    }

    BinaryTree::preOrderArr->push_back(node->val);
    BinaryTree::preorder(node->left);
    BinaryTree::preorder(node->right);
}


void BinaryTree::inorder(NodeElem* node){
    if (!node) {
        return ;
    }

    BinaryTree::inorder(node->left);
    BinaryTree::inOrderArr->push_back(node->val);
    BinaryTree::inorder(node->right);
}

