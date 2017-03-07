
/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "MergeSort.h"

/**
 * Default constructor.
 */
MergeSort::MergeSort() : ListSorter() {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string MergeSort::name() const { return "Mergesort"; }

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();
    
    mergesort(data);
    
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
        to_string(size_before) + ", size after " +
        to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
    //URL: http://tinyurl.com/pyrhwdj
    /***** Complete this member function. *****/
    LinkedList a;
    LinkedList b;
    if( list.get_size()<2)  return;
    list.split(a, b);
    mergesort(a);
    mergesort(b);
    list.clear();
    merge(list,a, b);
    //list.print();
}


     /**
     * Merge two sublists back into a single list.
     * @param list the merged list.
     * @param sublist1 the first sublist.
     * @param sublist2 the second sublist.
     */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
    /***** Complete this member function. *****/
    
    while(sublist1.get_size()>0 && sublist2.get_size()> 0){
    
    if (sublist1.get_head()->value <= sublist2.get_head()->value){
        list.add(sublist1.get_head()->value);
        sublist1.remove_head();
        move_count++;
        compare_count++;
    }else{
        list.add(sublist2.get_head()->value);
        sublist2.remove_head();
        move_count++;
        compare_count++;
            }
    }
    while(sublist1.get_size()==0 && sublist2.get_size()>0)
    {
        list.add(sublist2.get_head()->value);
        sublist2.remove_head();
        move_count++;
    }
    while(sublist2.get_size()==0 && sublist1.get_size()>0)
    {
        list.add(sublist1.get_head()->value);
        sublist1.remove_head();
        move_count++;
    }
    
}
         /**
         * Clear the data.
         */
void MergeSort::clear()  {data.clear();}
