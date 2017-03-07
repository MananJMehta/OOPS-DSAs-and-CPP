//
//  SortedVector.h
//  assignment9b
//
//  Created by Manan Mehta on 10/27/16.
//  Copyright © 2016 Manan Mehta. All rights reserved.
//

#ifndef SORTEDVECTOR_H_
#define SORTEDVECTOR_H_

#include <vector>
using namespace std;

class SortedVector
{
public:
    SortedVector();
    virtual ~SortedVector();
    
    void prepend(int value);
  void append(int value);
    bool find(int value) const;
    int get_value(int i) const;
    void clear();
    bool check();
    
private:
    vector<int> data;
};

#endif /* SORTEDVECTOR_H_ */
