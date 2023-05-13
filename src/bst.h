#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

// constexpr int NWORDS = 45;
constexpr int NWORDS = 45392;

struct Node
{
    string key;
    Node * left, * right;
    int height;
    Node(const string & new_key, Node * new_left=nullptr, Node * new_right=nullptr)
        : key(new_key),
          left(new_left), right(new_right),
          height(1)
    { }

};

struct BST
{
    Node * root;
    const string name;
    int count;

    BST(const string & new_name)
        : root(nullptr), name(new_name), count(0) { }

    virtual void insert( const string & word) = 0;
    virtual bool find( const string & word ) const = 0;
    virtual void remove( const string & word ) = 0;

    virtual bool is_empty() const = 0;
    virtual int size() const { return count; }
    virtual int get_height() const = 0;

    static void pre_order_print(ostream & out, Node * t);
    static void in_order_print(ostream & out, Node * t);
    static void post_order_print(ostream & out, Node * t);

    void print(ostream & out) const
    {
        // pre_order_print(out, root);
        in_order_print(out, root);
        // post_order_print(out, root);
    }

    virtual ~BST() = default;
    BST(const BST & L) = delete;
    BST& operator =(const BST & L) = delete;
};

ostream & operator << (ostream & out, BST & L);

void error(string word, string msg);
void insert_all_words(int k, string file_name, BST & L);
void remove_all_words(int k, string file_name, BST & L);
void measure_BST(string file_name, BST & L);
void measure_BSTs(string input_file);

#endif
