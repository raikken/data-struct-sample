/**
* @file: main.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2021-02-08 21:04:46
* @brief
**/
#include<iostream>
#include<vector>

#include "skip_list.hpp"

using namespace std;

int main() {

    SkipList<int> list(32, 0);
    vector<int> vecarr = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120};

    for (int i = 0; i < vecarr.size(); i++) {
        list.insert(i, vecarr.at(i));
    }

    list.print();

    return 0;
}
