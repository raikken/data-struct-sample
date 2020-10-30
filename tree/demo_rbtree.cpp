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

public:
    Key key;
    Value value;
};

template<typename T>
struct MapConnCompator {
    bool operator()(const T& objA, const T& objB);
}

template<typename T>
bool MapConnCompator::operator()(const T& objA, const T& objB){
    return objA.key > objB;
}




void testRbTree(){
    MapCon<int, string> map1(1, "zhangzhida");
    MapCon<int, string> map2(2, "raikken");
    MapCon<int, string> map3(3, "zhang");
    MapCon<int, string> map4(4, "zhi");
    MapCon<int, string> map5(5, "da");
    MapCon<int, string> map6(6, "zhida");
    MapCon<int, string> map7(7, "raikken.zhang");
    MapCon<int, string> map8(8, "zhida.zhang");
    MapCon<int, string> map9(9, "raikken.zhida");

}


