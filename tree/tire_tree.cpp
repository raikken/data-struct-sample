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

void TireNode::search(char* strPrefix, vector<char*>* result) {
    size_t strLength = strlen(strPrefix);
    TireNode* node = this;
    for(size_t i = 0; i < strLength; i++) {
        if (node->nextNodes[strPrefix[i] - 'a'] != nullptr) {
            node = node->nextNodes[strPrefix[i] - 'a']; 
        }
    }

    
    if (node->count > 0) {
        result->push_back(strPrefix);
    }
    
    TireNode::findPrefixStrResult(node, result, strPrefix);
}

void TireNode::findPrefixStrResult(TireNode* node, vector<char*>* result, char* base){
    for (int i = 0; i < 26; i++) {
        TireNode* tmpNode = node->nextNodes[i];
        if (tmpNode == nullptr) {
            continue;
        }
        
        char tmp = i + 'a';
        //strcpy时一定确保,copy后字符串结尾为'\0'

        int strTmpLen = strlen(base) + 1;
        char* strTmp = (char*) malloc(sizeof(char*) * strTmpLen);
        strcpy(strTmp, base);
        strcat(strTmp, &tmp);
        strTmp[strTmpLen] = '\0';
        
        if (tmpNode->count > 0) {
            result->push_back(strTmp);
        }
        TireNode::findPrefixStrResult(tmpNode, result, strTmp);
    }
}



