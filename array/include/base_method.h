/**
* @file: array_header.h
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:17:29
* @brief
**/

#ifndef ARRAY_BASEMETHOD__
#define ARRAY_BASEMETHOD__

#include<iostream>
#include<vector>
#include<string>
using namespace std;
using vecint = vector<int>;
using vecintiter = vector<int>::iterator;

//交换数组中位置
void swap(int a, int b, vecint* vecintptr);

//打印数组
void printArr(vecint* vecarr);


#endif

