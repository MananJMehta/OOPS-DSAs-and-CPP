
/*
 * Assignment #12: Compare sorting algorithms
 *
 * CMPE 180-92 Data Structures and Algorithms in C++
 * Department of Computer Engineering
 * R. Mak, Nov. 20, 2016
 */
#include <iostream>
#include <math.h>
#include "ShellSortOptimal.h"

/**
 * Default constructor.
 */
ShellSortOptimal::ShellSortOptimal() {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Get the name of this sorting algorithm.
 * @return the name.
 */
string ShellSortOptimal::name() const { return "Shellsort optimal"; }

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
    //URL: https://en.wikipedia.org/wiki/Shellsort
    int gap, i, j;
    double n=size;
    int k;
    for( k=1;k<size;k++)
    {
        gap=pow(3,k);
        gap-=1;
        gap/=2;
        if(gap>size)
        {
            k=k-1;
            gap=pow(3,k);
            gap-=1;
            gap/=2;
            break;
        }
    }
    for (k ; k > 0; --k)
    {
        gap=pow(3,k);
        gap-=1;
        gap/=2;
        for (i = gap; i < n; i++)
        {
            for (j=i-gap; j>=0 && data[j]>data[j+gap] ; j-=gap)
            {
                swap(j,j+gap);
                compare_count++;
            }
            compare_count++;}
        }
}
