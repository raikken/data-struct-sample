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

        Value value;

        node_ptr parent;
        node_ptr left;
        node_ptr right;

        int height;

        Node(Value value):value(value), height(0){};

        Node():height(0){};

        static int height(node_ptr nodeptr);
}

template<typename Key, typename Value, typename KeyofValue>
int Node::height(node_ptr nodeptr) {
    if (nodeptr == nullptr) {
        return 0;
    }

    return nodeptr->height;
}

template<typename Key, typename Value, typename KeyofValue, typename Compare>
class AvlTree {
    public:
        typedef Key key_type;
        typedef Value value_type;
        typedef Value& reference;
        typedef const Value& const_reference;
        typedef Node<Key, Value, KeyofValue>* node_pointer; 

        node_pointer header;
        node_pointer root;

        AvlTree() {
            Node header = new Node<Key, Value, KeyofValue>();
            Node root  = new Node<Key, Value, KeyofValue>();

            header->left = root;
            header->right = root;
            root->parent = header;
            this->root = root;
            this->header = header;
        }

        //insert
        void insert(node_pointer nodeptr);

        void rotate_left(node_pointer xptr);

        void rotate_right(node_pointer xptr);

        //删除
        void delete(node_pointer xptr);

        void get_next_node(node_pointer node);
}


