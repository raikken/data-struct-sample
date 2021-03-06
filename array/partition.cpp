/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "array_header.h"


int Array::partition(vecint& vecarr, int start, int end){
    //record the last index in left zone
    int vecarrLen = vecarr.size();
    if(start < 0  ||  end >= vecarrLen) {

    }
    int k = start;
    int pivotIndex = end;
    for(int i = start; i < end; i++) {
        if(vecarr[i] <= vecarr[pivotIndex] ){
            if(i != k){
                swap(&vecarr, i, k);
            }
            k++;
        }
    }
    swap(&vecarr, k, end);
    return k;
}



int Array::partition(vecint& vecarr, int start, int end, int pivotIndex){
    if(!vecarr.size()) {
        return 0;
    }
    int pivotVal = vecarr[pivotIndex];
    int startIndex  = start;
    int endIndex = end;
    int resultMidIndex = pivotIndex;
    
    //1. exchange first and last element
    while(startIndex != endIndex){
        //startIndex move first
        while(startIndex < endIndex && vecarr[startIndex] <= pivotVal) startIndex++;
        while(startIndex < endIndex && vecarr[endIndex] >= pivotVal) endIndex--;

        if(startIndex < endIndex){
            int tmp = vecarr[startIndex];
            vecarr[startIndex] = vecarr[endIndex];
            vecarr[endIndex] = tmp;
        }
    }
    //2. move intermediate element
    //because we move the "startIndex" first, when the "startIndex" meet the "endIndex", the start value may greater than pivotVal
    //note: if the "endIndex" equals "end", the "endValue" may be smaller than pivotVal. small value should be on the left 
    if(startIndex < pivotIndex || (endIndex == end && vecarr[startIndex] < pivotVal)){
        //when the "start" on the left side of pivotVal, we should exchange the "pivotVal" and "start" 
        vecarr[pivotIndex] = vecarr[startIndex];
        vecarr[startIndex] = pivotVal;
        resultMidIndex = startIndex;
    } else if(startIndex > pivotIndex && (startIndex-1) != pivotIndex) {
        //when the "startIndex" on the right side of pivotVal, we should exchange the "pivotVal" and the "start-1"
        //because the "start" greater than "pivotVal", the "pivotVal" one the left zone, the left zone only contains small element
        //the "start-1" value less than "pivotVal", so we should exchange these
        vecarr[pivotIndex] = vecarr[startIndex-1];
        vecarr[startIndex-1] = pivotVal;
        resultMidIndex = startIndex-1;
    }

    return resultMidIndex;
}


vecint Array::findMiniList(vecint& vecarr,int nth){
    vecint vecresult;
    if(!vecarr.size()){
        return vecresult;
    }

    int start = 0;
    int len = vecarr.size();
    int end = len - 1;
    int needIndex = nth - 1;
    int resultIndex = Array::partition(vecarr, start, end, needIndex);

    while (needIndex != resultIndex) {
        if (needIndex > resultIndex) {
            start += 1;
        } else {
            end -= 1;
        }
        resultIndex = Array::partition(vecarr, start, end, needIndex);
    }

    for(int i=0; i< nth; i++){
        vecresult.push_back(vecarr.at(i));
    }
    return vecresult;
}


void Array::quickSort(vecint& vecarr, int start, int end, int pivotIndex) {

    int realPivotIndex = Array::partition(vecarr, start, end, pivotIndex);

    if(start + 1 < realPivotIndex) {
        Array::quickSort(vecarr, start, realPivotIndex-1, start);
    }

    if (realPivotIndex + 1 < end) {
        Array::quickSort(vecarr, realPivotIndex+1, end, realPivotIndex+1);
    }
}


void Array::quickSort(vecint& vecarr) {
    int len  = vecarr.size();
    if (len < 2) {
        return ;
    }

    stack<int> stackList;
    int start = 0;
    int end = vecarr.size() - 1;

    stackList.push(start);
    stackList.push(end);

    while (!stackList.empty()) {
        end = stackList.top();
        stackList.pop();
        start = stackList.top();
        stackList.pop();

        int realPivotIndex = Array::partition(vecarr, start, end, start);

        if (start + 1 < realPivotIndex) {
            stackList.push(start);
            stackList.push(realPivotIndex-1);
        }

        if (realPivotIndex + 1 < end) {
            stackList.push(realPivotIndex+1);
            stackList.push(end);
        }
    }
}


