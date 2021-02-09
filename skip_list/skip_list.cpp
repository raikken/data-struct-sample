/**
* @file: skip_list.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2021-02-09 15:59:35
* @brief
**/
#include<iostream>
#include<vector>
#include<limits>
#include<random>
#include<ctime>
using namespace std;


template<typename T>
class SkipNode {
public:
    SkipNode(int key, T val, int level): key(key), value(val) {
        vector<SkipNode*> tmp(level, nullptr);
        this->next = tmp;
    }

    int key;
    int value;
    vector<SkipNode*> next;
};

template<typename T>
class SkipList {
public:
    SkipList(int level): maxLevel(level) {
        this->head = new SkipNode<int>(SkipList<T>::MinVal, 0, level);
        this->tail = new SkipNode<int>(SkipList<T>::MaxVal, 0, level);
        for (int i = 0; i < level; i++) {
            this->head->next[i] = this->tail;
        }
    }

    int getRandomLevel();

    SkipNode<T>* find(int key);

    SkipNode<T>* insert(int key, T val);

    void earse(int key);

    void print();

    static int MinVal;
    static int MaxVal;

    int maxLevel;
    SkipNode<T>* head;
    SkipNode<T>* tail;
};

template<typename T>
int SkipList<T>::MinVal = numeric_limits<int>::min();

template<typename T>
int SkipList<T>::MaxVal = numeric_limits<int>::max();

template<typename T>
int SkipList<T>::getRandomLevel() {
    int seed = time(0);
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<int> u(0, 1);
    int result;
    while(u(e) && result < this->maxLevel) {
        result ++;
    }

    return result;
}

template<typename T>
SkipNode<T>* SkipList<T>::find(int key) {
    SkipNode<T>* tmp = this->head;

    for (int i = this->maxLevel - 1; i > -1; i--) {
        while(tmp->next[i] != nullptr && tmp->next[i]->key < key) {
            tmp = tmp->next[i];
        }
    }

    if (tmp->next[0]->key == key) {
        return tmp->next[0];
    }

    return nullptr;
}

template<typename T>
SkipNode<T>* SkipList<T>::insert(int key, T value) {
    SkipNode<T>* node = this->find(key);

    if (node != nullptr) {
        node->value = value;
        return node;
    }

    int randomLevel = this->getRandomLevel();
    SkipNode<T>* newNode = new SkipNode<T>(key, value, this->maxLevel);
    SkipNode<T>* tmp = this->head;
    for (int i = randomLevel; i > -1; i--) {
        while(tmp->next[i] != nullptr && tmp->next[i]->key < key) {
            tmp = tmp->next[i];
        }

        newNode->next[i] = tmp->next[i];
        tmp->next[i] = newNode;
    }
    return newNode;
}

template<typename T>
void SkipList<T>::earse(int key) {
   SkipNode<T>* tmp = this->head;

    for (int i = this->maxLevel - 1; i > -1; i-- ) {
        //std::cout << "current: " << i << " tmp->next[i]: " << tmp->next[i] << std::endl;
        while (tmp->next[i] != nullptr && tmp->next[i]->key < key) {
            tmp = tmp->next[i];
        }
        if (tmp->next[i]->key == key) {
            tmp->next[i] = tmp->next[i]->next[i];
        }
    }
}

template<typename T>
void SkipList<T>::print() {
    for (int i = this->maxLevel - 1; i > -1; i--) {
        SkipNode<T>* tmp = this->head;
        if (tmp->key == SkipList<T>::MinVal && tmp->next[i]->key == SkipList<T>::MaxVal) {
            continue;
        }
        std::cout << "Level [ " << i << " ]: ";
        tmp = tmp->next[i];
        while (tmp->key != SkipList<T>::MaxVal) {
            std::cout << "[ " << tmp->key << ", " << tmp->value << "]";
            tmp = tmp->next[i];
        }
        std::cout << std::endl;
    }
}

int main() {

    SkipList<int>* skiplist = new SkipList<int>(32);

    vector<int> vecarr = {100, 110, 120, 130, 140, 150, 160, 170, 180};
    int index = 0;
    for (vector<int>::iterator iter = vecarr.begin(); iter != vecarr.end(); iter++) {
        skiplist->insert(index, *iter);
        ++index;
    }

    skiplist->print();

    skiplist->earse(3);
    std::cout << "after delete " << endl;
    skiplist->print();
    delete skiplist;

    return 0;
}
