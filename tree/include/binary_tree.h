/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/

#ifndef BINARY_TREE_H__
#define BINARY_TREE_H__

#include "base_method.h"

class NodeElem{
    public:
        int val;
        NodeElem* left;
        NodeElem* right;
        
        NodeElem(int value):val(value), left(nullptr), right(nullptr){};
};


class BinaryTree{
    public:
        static NodeElem* build(vecint* vecarr);
        static void preorder(NodeElem* node);
        static void inorder(NodeElem* node);

        static vecint* preOrderArr;
        static vecint* inOrderArr;
};

//vecint vecstaticarr = {};
//vecint* BinaryTree::orderArr = &vecstaticarr;
//vecint vecarr = {};
//vecint* BinaryTree::orderArr = &vecarr;

#endif

