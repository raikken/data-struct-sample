/**
* @file: base_method.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2019-11-16 17:16:52
* @brief
**/
#include "base_method.h"

#ifndef RB_TREE_H__
#define RB_TREE_H__

enum RBTColor{RED, BLACK};

template<typename Value>
class NodeIterator{
    public:
        typedef Value value_type;
        typedef Value* pointer;
        typedef const Value* const_pointer;
        typedef Value& reference;
        pointer cur;

        NodeIterator(pointer ptr) : cur(ptr) {};

        NodeIterator& operator++(){
        
        }

};
        
template<typename Key, typename Value>
class Node {
public:
    typedef NodeIterator<Value> iterator;

    typedef Key key_type;
    typedef Value value_type;
    typedef Node<Key, Value>* node_ptr;

    Node(Value value, node_ptr parent):value(value), parent(parent), left(left), right(right){};

    //判断该节点是否为红色节点
    bool isLeafNode();

    //获取叶子节点
    static Node<Key, Value>& getLeafNode(node_ptr parent);

public:
    Value value;

    RBTColor color;

    node_ptr parent;
    node_ptr left;
    node_ptr right;
};

template<typename Key, typename Value>
bool Node<Key, Value>::isLeafNode(){
    return this->color == BLACK && this->left == nullptr && this->right == nullptr;
}

//生成叶子节点
template<typename Key, typename Value>
Node<Key, Value>& Node<Key, Value>::getLeafNode(node_ptr parent){
    return Node<Key, Value>(NULL, BLACK, parent);
}


template<typename Key, typename Value, typename Compare>
class RbTree {
public:
    typedef Key key_type;
    typedef Value value_type;
    typedef Value& reference;
    typedef const Value& const_reference;

    typedef Node<Key, Value>* node_pointer; 
    typedef Node<Key, Value>& node_reference;

    RbTree() {
        node_reference header = Node<Key, Value>::getLeafNode(nullptr);
        node_reference root = Node<Key, Value>::getLeafNode(header);

        header->left = root;
        header->right = root;
            
        this->root = &root;
        this->header = &header;
    }

    //insert
    void insert(node_pointer nodeptr);
       
    //insert_rebalance
    void insert_rebalance(node_pointer xptr);

    void rotate_left(node_pointer xptr);

    void rotate_right(node_pointer xptr);

    //pre_delete_node
    node_pointer pre_delete_node(node_pointer xptr);

    //删除
    void delete_node(node_pointer xptr);

    void delete_rebalance(node_pointer xptr);

    void get_next_node(node_pointer node);
    
    //chcck node 是否存在
    node_pointer check_node_exists(node_pointer xptr);
    
    //获取后继节点
    node_pointer get_post_node(node_pointer xptr);
    
    //获取前缀节点
    node_pointer get_pre_node(node_pointer xptr);
public:
    node_pointer header;
    node_pointer root;
};


template<typename Key, typename Value, typename Compare>
void RbTree<Key, Value, Compare>::insert(node_pointer nodeptr) {
    node_pointer xptr = this->root;
    node_pointer xparentptr = this->header;

    //while(xptr != nullptr) {
    while(!xptr->isLeafNode()) {
        xparentptr = xptr;
        if (Compare(xptr, nodeptr)) {
            xptr = xptr->left;
        } else {
            xptr = xptr->right;
        }
    }

    nodeptr->parent = xparentptr;
    if (Compare(xparentptr, nodeptr)) {
        xparentptr->left = nodeptr;
    } else {
        xparentptr->right = nodeptr;
    }

    insert_rebalance(nodeptr);
}


