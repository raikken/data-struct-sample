/**
* @file: linkedList.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-10-30 22:14:08
* @brief
**/
#include<iostream>
#include<vector>
#include<unordered_map>
//#include "reverse.hpp"
using namespace std;

#ifndef LINKEDNODE_H__
#define LINKEDNODE_H__


class LinkedNode{
    //private:
    //    int _data;
    //    LinkedNode* _next;
    //    LinkedNode* _tmp;
    //    LinkedNode* _other;
    public:
        int _data;
        LinkedNode* _next;
        LinkedNode* _tmp;
        LinkedNode* _other;
        
        LinkedNode(int data):_data(data),_next(nullptr),_other(nullptr){};

        LinkedNode(const LinkedNode& obj);
        int getData();
        void printData();
        void setData(int data);
        void setNext(LinkedNode* next);
        LinkedNode* getOther();
        void setOther(LinkedNode* other);
        LinkedNode* getNext();
        //建立链表
        static LinkedNode* build(vector<int>* vecintptr);
        //print输出链表   
        static void printList(LinkedNode* headptr);
        //翻转输出
        static void reversePrintList(LinkedNode* nodeptr);
        //递归反转链表1, 两参数
        static LinkedNode* reverseLinkedNodeList1(LinkedNode* nodeptr, LinkedNode* objptr);
        //递归反转链表2, 单参数
        static LinkedNode* reverseLinkedNodeList2(LinkedNode* nodeptr);
        //非递归反转链表
        static LinkedNode* reverseLinkedNodeList3(LinkedNode* nodeptr);


        //检测链表是否有环
        static bool checkRing(LinkedNode* nodeptr);
        //获取倒数第n个节点
        static LinkedNode* getnthLast(LinkedNode* headptr,int n);


        //链表旋转
        static LinkedNode* rotate(LinkedNode* headptr,int n);


        //合并有序链表
        static LinkedNode* mergeOrderedList(LinkedNode* headptr1, LinkedNode* headptr2);
        //检测链表是否回文
        bool checkPalindrome(LinkedNode*);

        //copy复杂链表
        static LinkedNode* complexCopy(LinkedNode* headptr);
};

#endif


