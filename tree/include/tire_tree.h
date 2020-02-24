/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "base_method.h"

#ifndef TIRE_TREE_H__
#define TIRE_TREE_H__


class NodeElem{
    public:
        int val;
        NodeElem* left;
        NodeElem* right;
        
        NodeElem(int value):val(value), left(nullptr), right(nullptr){};
};


class TireNode{
    public:
        void insert(char* strTmp);

        int prefixCount(char* strTmp);

        //以当前节点作为结尾的数量
        int count;
        //当前链路为前缀字符串的数量
        int prefix;
        //char charter;
        TireNode* nextNodes[26];


};


#endif

