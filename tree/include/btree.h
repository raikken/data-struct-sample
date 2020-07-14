/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "base_method.h"

#ifndef AVL_TREE_H__
#define AVL_TREE_H__

template<typename Key, typename Value, typename KeyofValue>
class Node {
    public:
        typedef Key key_type;
        typedef Value value_type;
        typedef Node* node_ptr;

        vector<Value> vlist;
        vector<Node> clist;
        node_ptr parent;
        node_ptr left;
        node_ptr right;
        int ways;
        
        Node(ways):ways(ways){};

        value_type get_max_value();
        value_type get_min_value();

        bool full();

        bool isleaf();
}

template<typename Key, typename Value, typename KeyofValue>
bool Node::isleaf(){
    return (this->clist.size() == 0)
}

template<typename Key, typename Value, typename KeyofValue>
value_type Node::get_max_value(){
    int len = vlist.size();
    return this->vlist.at(len-1);
}

template<typename Key, typename Value, typename KeyofValue>
value_type Node::get_min_value(){
    return this->vlist.at(0);
}

template<typename Key, typename Value, typename KeyofValue>
bool Node::full(){
    return (this->vlist.size() == this->ways);
} 

template<typename Key, typename Value, typename KeyofValue, typename Compare>
class BTree {
    public:
        typedef Key key_type;
        typedef Value value_type;
        typedef Value& reference;
        typedef const Value& const_reference;
        typedef Node<Key, Value, KeyofValue>* node_pointer; 

        node_pointer header;
        node_pointer root;

        int ways;
        
        BTree(ways) {
            node_pointer root  = new Node<Key, Value, KeyofValue>(ways);
            this->ways = ways;
            this->root = root;
        }

        //insert
        void insert(value_type val);

        //删除
        void delete(value_type val);

        //分裂节点
        node_pointer split(node_pointer xptr);

        //从左邻节点借值
        void borrow_from_value(node_pointer xptr, int index);

        //从右邻节点借值
        void borrow_from_value(node_pointer xptr, int index);

        //merge节点,默认和左节点merge
        void merge_node(node_pointer xptr, int index);

        //获取后继节点
        static node_pointer get_post_node(node_pointer xptr);
}

/**
 *@desc 分裂节点，分裂主逻辑如下:
 * 1. 新创建节点, 保留待分裂节点中(mid, full)元素。子节点同里
 * 2. 待分裂节点, 保留待分裂节点中(0, mid) 元素,子元素同里
 * 3. 中位数mid元素被添加至父节点中
 * 若待分裂节点为根节点, 因根节点没有父节点，则需要新创建根节点
 */
template<typename Key, typename Value, typename KeyofValue, typename Compare>
node_pointer BTree::split(node_pointer xptr){
    node_pointer newxptr = new Node(this->ways);//新创建节点
    int full = this->ways - 1;// 节点的满载个数为 阶数 - 1
    int mid = full/2; //中间节点
    splice(&(this->vlist), &(newxptr->vlist), mid+1, (full  - mid -1));
    splice(&(this->clist), &(newxptr->clist), mid+1, (this->ways - mid-1));

    if (newxptr->clist.size() > 0) {
        //重置父节点
        for (vector<Node>::iterator start = newxptr->clist.begin(); start < newxptr->vlist.end(); start++) {
            start->parent = newxptr;
        }
    }

    if (xptr == this->root) {//待分裂节点为根节点
        node_pointer newrootptr = new Node(this->ways);
        newrootptr->vlist.emplace_back(this->vlist[mid]);
        newrootptr->clist.emplace_back(xptr);
        newrootptr->clist.emplace_back(newxptr);
        xptr->parent = newrootptr;
        newxptr->parent = newrootptr;
    } else {//待分裂节点为非根节点
        int index = findIndex(&(xptr->parent->clist), xptr);
        xptr->parent->vlist.insert(xptr->parent->vlist.begin()+index, xptr->vlist[mid]);
        xptr->parent->clist.insert(xptr->parent->vlist.begin()+index+1, newxptr);
    }
    xptr->vlist.erase(xptr->vlist.begin() + mid, xptr->vlist.begin() + mid + 1);
    return xptr->parent;
}

/**
 *@desc 插入值, 递归插入
 */
template<typename Key, typename Value, typename KeyofValue, typename Compare>
void BTree::insert(node_pointer xptr, value_type val) {
    node_pointer xptr = (xptr == nullptr)? this->root: xptr;

    if (xptr->full()) {//当节点满载时，则先分裂节点再进行添加
        this->insert(this->split(xptr), val);
    } else {
        if (xptr->vlist.size() == 0) {
            xptr->vlist.emplace_back(val);
        } else {
            int pos = findPos(xptr->vlist, val);//查询节点所在区间
            if (xptr->leaf()){//叶子节点, 新增元素
                xptr->vlist->insert(pos, val);
            } else {//非叶子节点递归插入
                this->insert(xptr->clist[pos], val);
            }
        }
    }
}

