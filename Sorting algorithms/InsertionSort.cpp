/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */

#include "InsertionSort.h"


/**
 * Default constructor.
 */
InsertionSort::InsertionSort() : VectorSorter() {
}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string InsertionSort::name() const { return "Insertion sort"; }

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    //http://cforbeginners.com/insertionsort.html

    int j, temp;
    double length= data.size();
    for (int i = 0; i < length; i++)
    {
        j=i;
        while(j>0)
        {
            if( data[j]<data[j-1] )
            {
                temp=data[j-1];
                data[j-1]=data[j];
                data[j]=temp;
                compare_count++;
                move_count++;
                j--;
            }
            else
            {
                compare_count++;
                break;
            }
            
        }
    }
}
