/**
* @file: demo_binary_tree.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2020-03-16 20:08:32
* @brief
**/

#include "test_demo.h"


template<typename Key, typename Value>
class MapCon {
public:

    MapCon(Key k, Value val):key(k), value(val){};      

    static int compare(const MapCon& map1, const MapCon& map2){
        if (map1.key == map2.key) {
            return 0;
        } else if(map1.key > map2.key) {
            return 1;
        } 
        return -1;
    }

private:
    Key key;
    Value value;
};

void testRbTree(){
    int int1 = 1;
    int int2 = 2;
    int int3 = 3;
    MapCon<int, string> map1(int1, "zhangzhida");
    MapCon<int, string> map2(int2, "raikken");
    MapCon<int, string> map3(int3, "zhang");
}


