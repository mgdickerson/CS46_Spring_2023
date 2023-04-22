#include <string>
using namespace std;

constexpr int NWORDS = 45;
// constexpr int NWORDS = 45392;

struct SortedList
{
    const string name;
    SortedList(const string & new_name)
        : name(new_name) { }
    virtual void insert(const string & word) = 0;
    virtual bool find(const string & word) = 0;
    virtual void remove(const string & word) = 0;
    virtual bool is_empty() = 0;
    virtual bool is_full() = 0;
    virtual void print(ostream & out) = 0;
    SortedList(const SortedList & L) = delete;
    SortedList& operator =(const SortedList & L) = delete;
    virtual ~SortedList() { }
};

ostream & operator << (ostream & out, SortedList & L);

class SortedArrayList
    : public SortedList
{
    int capacity;
    int size;
    string * buf;
    int find_index(const string & word);
    void copy_down(int hole);
    void copy_up(int hole);
public:

    class iterator {
        std::string * ptr;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::string;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t;
        explicit iterator(pointer const p = nullptr) : ptr{p} {}
        iterator& operator++() {
            ++ptr;
            return *this;
        }
        iterator& operator--() {
            --ptr;
            return *this;
        }
        iterator operator++(int) {
            iterator copy{ptr};
            ++ptr;
            return copy;
        }
        iterator operator--(int) {
            iterator copy{ptr};
            --ptr;
            return copy;
        }
        iterator& operator+=(difference_type const d) {
            ptr += d;
            return *this;
        }
        iterator& operator-=(difference_type const d) {
            ptr -= d;
            return *this;
        }
        friend iterator operator+(iterator i, difference_type const d) {
            i += d;
            return i;
        }
        friend iterator operator-(iterator i, difference_type const d) {
            i -= d;
            return i;
        }
        friend difference_type operator-(iterator const i, iterator const j) {
            return i.ptr - j.ptr;
        }
        auto operator <=> (iterator const& other) const = default;
        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }
        reference operator[](difference_type const d) const { return ptr[d]; }
    };
    iterator begin() { return iterator{&buf[0]}; }
    iterator end() { return iterator{&buf[size]}; }


    SortedArrayList(int cap = NWORDS);
    void insert(const string & word);
    bool find(const string & word);
    void remove(const string & word);
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~SortedArrayList();
};

// static_assert(std::random_access_iterator<SortedArrayList::iterator>);

struct ListNode {
    string data;
    ListNode * next;
    ListNode(string new_data, ListNode * new_next)
        : data(new_data), next(new_next) { }
    static void print(ostream & out, ListNode * L);
    static void insert(const string & word, ListNode * & L);
    static ListNode * find(const string & word, ListNode * L);
    static void delete_list(ListNode * L);
    static void remove(const string & word, ListNode * & L);
};


class SortedLinkedList 
    : public SortedList
{

    ListNode * head;

public:
    class iterator {
        ListNode* current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = std::string;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t;
        explicit iterator(ListNode * const ptr = nullptr);
        iterator & operator ++ ();
        iterator operator ++ (int);
        reference operator *() const;
        pointer operator->() const;
        bool operator == (iterator const & other) const;
        bool operator != (iterator const & other) const;
    };
    iterator begin();
    iterator end();

    SortedLinkedList();
    void insert(const string & word);
    bool find(const string & word);
    void remove(const string & word);
    bool is_empty();
    bool is_full();
    void print(ostream & out);
    ~SortedLinkedList();
};

// static_assert(std::forward_iterator<SortedLinkedList::iterator>);

void error(string word, string msg);
void insert_all_words(int k, string file_name, SortedList & L);
void find_all_words(int k, string file_name, SortedList & L);
void remove_all_words(int k, string file_name, SortedList & L);
void measure_SortedList_methods(string file_name, SortedList & L);
void measure_lists(string input_file);
