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


void BinaryTree::preorder(NodeElem* node){
    if (!node) {
        return ;
    }
    //cout << node->val << endl;
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

