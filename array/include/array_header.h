/**
* @file: array_header.h
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:17:29
* @brief
**/
#include "base_method.h"



#ifndef ARRAY_H__
#define ARRAY_H__
class Array{
public:
    //partation算法
    static int partation(vecint& vecarr, int start, int end, int midIndex);

    static int findMedian(vecint* vecintptr); 

};

#endif


