/*
* @file: tire_tree.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2020-02-08 18:30:52
* @brief
**/
#include "tire_tree.h"

void TireNode::insert(char* strTmp){
    if (strTmp == '\0') {
        return ;
    }

    size_t strLength = strlen(strTmp);
    TireNode* node = this;
    for(size_t i = 0; i< strLength; i++){
        if (node->nextNodes[strTmp[i] - 'a'] == nullptr) {
            node->nextNodes[strTmp[i] - 'a'] = new TireNode();
        }

        node  = node->nextNodes[strTmp[i] - 'a'];
        node->prefix++;
        //node = node->nextNodes[strTmp[i] - 'a'];
    }
    node->count++;
}


int TireNode::prefixCount(char* strTmp){
    if (strTmp == '\0') {
        return 0;
    }

    size_t strLength = strlen(strTmp);
    TireNode* node = this;
    for(size_t i = 0; i< strLength; i++) {
        if (node->nextNodes[strTmp[i] - 'a'] != nullptr) {
           node = node->nextNodes[strTmp[i] - 'a'];
        } else {
           return 0;
       } 
    }
    return node->prefix;
}
