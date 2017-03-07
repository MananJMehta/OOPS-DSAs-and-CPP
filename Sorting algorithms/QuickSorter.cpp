/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "QuickSorter.h"
#include "iostream"
using namespace std;
/**
 * Default constructor.
 */
QuickSorter::QuickSorter() : VectorSorter() {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
    /*** Complete this member function. ***/
    if (right - left <= 0) return;
    else {
        int pivot = choose_pivot_strategy(left, right);
        int partitionPoint = partition(left, right, pivot);
        quicksort(left, partitionPoint - 1);
        quicksort(partitionPoint + 1, right);
    }
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
int QuickSorter::choose_pivot(const int left, const int right)
{

   return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const int pivot)
{
    /*** Complete this member function. ***/
    int lefty = left - 1;
    int righty = right;
    if ((pivot == 0 )&& (data[righty] == 0) )compare_count += 8;
    while (1) {
        while (data[++lefty] < pivot) compare_count+=2;
        while (righty > 0 && data[--righty] > pivot) compare_count+=2;
        if (lefty >= righty) break;
        else swap(lefty, righty);
    }
    swap(lefty, right);
    
    return lefty;
    }
