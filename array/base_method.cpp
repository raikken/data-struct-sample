/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "array_header.h"


void swap(int a, int b, vecint* vecintptr){
    if (a == b){
        return ;
    }

    int tmp = vecintptr->at(a);
    (*vecintptr)[a] = vecintptr->at(b);
    (*vecintptr)[b] = tmp;
}

void printArr(vecint* vecintptr){
    if(vecintptr->empty()){
        return ;
    }

    string tmp;
    int size = vecintptr->size();

    for(int i=0; i < size;i++) {
        string strtmp(to_string(vecintptr->at(i))+",");
        tmp.append(strtmp);
    }
    cout << tmp << endl;
}


