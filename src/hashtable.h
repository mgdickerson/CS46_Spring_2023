#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
using namespace std;

#include "hasher.h"
#include "stats.h"

// constexpr size_t NWORDS = 45;
constexpr size_t NWORDS = 45392;

struct ListNode {
    string data;
    ListNode * next;
    ListNode(string new_data, ListNode * new_next)
        : data(new_data), next(new_next) { }
    static ListNode * find(string key, ListNode * L);
    static ListNode * insert(string key, ListNode * L);
    static ListNode * remove(string key, ListNode * L);
    static void print(ostream & out, ListNode * L);
    static int length(ListNode * L);
    static void delete_list(ListNode * L);
};

class HashTable
{
    const Hasher & hasher;
    const size_t capacity;
    ListNode * * buf;
    const string name;
public:
    HashTable(const Hasher & h, size_t cap = NWORDS/45)
        : hasher(h),
          capacity(cap),
          buf(new ListNode *[cap]),
          name("ChainedHashTable")
    {
        for (size_t i=0; i<capacity; ++i)
            buf[i] = nullptr;
    }

    void insert( const string & word);
    bool find( const string & word);
    void remove( const string & word);
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~HashTable();
    HashTable(const HashTable & L) = delete;
    HashTable& operator =(const HashTable & L) = delete;

    string get_name() { return name + " using " + hasher.name; }
    size_t number_of_entries();
    size_t number_of_chains();
    void get_chain_lengths(vector<int> & v);
};

void error(string word, string msg);

void insert_all_words(string file_name, HashTable & L);
void find_all_words(string file_name, HashTable & L);
void remove_all_words(string file_name, HashTable & L);

void measure_hashtable(string file_name, HashTable & L);
void measure_hashtables(string input_file);

#endif
