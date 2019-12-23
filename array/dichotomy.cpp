/**
* @file: merge.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-29 13:30:45
* @brief
**/
#include "array_header.h"


int Array::getMinValinSomeOrderArr(vecint& vecarr){
    int len = vecarr.size();
    if(len <= 2) {
        throw invalid_argument("prams.array too short");
    }

    int start = 0;
    int end = len-1;

    int midIndex;
    while(vecarr[start] >= vecarr[end]){
        if (end - start == 1) {
            midIndex = end;
            break;
        }
        
        midIndex = (start + end)/2;
        //three numbers are equal
        if (vecarr[midIndex] == vecarr[start] && vecarr[midIndex] == vecarr[end]) {
            int minVal = vecarr[0];
            for(int i = start; i <= end; i++){
                if(vecarr[i] < minVal) {
                    minVal = vecarr[i];
                }
            }
            return minVal;
        }
        
        if(vecarr[start] > vecarr[midIndex]) {
            end = midIndex;
        } else if(vecarr[midIndex] > vecarr[end]) {
            start = midIndex;
        }
    }

    return vecarr[midIndex];
}