template<typename Key, typename Value, typename KeyofValue, typename Compare>
node_pointer Btree::get_post_node(node_pointer xptr){   
    while(xptr->clist.size() > 0) {
        xptr = xptr->clist[0];
    }
    return xptr;
}

//从左节点处借值
template<typename Key, typename Value, typename KeyofValue, typename Compare>
void Btree::borrow_from_left(node_pointer xptr, int index){
    Value xparentval = xptr->vlist[index];

    int leftvlistlen = xptr->clist[index].vlist.size();
    xptr->vlist[index] = xptr->clist[index].vlist[leftvlistlen-1];
    xptr->clist[index].vlist.earse(leftvlistlen-1);

    xptr->clist[index+1].vlist.insert(0, xparentval);
}

//从右节点处借值
template<typename Key, typename Value, typename KeyofValue, typename Compare>
void Btree::borrow_from_right(node_pointer xptr, int index){
    Value xparentval = xptr->vlist[index];

    //int leftvlistlen = xptr->clist[index].vlist.size();
    xptr->vlist[index] = xptr->clist[index+1].vlist[0];
    xptr->clist[index+1].vlist.erase(0);

    xptr->clist[index].vlist.push_back(xparentval);
}

//merge左节点:
template<typename Key, typename Value, typename KeyofValue, typename Compare>
void Btree::merge_leftnode(node_pointer xptr, int index) {
    Value xmiddleValue = xptr->vlist[index-1];
    xptr->vlist.erase(index-1);
    node_pointer xleftptr = xptr->clist[index-1];
    xleftptr->vlist.push_back(xmiddleValue);

    xleftptr->vlist.merge(xptr->clist[index].vlist);
    delete xptr->clist[index];
    xptr->clist.erase(index);
}


//merge右节点:
template<typename Key, typename Value, typename KeyofValue, typename Compare>
void Btree::merge_rightnode(node_pointer xptr, int index) {
    Value xmiddleValue = xptr->vlist[index];
    xptr->vlist.erase(index);
    node_pointer xrightptr = xptr->clist[index+1];
    xrightptr->vlist.insert(0, xmiddleValue);

    for (int i=0; i < xptr->clist[index].vlist.size(); i++){
        xrightptr->vlist.insert(0, xptr->clist[index].vlist[i]);
    }
    delete xptr->clist[index];
    xptr->clist.erase(index);
}

//rebalance
template<typename Key, typename Value, typename KeyofValue, typename Compare>
void Btree::rebalance(node_pointer xptr, int index) {
    int minlen = this->ways/2;
    int fulllen = this->ways - 1;
    
    node_pointer xrealptr = xptr->clist[index];
    bool xrealstatus = xptr->clist[index].vlist.size() >= minlen;
    if (xrealstatus) {
        return ;
    }

    //删除值后, 节点值缺失
    bool xleftvlistover = xptr->clist[index-1].vlist.size() > minlen;
    bool xrightvlistover = xptr->clist[index+1].vlist.size() > minlen;
 
    if (index == 0) {//如果为首节点
        if (xrightvlistover) {
            borrow_from_right(xptr->clist[index], index);
        } else {
            merge_rightnode(xptr, index);
        }
        return ;
    }
   
    //左邻节点有节点富余
    if (xleftvlistover) {
        borrow_from_left(xptr->clist[index], index);
    } else {
    //左右节点均无节点富余, 默认选择和左邻节点merge
        merge_leftnode(xptr, index);
    }
}

/**
 *@desc 删除
 */
template<typename Key, typename Value, typename KeyofValue, typename Compare>
void Btree::delete(node_pointer xrootptr, Value value) {
    
    node_pointer xptr = (xptr == nullptr) ? this->root: xptr;
    int index = findPos(xptr.vlist, value);
    //节点中最大容量
    int fulllen = this->ways - 1;
    //节点中最小容量
    int mixlen = this->ways/2;

    int vlistlen = this->vlist.size();
    if (!xptr->leaf()) {//当前节点为非叶子节点
        // 待删除的值 在非叶子节点中
        if (index < vlistlen && Compare(xptr->vlist[index], value) == 0) {
            //寻找后继,进行替换
            node_pointer xpostnodeptr = Btree::get_post_node(this->vlist[index+1]);
            xptr->vlist[index] = xpostnodeptr->vlist[0];
            delete(xptr->clist[index+1], xpostnodeptr->vlist[0]);
            rebalance(xptr, index + 1);
        } else {
            //待删除的值不在当前非叶子节点中
            delete(xptr->clist[index], value);
            rebalance(xptr, index);
        }
    } else {
        //待删除的值在叶子节点中, 直接删除该值
        if (Compare(xptr->vlist[index], value) == 0) {
            xptr->vlist.earse(this->vlist[index].begin()+index, this->vlist[index].begin()+index+1);
        } else {
            //待删除的值,并不存在
            return nullptr;
        }
    }
}

#endif

