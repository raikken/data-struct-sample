/**
* @file: array_header.h
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:17:29
* @brief
**/
#include "base_method.h"
class Array{
public:
    //partation
    static int partation(vecint& vecarr, int start, int end, int midIndex);
    static vecint findMiniList(vecint& vecarr,int nth);

    //buildMaxHeap
    static void buildMaxHeap(vecint &vecarr);
    //insert for heap
    void insertForHeap(int num);
    //find median
    double findMedian();

    
    //merge
    static vecint mergeSort(vecint& vecarr);


    //最大堆
    vecint minHeap;
    vecint maxHeap;
};




