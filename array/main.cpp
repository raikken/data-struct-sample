/**
* @file: main.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:25
* @brief
**/
#include "array_header.h"

int main(){

    vecint vecarr = {1,6,9,5,4};
    cout << "Origin arr: " << endl;
    printArr(&vecarr);
    int b = Array::partation(vecarr, 0, 4, 1);
    cout << "After Rank, midIndex: " << b << endl;
    printArr(&vecarr);
    
    return 0;
}
