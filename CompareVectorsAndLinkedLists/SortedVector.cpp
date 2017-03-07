//
//  SortedVector.cpp
//  assignment9b
//
//  Created by Manan Mehta on 10/27/16.
//  Copyright © 2016 Manan Mehta. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
}

SortedVector::~SortedVector()
{
}

/***** Complete this file. *****/
void SortedVector::prepend(int value)
{
    vector<int>::iterator it;
    
    it = data.begin();
    it = data.insert ( it , value );
    
}
void SortedVector::append(int value)
{
    data.push_back (value);
}
bool SortedVector::find(int value) const
{
    vector<int>::const_iterator it;
   for (it = data.begin(); it != data.end();  it++)
    {
             if (*it == value) return true;
    }
   
    return false;
}
int SortedVector::get_value(int i) const
{
    vector<int>::const_iterator it=data.begin();
    return it[i];
}
void SortedVector::clear()
{
    vector<int>::iterator it;
    for (it = data.begin(); it != data.end(); )
        it=data.erase(it);
    
}


bool SortedVector::check()
{
    if (data.size() == 0) return true;
    
    vector<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}
