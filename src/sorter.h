#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>
using namespace std;

constexpr int NWORDS = 45392;

class Sorter
{
protected:
    vector<string> vec;
public:
    const string name;

    Sorter(string my_name) : name(my_name) { }
    void fill(int count, string file_name);
    void print(ostream & out);
    virtual void sort() = 0;
    bool verify_sorted();
};

class InsertionSorter : public Sorter
{
public:
    InsertionSorter() : Sorter("InsertionSorter") { }
    static void insertionsort(vector<string>& vec, int low, int high);
    void sort() override;
};

class QuickSorter : public Sorter
{
public:
    QuickSorter() : Sorter("QuickSorter") { }
    static string select_pivot(vector<string>& vec, int low, int high);
    static int partition(vector<string>& vec, int low, int high);
    static void quicksort(vector<string>& vec, int low, int high);
    void sort() override;
};

class HeapSorter : public Sorter
{
public:
    HeapSorter() : Sorter("HeapSorter") { }
    static void heapify(vector<string>& vec, int high, int root);
    static void heapsort(vector<string>& vec, int low, int high);
    void sort() override;
};

class IntroSorter : public Sorter
{
public:
    IntroSorter() : Sorter("IntroSorter") { }
    static void introsort(vector<string>& vec, int low, int high);
    void sort() override;
};

class STLSorter : public Sorter
{
public:
    STLSorter() : Sorter("STLSorter") { }
    void sort() override;
};

class StableSorter : public Sorter
{
public:
    StableSorter() : Sorter("StableSorter") { }
    void sort() override;
};

class ShellSorter : public Sorter
{
public:
    ShellSorter() : Sorter("ShellSorter") { }
    void gapInsertionSort(vector<string> & avector, int start, int gap);
    void shellSort(vector<string> & avector);
    void sort() override;
};

ostream & operator << (ostream & out, Sorter & L);
void error(string word, string msg);
void measure_partition(int k, string file_name, Sorter & L);
void measure_partitions(string file_name, Sorter & L);
void measure_sorters(string input_file);

#endif
