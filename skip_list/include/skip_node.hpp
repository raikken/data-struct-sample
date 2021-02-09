/**
* @file: skip_list.h
* @author: xxx
* @mail: xxx@yyy.com
* @date 2021-02-08 11:55:41
* @brief
**/


#ifndef SKIP_NODE_H
#define SKIP_NODE_H

#include<vector>

template<typename T>
class SkipNode {
public:

    SkipNode(int key, T value, int level): _key(key), _value(value) {
        std::vector<SkipNode<T>*> list(level, nullptr);
        //for (int i = 0; i < level; i++) {
        //    this->_next.push_back(nullptr);
        //}
        this->_next = list;
    };

    void setNext(int i, SkipNode<T>* node);

    int getKey();

    T& getValue();

    SkipNode<T>* getNextNode(int i);

    void setValue(T value);

private:
    std::vector<SkipNode<T>*> _next;
    int _key;
    T _value;
};

template<typename T>
int SkipNode<T>::getKey() {
    return this->_key;
}

template<typename T>
SkipNode<T>* SkipNode<T>::getNextNode(int i) {
    return this->_next.at(i);
}


template<typename T>
void SkipNode<T>::setNext(int i, SkipNode<T>* node) {
    this->_next[i] = node;
}


template<typename T>
void SkipNode<T>::setValue(T value) {
    this->_value = value;
}

template<typename T>
T& SkipNode<T>::getValue(){
    return this->_value;
}


#endif

