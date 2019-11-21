/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "array_header.h"


int Array::partation(vecint& vecarr, int start, int end, int pivotIndex){
    if(!vecarr.size()) {
        return 0;
    }
    int pivotVal = vecarr[pivotIndex];
    //1. exchange first and last element
    while(start != end){
        //start move first
        while(start < end && vecarr[start] <= pivotVal) start++;
        while(start < end && vecarr[end] >= pivotVal) end--;

        if(start < end){
            int tmp = vecarr[start];
            vecarr[start] = vecarr[end];
            vecarr[end] = tmp;
        }
    }
    //2. move intermediate element
    //because we move "start" first, when "start" meet "end", the start value may greater than pivotVal
    if(start < pivotIndex){
        //when "start" on the left side of pivotVal, we should exchange "pivotVal" and "start" 
        vecarr[pivotIndex] = vecarr[start];
        vecarr[start] = pivotVal;
    } else if(start > pivotIndex){
        //when "start" on the right side of pivotVal, we should exchange "pivotVal" and "start-1"
        //because the "start" greater than "pivotVal", the "pivotVal" one the left zone, the left zone only contains small element
        //the "start-1" value less than "pivotVal", so we should exchange these
        vecarr[pivotIndex] = vecarr[start-1];
        vecarr[start-1] = pivotVal;
    }

    return start;
}





