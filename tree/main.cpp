/**
* @file: main.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-12-05 15:39:38
* @brief
**/
#include "binary_tree.h"
#include "tire_tree.h"


int main(){
    /*vecint vecarr = {0,1,2,3,4,5,6,7,8,9};
    NodeElem* nodePtr = BinaryTree::build(&vecarr);
    cout << "preorder: ";
    BinaryTree::preorder(nodePtr);
    printArr(BinaryTree::preOrderArr);
    
    cout << "inOrder: ";
    BinaryTree::inorder(nodePtr);
    printArr(BinaryTree::inOrderArr);*/
    
    vecint preorderArr = {0, 1, 3, 7, 8, 4, 9, 2, 5, 6};
    vecint inorderArr = {7, 3, 8, 1, 9, 4, 0, 5, 2, 6};
    size_t len = preorderArr.size();
 
    NodeElem* nodeAfterPtr = BinaryTree::buildByOrder(&(preorderArr[0]), &(preorderArr[len-1]), &(inorderArr[0]), &(inorderArr[len-1]));
    //int* rootIndex = findIndex(&(inorderArr[0]), &(inorderArr[len-1]), preorderArr[0]);

    //cout << "rootIndex: " << rootIndex << " *rootIndex: " << *rootIndex << endl;
    BinaryTree::preorder(nodeAfterPtr);
    printArr(BinaryTree::preOrderArr);


    /*  TireNode   */
    /*char* s1 = "zhangzhida";
    char* s2 = "zhangzhida_raikken";
    char* s3 = "zhang_raikken";
    char* s4 = "zhangzhi";
    char* s5 = "zhang_haha";
    char* s6 = "zhang";
    char* s7 = "raikken";*/
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
    
    return 0;
}


