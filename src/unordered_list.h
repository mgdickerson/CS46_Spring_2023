#include <string>
using namespace std;

constexpr int NWORDS = 45392;

struct UnorderedList
{
    const string name;
    UnorderedList(const string & new_name)
        : name(new_name) { }
    virtual void insert(const string & word) = 0;
    virtual bool find(const string & word) = 0;
    virtual void remove(const string & word) = 0;
    virtual bool is_empty() = 0;
    virtual bool is_full() = 0;
    virtual void erase() = 0;
    virtual void print(ostream & out) = 0;
    UnorderedList(const UnorderedList & L) = delete;
    UnorderedList& operator =(const UnorderedList & L) = delete;
    virtual ~UnorderedList() { }
};

class UnorderedArrayList
    : public UnorderedList
{
    int capacity;
    int size;
    string * buf;
    int find_index(const string & word);
public:
    UnorderedArrayList(int max_len);
    void insert(const string & word);
    bool find(const string & word);
    void remove(const string & word);
    bool is_empty();
    bool is_full();
    void erase();
    void print(ostream & out);
    ~UnorderedArrayList();
};

struct ListNode {
    string data;
    ListNode * next;
    ListNode(string new_data, ListNode * new_next)
        : data(new_data), next(new_next) { }
    static void print(ostream & out, ListNode * L);
    static ListNode * find(const string & word, ListNode * L);
    static void delete_list(ListNode * L);
    static void remove(const string & word, ListNode * & L);
};

class UnorderedLinkedList 
    : public UnorderedList
{

    ListNode * head;

public:

    UnorderedLinkedList();
    void insert(const string & word);
    bool find(const string & word);
    void remove(const string & word);
    bool is_empty();
    bool is_full();
    void erase();
    void print(ostream & out);
    ~UnorderedLinkedList();
};

ostream & operator << (ostream & out, UnorderedList & L);

void error(string word, string msg);
void insert_all_words(int k, string file_name, UnorderedList & L);
void find_all_words(int k, string file_name, UnorderedList & L);
void remove_all_words(int k, string file_name, UnorderedList & L);
void measure_UnorderedList_methods(string file_name, UnorderedList & L);
void measure_lists(string input_file);
