/**
* @file: array_header.h
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:17:29
* @brief
**/
#ifndef BASEMETHOD_H__
#define BASEMETHOD_H__

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<stdexcept>
using namespace std;
using vecint = vector<int>;
using vecintiter = vector<int>::iterator;

//交换数组中位置
void swap(int a, int b, vecint* vecintptr);

vecint* arrayMerge(vecint* vecarr1, vecint* vecarr2);


template<typename T>
int findIndex(vector<T>* vecarr, T val){
    if(!vecarr) {
        throw invalid_argument("params.error");
    }

    size_t len = vecarr->size();
    for(int i = 0; i< len; i++){
        if(vecarr->at(i) == val){
            return i;
        }
    }
    return -1;
}


int* findIndex(int* startIndex, int* endIndex, int val);

template<typename T>
int length(T& arr){
    return sizeof(arr)/sizeof(arr[0]);
}


template<typename T>
void printArr(vector<T>* vecarr){
    if (vecarr->empty()) {
        return ;
    }

    string tmp;
    int size = vecarr->size();

    for(int i=0; i < size;i++) {
        string strtmp(to_string(vecarr->at(i))+",");
        tmp.append(strtmp);
    }
    cout << tmp << endl;
}

#endif