//insert_rebalance
template<typename Key, typename Value, typename Compare>
void RbTree<Key, Value, Compare>::insert_rebalance(node_pointer xptr){
    xptr->color = RED;
    //重平衡条件, 当前不为root, 并且父节点颜色为红
    while(xptr != this->root && xptr->parent->color == RED) {
        node_pointer xparentptr = xptr->parent;
        //当父节点为祖父节点的左节点
        if (xparentptr->parent->left == xparentptr) {
            //伯父节点
            node_pointer xuncleptr = xparentptr->parent->right;
            //伯父节点存在且为红
            if (xuncleptr && xuncleptr->color == RED) {
                xparentptr->color = BLACK;
                xuncleptr->color = BLACK;
                xparentptr->parent->color = RED;
                xptr = xparentptr->parent;
            } else {
            //伯父节点不存在, 或者伯父节点为黑
                if (xptr == xparentptr->right) {
                    //xptr为内侧插入, 内侧插入旋转后, 出现父子节点同为红色, 当父子同时违背红黑树平衡原则时, 先解决子节点
                    xptr = xptr->parent;
                    rotate_left(xptr);//旋转不修改颜色, 参数为旋转的轴点
                }
                xptr->parent->color = BLACK;
                xptr->parent->parent->color = RED;
                rotate_right(xptr->parent->parent);
                //此处无需做xptr的上溯, 因此逻辑分支运行后,  红黑树已经平衡
            }
        } else {
            //当父节点为祖父节点的右节点
            node_pointer xuncleptr = xparentptr->parent->left;
            //叔父节点存在且为红
            if (xuncleptr && xuncleptr->color == RED){
                xparentptr->color = BLACK;
                xuncleptr->color = BLACK;
                xparentptr->parent->color = RED;
                xptr = xparentptr->parent;
            } else {
        
                // 叔父节点不存在, 或者叔父节点为黑
                if (xptr == xparentptr->left) {
                    //xptr为内侧插入
                    xptr = xparentptr;
                    rotate_right(xptr);
                }
                //外侧插入新节点
                xptr->parent->color = BLACK;
                xptr->parent->parent->color = RED;
                rotate_left(xptr->parent->parent);
            }
        }
    }
    this->root->color = BLACK;
}


template<typename Key, typename Value, typename Compare>
void RbTree<Key, Value, Compare>::rotate_left(node_pointer xptr){
    node_pointer originrightptr = xptr->right;
    xptr->right = originrightptr->left;

    originrightptr->parent = xptr->parent;
    
    if (xptr == this->root) {
        this->root = originrightptr;
    } else if(xptr->parent->left == xptr) {
        xptr->parent->left = originrightptr;
    } else {
        xptr->parent->right = originrightptr;
    }

    originrightptr->left = xptr;
    xptr->parent = originrightptr;
}


template<typename Key, typename Value, typename Compare>
void RbTree<Key, Value, Compare>::rotate_right(node_pointer xptr){
    node_pointer originleftptr = xptr->left;
    //originleftptr->right 挂载至 xptr->left
    xptr->left = originleftptr->right;
    originleftptr->right->parent = xptr;
    
    //将xptr父节点的子节点替换为originleftptr   
    originleftptr->parent =  xptr->parent;
    if (this->root == xptr) {
        this->root = originleftptr;
    } else if (xptr->parent->left == xptr) {
        xptr->parent->left = originleftptr;
    } else {
        xptr->parent->right = originleftptr;
    }
    //originleftptr替换为xptr的父节点
    originleftptr->right = xptr;
    xptr->parent = originleftptr;
}

template<typename Key, typename Value, typename Compare>
Node<Key, Value>* RbTree<Key, Value, Compare>::check_node_exists(node_pointer xptr){
    node_pointer xcurptr = this->root;

    while(xcurptr){
        if (xcurptr->Value == xptr->Value) {
            return xcurptr;
        } else if (Compare(xcurptr, xptr)) {
            xcurptr = xcurptr->left;
        } else {
            xcurptr = xcurptr->right;
        }
    }

    return xcurptr;
}

//获取值大于该节点的最小节点
template<typename Key, typename Value, typename Compare>
Node<Key, Value>* RbTree<Key, Value, Compare>::get_post_node(node_pointer xptr){
    node_pointer xpostptr = xptr->right;
    if (!xpostptr) {
        return xpostptr;
    }

    while (xpostptr->left) {
        xpostptr = xpostptr->left;
    }

    return xpostptr;
}

//获取值小于该节点的最大节点
template<typename Key, typename Value, typename Compare>
Node<Key, Value>* RbTree<Key, Value, Compare>::get_pre_node(node_pointer xptr){
    node_pointer xpreptr = xptr->left;
    if (!xpreptr) {
        return xpreptr;
    }

    while (xpreptr->right) {
        xpreptr = xpreptr->right;
    }

    return xpreptr;
}

//获取临近节点, 交换
template<typename Key, typename Value, typename Compare>
Node<Key, Value>* RbTree<Key, Value, Compare>::pre_delete_node(node_pointer xptr){

    //获取节点到交换
    node_pointer xpostptr = this->get_post_node(xptr);
    if (!xpostptr) {
        Value tmp = xptr->value;
        xptr->value = xpostptr->value;
        xpostptr->value = xptr->value;
        return xpostptr;
    }

    node_pointer xpreptr = this->get_pre_node(xptr);
    if (!xpreptr) {
       Value tmp = xptr->value;
       xptr->value = xpreptr->value;
       xpreptr->value = xptr->value;
       return xpreptr;
    }
    return xptr;
}

