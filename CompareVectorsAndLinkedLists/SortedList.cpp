//
//  SortedList.cpp
//  assignment9b
//
//  Created by Manan Mehta on 10/27/16.
//  Copyright © 2016 Manan Mehta. All rights reserved.
//


#include <iostream>
#include <iterator>
#include <algorithm>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
}

SortedList::~SortedList()
{
}

/***** Complete this file. *****/
void SortedList::prepend(int value)
{
    list<int>::iterator it;
    
    it = data.begin();
    it = data.insert ( it , value );
}
void SortedList::append(int value)
{

    data.push_back (  value );
}
bool SortedList::find(int value) const
{
    list<int>::const_iterator it;
  
    for(it=data.begin(); it!=data.end(); it++)
    {
        if (*it == value) return true;
    }
    
    return false;

}
int SortedList::get_value(int i) const
{

       double x=data.size();
    
   
    
    
   if(i<x/2)
    {
        double j=0;
        list<int>::const_iterator it = data.begin();
       
        while(j<i)
        {
            it++;
            j++;
        }
        return *it;
    }
    else if(i>=x/2)
    {
        
        list<int>::const_reverse_iterator rit= data.rbegin();
        
       
       while(x!=i+1)
        {
            
            
            rit++;
            x--;
            
            
        }
      
       
        return *rit;
    }
    
    else
     return 0;
}
void SortedList::clear()
{
    list<int>::iterator it;
    for (it = data.begin(); it != data.end(); )
    it=data.erase(it);
}



bool SortedList::check()
{
    if (data.size() == 0) return true;
    
    list<int>::iterator it = data.begin();
    int prev = *it;
    while ((++it != data.end()) && (prev <= *it));
    return it == data.end();
}
