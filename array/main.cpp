/**
* @file: main.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:25
* @brief
**/
#include "array_header.h"



int main(){

    vecint vecarr = {1, 2, 5, 9, 6, 7};

    vecint vecarr1 = {1,2,5,9,4,7};
    cout << "origin Arr: ";
    printArr(&vecarr1);

    int midIndex = Array::partition(vecarr1, 0, vecarr1.size(), 2);
    cout << "after partition: ";
    printArr(&vecarr1);
    
    
    Array::buildMaxHeap(vecarr1);
    printArr(&vecarr1);

    Array* arrObj = new Array();
    for(int i=0; i< vecarr.size(); i++){
        arrObj->insertForHeap(vecarr.at(i));
    }

    double md = arrObj->findMedian();
    cout << "median: " << md << endl;
    
    cout << "##################" << endl; 
    vecint vectmp = {2,3};
    vecint vecMergeResultArr = Array::mergeSort(vecarr);
    cout << "after merge result arr: " << endl;
    printArr(&vecMergeResultArr);
    
    
    vecint vecarr2 = {3,2,4,7,6,5,1};
    Array::quickSort(vecarr2, 0, 7, 0);
    cout << "quickQuick: ";
    printArr(&vecarr2);
    return 0;
}
