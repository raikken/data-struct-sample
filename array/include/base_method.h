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
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
using vecint = vector<int>;
using vecintiter = vector<int>::iterator;

//交换数组中位置
void swap(vecint* vecintptr, int a, int b);

//打印数组
void printArr(vecint* vecarr);

vecint slice(vecint* vecarr, int a, int b);

#endif
