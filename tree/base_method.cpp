/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "base_method.h"


void swap(int a, int b, vecint* vecintptr){
    if (a == b){
        return ;
    }

    int tmp = vecintptr->at(a);
    (*vecintptr)[a] = vecintptr->at(b);
    (*vecintptr)[b] = tmp;
}

vecint* arrayMerge(vecint* vecarr1, vecint* vecarr2) {
    if (vecarr1 && !vecarr2) {
        return vecarr1;
    } else if (!vecarr1 && vecarr2) {
        return vecarr2;
    } else if (!vecarr1 && vecarr2) {
        return nullptr;
    }
    int len = vecarr2->size();
    for(int i=0; i< len;i++){
        vecarr1->push_back(vecarr2->at(i));
    }
    return vecarr1;
}


int* findIndex(int* startIndex, int* endIndex, int val){
    if (startIndex == endIndex && *startIndex == val) {
        return startIndex;
    }
    
    while(startIndex <= endIndex){
        if(*startIndex == val){
            return startIndex;
        }
        startIndex++;
    }

    return nullptr;
}


