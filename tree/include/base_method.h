/**
* @file: array_header.h
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:17:29
* @brief
**/
#ifndef BASEMETHOD_H__
#define BASEMETHOD_H__

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
using vecint = vector<int>;
using vecintiter = vector<int>::iterator;

//交换数组中位置
void swap(int a, int b, vecint* vecintptr);

//打印数组
void printArr(vecint* vecarr);
/*
//heapify
void heapify(vecint& vecarr, int topIndex);

vecint slice(vecint* vecarr, int a, int b);
*/

vecint* arrayMerge(vecint* vecarr1, vecint* vecarr2);

#endif
