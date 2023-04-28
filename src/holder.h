#include <iostream>
using namespace std;

// constexpr int NWORDS = 45;
constexpr int NWORDS = 45392;

struct Holder
{
    const string name;
    Holder(const string & new_name)
        : name(new_name) { }

    virtual void insert( const string & word) = 0;
    virtual void remove() = 0;
    virtual string peek() = 0;
    virtual bool is_empty() = 0;
    virtual bool is_full() = 0;
    virtual void print(ostream & out) = 0;
    virtual ~Holder() { }
    Holder(const Holder & L) = delete;
    Holder& operator =(const Holder & L) = delete;
};

struct Stack
    : public Holder
{
    Stack(const string & new_name) : Holder(new_name) { }
    virtual void push(const string & word) = 0;
    virtual void pop() = 0;
    virtual string top() = 0;
 
    virtual void insert( const string & word) { push(word); }
    virtual void remove() { pop(); }
    virtual string peek() { return top(); }
};

struct Queue
    : public Holder
{
    Queue(const string & new_name) : Holder(new_name) { }
    virtual void enq(const string & word) = 0;
    virtual void deq() = 0;
    virtual string next() = 0;
 
    virtual void insert( const string & word) { enq(word); }
    virtual void remove() { deq(); }
    virtual string peek() { return next(); }
};

ostream & operator << (ostream & out, Stack & L);

class ArrayStack
    : public Stack
{
    const int capacity;
    int size;
    string * buf;
public:
    ArrayStack(int cap = NWORDS);
    void push(const string & word);
    void pop();
    string top();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~ArrayStack();
};


struct ListNode {
    string data;
    ListNode * next;
    ListNode(string new_data, ListNode * new_next)
        : data(new_data), next(new_next) { }
    static void print(ostream & out, ListNode * L);
    static void delete_list(ListNode * L);
};

class LinkedStack
    : public Stack
{

    ListNode * head;

public:
    LinkedStack();
    void push(const string & word);
    void pop();
    string top();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~LinkedStack();
};

class ArrayQueue
    : public Queue
{
    const int capacity;
    int front, rear;
    string * buf;
public:
    ArrayQueue(int cap = NWORDS);
    void enq(const string & word);
    void deq();
    string next();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~ArrayQueue();
};

class LinkedQueue
    : public Queue
{
    ListNode * head, * tail;
public:
    LinkedQueue();
    void enq(const string & word);
    void deq();
    string next();
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~LinkedQueue();
};

void error(string word, string msg);
void insert_all_words(int k, string file_name, Holder & L);
void remove_all_words(int k, string file_name, Holder & L);
void measure_holder(string file_name, Holder & L);
void measure_holders(string input_file);