//balance delete node
//删除rebalance 本质上时 去掉 继任被删除节点 的节点 上的 双重黑色
template<typename Key, typename Value, typename Compare>
void RbTree<Key, Value, Compare>::delete_rebalance(node_pointer xptr) {

    while(xptr != this->root || xptr->color == BLACK) {
        node_pointer xparentptr = xptr->parent;
        if (xparentptr->left == xptr) {
            node_pointer xbrotherptr = xparentptr->right;

            //case1 兄弟节点为红色
            //父节点和兄弟节点调换颜色后 左旋
            if (xbrotherptr->color == RED) {
               xparentptr->color = RED;
               xbrotherptr->color = BLACK;
               rotate_left(xparentptr);

            } else if (xbrotherptr->color == BLACK && xbrotherptr->left->color == BLACK && xbrotherptr->right->color == BLACK) {
            //case 2 兄弟节点为黑色, 且兄弟节点的子节点为黑色
            //将xptr上的双重黑色 上移至父节点
                
                // 若父节点为红色, 则将xptr上的双重黑色移至父节点, 并将叔父节点改为红, 平衡完毕
                if (xparentptr->color == RED) {
                    xbrotherptr->color = RED;
                    xparentptr->color = BLACK;
                    break;
                } else {
                    // 若父节点也为黑色, 则重新while
                    xptr = xparentptr; 
                }
            } else if (xbrotherptr->color == BLACK && xbrotherptr->left->color == RED && xbrotherptr->right->color == BLACK){ 
            //case3 兄弟节点为黑色 且兄弟节点的子节点中 左为红 右为黑
            //左子节点和父节点换色, 然后右旋 后 改为case4
            
                xbrotherptr->left->color = BLACK;
                xparentptr->color = RED;
                rotate_right(xparentptr);
            } else if (xbrotherptr->color == BLACK && xbrotherptr->right->color == RED) {
            //case4 兄弟节点为黑色 右子节点为红色, 左子节点任意颜色
            //兄弟节点右子节点颜色 由红转黑, 并以父节点为旋点，左旋后 将xptr的双重黑色上移完毕。 平衡结束
                xbrotherptr->color = xparentptr->color;
                xparentptr->color = BLACK;
                xbrotherptr->right->color = BLACK;
                rotate_left(xparentptr);
                break;
            }

        } else if (xparentptr->right == xptr) {
           //对称的逻辑, 
           node_pointer xbrotherptr = xparentptr->left;
           //case1
           if (xbrotherptr->color == RED) {
               xbrotherptr->color = BLACK;
               xparentptr->color = RED;
               rotate_right(xparentptr);
           } else if (xbrotherptr->color == BLACK && xbrotherptr->left->color == BLACK && xbrotherptr->right->color == BLACK) {

            //case2
                if (xparentptr->color == RED) {
                    xbrotherptr->color = RED;
                    xparentptr->color = BLACK;
                    break;
                } else {
                   xptr = xparentptr; 
                }
            } else if (xbrotherptr->color == BLACK && xbrotherptr->right->color == RED && xbrotherptr->left->color == BLACK) {
            //case3
                xbrotherptr->right->color = BLACK;
                xbrotherptr->color = RED;
                rotate_left(xbrotherptr);
            } else if (xbrotherptr->color == BLACK && xbrotherptr->left == RED) {
            //case4    
                xbrotherptr->color = xparentptr->color;
                xbrotherptr->left->color = BLACK;
                rotate_right(xparentptr);
                break;
            }
        }
    }

    this->root->color = BLACK;
}


template<typename Key, typename Value, typename Compare>
void RbTree<Key, Value, Compare>::delete_node(node_pointer xptr){
    //pre_delete_node
    node_pointer xdeleteptr = pre_delete_node(xptr);

    node_pointer xdeletechildptr;
    if (xdeleteptr->left) {
        xdeletechildptr = xdeleteptr->left;
    } else {
        xdeletechildptr = xdeleteptr->right;
    }

    if (xdeleteptr->parent->left == xdeleteptr) {
        xdeleteptr->parent->left = xdeletechildptr;
    } else if (xdeleteptr->parent->right == xdeleteptr) {
        xdeleteptr->parent->right = xdeletechildptr;
    }

    if (xdeleteptr == this->root) {
        xdeleteptr->parent->left = xdeletechildptr;
        xdeleteptr->parent->right = xdeletechildptr;
    }

    //当删除的节点颜色为黑色
    if (xdeleteptr->color == BLACK) {
        if (xdeletechildptr->color == RED) {
            xdeletechildptr->color = BLACK;
        } else {
            rebalance_delete(xdeletechildptr);
        }
    }
}


#endif

