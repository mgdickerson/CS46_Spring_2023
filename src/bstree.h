#ifndef BSTREE_H
#define BSTREE_H

#include "bst.h"

class BSTree
    : public BST
{
    static Node * insert_node(Node * t, string key);
    static Node * find_node(Node * t, string key);
    static Node * left_most(Node * t);
    static Node * delete_node(Node * t, string key);
    static int compute_height(Node * t);
public:
    BSTree();
    void insert(const string & key);
    bool find(const string & key) const;
    void remove(const string & key);
    bool is_empty() const;
    int get_height() const;
};

#endif
