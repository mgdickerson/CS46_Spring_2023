#ifndef AVLTREE_H
#define AVLTREE_H

#include "bst.h"

class AVLTree
    : public BST
{
    static int get_height(Node * node);
    static int get_balance(Node * node);
    static void set_height(Node * node);
    static Node * right_rotate(Node * y);
    static Node * left_rotate(Node * x);
    static Node * rebalance(Node * t);
    static Node * insert_node(Node * t, string key);
    static Node * find_node(Node * t, string key);
    static Node * delete_node(Node * t, string key);
public:
    AVLTree();
    void insert(const string & key);
    bool find(const string & key) const;
    void remove(const string & key);
    bool is_empty() const;
    int get_height() const;
};

#endif
