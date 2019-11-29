/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "array_header.h"


void heapify(vecint& vecarr, int len, int topIndex){
    int leftNodeIndex = 2*topIndex + 1;
    int rightNodeIndex = 2*topIndex + 2;
    int tmpIndex = topIndex;

    if(rightNodeIndex < len && vecarr[rightNodeIndex] > vecarr[tmpIndex]){
        tmpIndex = rightNodeIndex;
    }

    if (leftNodeIndex < len && vecarr[leftNodeIndex] > vecarr[tmpIndex]){
        tmpIndex = leftNodeIndex;
    }

    if (tmpIndex != topIndex){
        heapify(vecarr, len, tmpIndex);
        swap(tmpIndex, topIndex, &vecarr);
    }
}


void Array::buildMaxHeap(vecint &vecarr){
    int len = vecarr.size(); 
    if (!len) {
        return;
    }

    for(int i = len/2; i >= 0; i--) {
        heapify(vecarr, len, i);
    }
}


void Array::insertForHeap(int num){
    int minHeapLen = this->minHeap.size();
    int maxHeapLen = this->maxHeap.size();

    if((minHeapLen + maxHeapLen) & 1){
        if(minHeapLen > 0) {
            this->maxHeap.push_back(num);
            push_heap(this->maxHeap.begin(), this->maxHeap.end(), less<int>());

            num = this->maxHeap.at(0);

            pop_heap(this->maxHeap.begin(), this->maxHeap.end(), less<int>());
            this->maxHeap.pop_back();
        }
        this->minHeap.push_back(num);
        push_heap(this->minHeap.begin(), this->minHeap.end(), greater<int>());
    } else {
        if(maxHeapLen > 0) {
            this->minHeap.push_back(num);
            push_heap(this->minHeap.begin(), this->minHeap.end(), greater<int>());

            num = this->minHeap.at(0);

            pop_heap(this->minHeap.begin(), this->minHeap.end(), greater<int>());
            this->minHeap.pop_back();
        }
        this->maxHeap.push_back(num);
        push_heap(this->maxHeap.begin(), this->maxHeap.end(), less<int>());
    }
}


double Array::findMedian(){
    int minHeapLen = this->minHeap.size();
    int maxHeapLen = this->maxHeap.size();

    if((minHeapLen + maxHeapLen) & 1){
        return (double)(this->minHeap.at(0));
    }

    return (double)(this->minHeap.at(0) + this->maxHeap.at(0))/2;
}


