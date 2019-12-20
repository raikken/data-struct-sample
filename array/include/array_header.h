/**
* @file: array_header.h
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:17:29
* @brief
**/

#ifndef ARRAY_HEADER__
#define ARRAY_HEADER__

#include "base_method.h"
class Array{
public:
    //partation
    static int partition(vecint& vecarr, int start, int end, int midIndex);
    static int partition(vecint& vecarr, int start, int end);
    static vecint findMiniList(vecint& vecarr,int nth);
    static void quickSort(vecint& vecarr, int start, int end, int pivotIndex);
    static void quickSort(vecint& vecarr);

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


#endif

