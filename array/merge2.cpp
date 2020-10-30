/**
* @file: merge.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-29 13:30:45
* @brief
**/
#include "array_header.h"


vecint Array::mergeSort(vecint& vecarr){
    int vecarrlen = vecarr.size();
    if(vecarrlen < 2){
        return vecarr;
    }

    int midIndex = (vecarrlen-1) >> 1;
    vecint veclefthalf = slice(&vecarr, 0, midIndex);
    vecint vecrighthalf = slice(&vecarr, midIndex+1, vecarrlen-1);
    
    vecint vecarr1 = Array::mergeSort(veclefthalf);
    vecint vecarr2 = Array::mergeSort(vecrighthalf);
    vecint vecretarr;
    int arr1len = vecarr1.size();
    int arr2len = vecarr2.size();
    int a = 0;
    int b = 0;

    while(a < arr1len && b < arr2len){
        int tmp = vecarr1[a] < vecarr2[b] ? vecarr1[a++] : vecarr2[b++];
        vecretarr.push_back(tmp);
    }

    while(a < arr1len) {
        int tmpArr1 = vecarr1[a++];
        vecretarr.push_back(tmpArr1);
    }

    while(b < arr2len) {
        int tmpArr2 = vecarr2[b++];
        vecretarr.push_back(tmpArr2);
    }

    return vecretarr;
}

void Array::mergeSort2(vecint& vecarr, int startIndex, int endIndex) {
    if (startIndex == endIndex) {
        return ;
    }


} 