template<typename Key, typename Value, typename Keyofvalue, typename Compare>
void AvlTree::insert(node_pointer xrootptr, node_pointer nodeptr) {

    if (Compare(xrootptr, nodeptr)) {
        if (xrootptr->left != nullptr) {
            this->insert(xrootptr->left, nodeptr);
        } else {
            xrootptr->left = nodeptr;
        }

        if ((Node::height(xrootptr->left) - Node::height(xrootptr->right) == 2) {
            
            if (!Compare(xrootptr->left, nodeptr)) {
            //case LR: 先左旋
                rotate_left(xrootptr->left);
            }
            rotate_right(xrootptr);
        }
    } else {
        if (xrootptr->right != nullptr) {
            this->insert(xrootptr->right, nodeptr);
        } else {
            xrootptr->right = nodeptr;
        }

        if ((Node::height(xrootptr->right) - Node::height(xrootptr->left) == 1) {
            if (!Compare(xrootptr->right, nodeptr)) {
                rotate_right(xrootptr-xrootptr->right);
            }
            rotate_left(xrootptr)
        }
    }

    xrootptr->height = max(xrootptr->left->height, xrootptr->right->height) + 1;
}


template<typename key, typename value, typename keyofvalue, typename compare>
void AvlTree::rotate_left(node_pointer xptr){
    node_pointer xrightptr = xptr->right;

    xptr->right = xrightptr->left;
    xrightptr->left->parent = xptr->right;
    
    if (xptr == this->root) {
        this->root = xrightptr;
    } else if(xptr->parent->left == xptr) {
        xptr->parent->left = xrightptr;
    } else if (xptr->parent->right == xptr) {
        xptr->parent->right = xrightptr;
    }
    
    xrightptr->left =  xptr;
    xrightptr->parent = xptr->parent;
    xptr->parent = xrightptr;

    xptr->height = max(xptr->left->height, xptr->right->height) +1;
    xrightptr->height = max(xrightptr->left->height, xrightptr->right->height) + 1;
}


template<typename Key, typename Value, typename KeyofValue, typename Compare>
void AvlTree::rotate_right(node_pointer xptr) { 
    node_pointer xleftptr = xptr->left;
    
    xptr->left = xleftptr->right;
    xleftptr->right->parent = xptr->left;

    if (this->root == xptr) {
        this->root = xleftptr;
    } else if(xptr->parent->left == xptr) {
        xptr->parent-left = xleftptr;
    } else if(xptr->parent->right == xptr) {
       xptr->parent->right = xleftptr;
    }
    
    xleftptr->right = xptr;
    xleftptr->patent = xptr->parent;
    xptr->parent = xleftptr;

    xptr->height = max(xpr->left->height, xptr->right->height) + 1;
    xleftptr->height = max(xleftptr->left->height, xleftptr->right->height) + 1;
}

template<typename Key, typename Value, typename KeyofValue, typename Compare>
node_pointer AvlTree::check_node_exists(node_pointer xptr){
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
template<typename Key, typename Value, typename KeyofValue, typename Compare>
node_pointer AvlTree::get_post_node(node_pointer xptr){
    node_pointer xpostptr = xptr->right;
    if (!xpostptr) {
        return xpreptr;
    }

    while (xpostptr->left) {
        xpostptr = xpostptr->left;
    }

    return xpostptr;
}

//获取值小于该节点的最大节点
template<typename Key, typename Value, typename KeyofValue, typename Compare>
node_pointer AvlTree::get_pre_node(node_pointer xptr){
    node_pointer xpreptr = xptr->left;
    if (!xpreptr) {
        return xpreptr;
    }

    while (xpreptr->right) {
        xpreptr = xpreptr->right;
    }

    return xpreptr;
}


template<typename Key, typename Value, typename KeyofValue, typename Compare>
void AvlTree::delete(node_pointer xrootptr, node_pointer nodeptr) {

    if (Compare(xrootptr, nodeptr) > 0) {
    //待删除节点在左子树中
        this->delete(xrootptr->left, nodeptr);
        //当删除节点后引发失衡, 因删除了左子树节点， 遂右子树高度大于左子树
        if ((Node::height(xrootptr->right) - Node::height(xrootptr->left)) == 2) {
            node_pointer xrightchildptr = xrootptr->right;

            //当树失衡是内侧高度大于外侧，则需要双旋转
            if (Node::height(xrightchildptr->left) > Node::height(xrightchildptr->right)) {
                rotate_right(xrightchildptr);
            }
            rotate_left(xrootptr);
        }
        xrootptr->height = max(Node::height(xrootptr->left), Node::height(xrootptr->right)) + 1;
    } else if (Compare(xrootptr, nodeptr) < 0) {
    //待删除节点在右子树中, 
        this->delete(xrootptr->right, nodeptr);
    
        if ((Node::height(xrootptr->left) - Node::height(xrootptr->right)) == 2) {
            node_pointer xleftchildptr = xrootptr->left;

            if (Node::height(xleftchildptr->right) > Node::height(xleftchildptr->left))  {
                rotate_left(xleftchildptr);
            }
            rotate_right(xrootptr);
        }
        xrootptr->height = max(Node::height(xrootptr->left), Node::height(xrootptr->right)) + 1;
    } else {
    //找到了待删除节点
        if (xrootptr->left != nullptr && xrootptr->right != nullptr) {
        //找到的待删除节点为非叶子节点(左右子节点均不为空)时，需要找其后继节点，或预节点作为真正被删除的节点来替换
            node_pointer xrealptr = nullptr;
            node_pointer xnextsearchptr = nullptr;
            //寻找替换节点, 若左侧子树高则从左子树寻找,否则 则从右侧子树寻找
            if (Node::height(xrootptr->left) > Node::height(xrootptr->right)) {
                xrealptr = this->get_pre_node(xrootptr);
                xnextsearchptr = xrootptr->left;
            } else {
                xrealptr = this->get_post_node(xrootptr);
                xnextsearchptr = xrootptr->right;
            }
            //替换值
            xrootptr->value = xrealptr->value;
            //继续向下，删除真正的节点
            this->delete(xnextsearchptr, xrealptr);
            xnextsearchptr->height = max(Node::height(xnextsearchptr->left), Node::height(xnextsearchptr->right)) + 1;
        } else {
        //真正的删除节点, 此时删除的为叶子节点, 或仅有一个子节点的非叶子节点
            node_pointer xchildptr = nullptr;
            //若删除的为非叶子节点， 让其子节点来替换
            if ( xrootptr->left != nullptr ) {
                xchildptr = xrootptr->left;
            } else if (xrootptr->right != nullptr) {
                xchildptr = xrootptr->right;
            }

            if (xrootptr->parent->left == xrootptr) {
                xrootptr->parent->left = xchildptr;
            } else {
                xrootptr->parent->right = xchildptr;
            }
            delete xrootptr;
        }
    }
}

#endif

