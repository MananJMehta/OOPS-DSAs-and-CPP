

/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include "ShellSortSuboptimal.h"
#include "InsertionSort.h"

/**
 * Default constructor.
 */
ShellSortSuboptimal::ShellSortSuboptimal() {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string ShellSortSuboptimal::name() const { return "Shellsort suboptimal"; }

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    //URL: http://www.cplusplus.com/forum/general/123961/
    int gap, i, j;
    double n=data.size();
    for (gap = n/2; gap > 0; gap /= 2)
        
        for (i = gap; i < n; i++){
            
            for (j=i-gap; j>=0 && data[j]>data[j+gap]; j-=gap)
            {
                swap(j,j+gap);
                compare_count++;
            }
            compare_count++;
        }
}
   
