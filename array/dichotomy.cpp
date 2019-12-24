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


/*
 * @desc find the "val" appears number in a inorder array
 * @example input: vecarr->{1,2,3,3,3,3,4,5}, val->3: output-> 4
 * */
int Array::getAppearNuminOrderArr(vecint& vecarr, int val){
    
    int start = 0;
    int end = vecarr.size()-1;
    int startIndex;
    while(start < end) {
        if (end - start == 1) {
            if (vecarr.at(end) != val) {
                throw invalid_argument("val not in vecarr");
            }
            startIndex = end;
            break;
        }
        int midIndex = (start + end)/2;
        if (vecarr.at(midIndex) >= val) {
            end = midIndex;
        } else { 
            start = midIndex;
        }
    }

    start = 0;
    end = vecarr.size()-1;
    int endIndex;

    while(start < end) {
        if(end - start == 1){
            endIndex = start;
            break;
        }
        int midIndex = (start + end)/2;
        if (vecarr.at(midIndex) <= val) {
            start = midIndex;
        } else {
            end = midIndex;
        }
    }

    int nums = endIndex - startIndex + 1;
    return nums;
} 



