/**
* @file: skip_list.h
* @author: xxx
* @mail: xxx@yyy.com
* @date 2021-02-08 11:55:41
* @brief
**/


#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include<limits>
#include<random>
#include<ctime>


#include "skip_node.hpp"

template<typename T>
class SkipList {
public:

    SkipList(int maxLevel, int initVal) : _maxLevel(maxLevel) {
        this->head = new SkipNode<T>(SkipList<T>::MinVal, initVal, maxLevel);
        this->tail = new SkipNode<T>(SkipList<T>::MaxVal, initVal, maxLevel);

        for (int i = 0; i < maxLevel; i++) {
            this->head->setNext(i, this->tail);
        }
    }

    SkipNode<T>* insert(int key, T value);

    SkipNode<T>* find(int key);

    SkipNode<T>* deleteOpt(int key);

    void print();
private:

    int getRandLevel();

    static int MinVal;
    static int MaxVal;

    SkipNode<T>* head;
    SkipNode<T>* tail;

    int _maxLevel;
};

 template<typename T>
 int SkipList<T>::MinVal = std::numeric_limits<int>::min();

 template<typename T>
 int SkipList<T>::MaxVal = std::numeric_limits<int>::max();


template<typename T>
SkipNode<T>* SkipList<T>::find(int key) {
    SkipNode<T>* tmp = this->head;

    for (int i = this->_maxLevel-1; i > -1; i--) {
        while (tmp != nullptr && tmp->getNextNode(i) != nullptr && tmp->getNextNode(i)->getKey() < key) {
            tmp = tmp->getNextNode(i);
        }
    }

    if (tmp->getNextNode(0) != nullptr && tmp->getNextNode(0)->getKey() == key) {
        return tmp->getNextNode(0);
    }

    return nullptr;
}


template<typename T>
int SkipList<T>::getRandLevel() {
    int seed = std::time(0);
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<int> u(0, 1);

    int randLevel = 0;

    while (u(e) && randLevel < this->_maxLevel) {
        randLevel++;
    }
    return randLevel;
}

template<typename T>
SkipNode<T>* SkipList<T>::insert(int key, T value) {
    SkipNode<T>* resultNode = this->find(key);
    if (resultNode != nullptr) {
        resultNode->setValue(value);
        return resultNode;
    }

    SkipNode<T>* node = this->head;
    int randLevel = this->getRandLevel();
    
    SkipNode<T>* newNode = new SkipNode<T>(key, value, this->_maxLevel);
    for (int i = randLevel; i > -1; i--) {
        while (node != nullptr && node->getNextNode(i) != nullptr && node->getNextNode(i)->getKey() < key) {
            node = node->getNextNode(i);
        }

        newNode->setNext(i, node->getNextNode(i));
        node->setNext(i, newNode);
    }

    return this->head;
}

template<typename T>
SkipNode<T>* SkipList<T>::deleteOpt(int key) {
    SkipNode<T>* tmp = this->head;
    SkipNode<T>* deleteNode = nullptr;
    for (int i = this->_maxLevel; i > -1; i--) {
        while (tmp != nullptr && tmp->getNextNode(i) != nullptr && tmp->getNextNode(i)->getKey() < key) {
            tmp = tmp->getNextNode(i);
        }

        if (tmp->getNextNode(i)->getKey() == key) {
            deleteNode = tmp;
            tmp->setNext(i, tmp->getNextNode(i)->getNextNode(i));
        }
    }

    return deleteNode;
}


template<typename T>
void SkipList<T>::print() {
    for (int i = 0; i < this->_maxLevel; i++) {
        SkipNode<T>* tmp = head;
        int lineLen = 1;

        if (tmp->getNextNode(i)->getKey() !=  SkipList<T>::MaxVal && tmp->getNextNode(i)->getKey() !=  SkipList<T>::MinVal) {
            std::cout << "\n";
            std::cout << "This is level " << i << ":" << std::endl;
            std::cout << "{";

            while (tmp->getNextNode(i) != nullptr && tmp->getNextNode(i)->getKey() != SkipList<T>::MinVal) {
                std::cout << "(" << "Key: " << tmp->getNextNode(i)->getKey() << ", ";
                std::cout << "Value: " << tmp->getNextNode(i)->getValue() << ")";

                tmp = tmp->getNextNode(i);

                if (tmp->getNextNode(i) != nullptr && tmp->getNextNode(i)->getKey() != SkipList<T>::MaxVal) {
                    std::cout << ", ";
                }

                if (lineLen++ % 5 == 0) std::cout << "\n";
            }
            std::cout << "}" << "\n";
        }
    }

}

#endif

