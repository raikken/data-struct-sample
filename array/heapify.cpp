/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "array_header.h"


/*
 * @desc headpify 
 * @example input-> {1,2,5,9,4,7};  output-> {7,2,1,5,9,4}
 * */
void Array::heapify(vecint& vecarr, int len, int topIndex){
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
        Array::heapify(vecarr, len, tmpIndex);
        swap(&vecarr, tmpIndex, topIndex);
    }
}

/*
 * @desc build max heap
 * @example input-> {1,2,5,9,4,7};  output-> {9,1,7,5,2,4}
 * @prams vector<int>
 * @return null
 * */
void Array::buildMaxHeap(vecint &vecarr){
    int len = vecarr.size(); 
    if (!len) {
        return;
    }

    for(int i = len/2; i >= 0; i--) {
        Array::heapify(vecarr, len, i);
    }
}


/*
 * @desc for finding the median in the data stream, insert the num,  
 * @example build the maxHeap and minHeap 
 * */
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


/*
 * @desc for finding the median in the data stream,  
 * @example  
 * */
double Array::findMedian(){
    int minHeapLen = this->minHeap.size();
    int maxHeapLen = this->maxHeap.size();

    if((minHeapLen + maxHeapLen) & 1){
        return (double)(this->minHeap.at(0));
    }

    return (double)(this->minHeap.at(0) + this->maxHeap.at(0))/2;
}


