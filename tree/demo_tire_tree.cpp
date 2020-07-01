/**
* @file: demo_tire_tree.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2020-03-16 20:08:32
* @brief
**/

#include "test_demo.h"

void testTireTree(){

    char* arrStr[] = {"zhangzhida", "zhangzhidaraikken", "zhangraikken", "zhangzhi", "zhanghaha", "zhang", "raikken"};

    TireNode* tiretree = new TireNode();

    for(int i = 0; i < length(arrStr); i++) {
        tiretree->insert(arrStr[i]);
    }

    int count = tiretree->prefixCount("zhang");
    vector<char*> searchResult;

    tiretree->search("zhang", &searchResult);
    
    cout << "prefixcount: " << count << endl;

    for(int i=0; i< searchResult.size(); i++){
        cout << searchResult.at(i) << endl;
    }

}
