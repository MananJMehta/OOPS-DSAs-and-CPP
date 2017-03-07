//
//  Person.cpp
//  assignment10b
//
//  Created by Manan Mehta on 11/3/16.
//  Copyright © 2016 Manan Mehta. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

/***** Write the constructors. *****/
Person::Person()
{
    
}
Person::Person(int level, string name)
{
    this->level=level;  // oldest ancestor is level 0
    this->name=name;
    this->parent=nullptr;
    
}
Person::Person(int level, string name, string spouse)
{
    this->level =level;  // oldest ancestor is level 0
    this->name = name;
    spouse_name=spouse;
    this->parent=nullptr;
}

/**
 * Destructor
 */
Person::~Person()
{
    /***** Complete this destructor: Recursively delete all the nodes. *****/
    if(children.size()==0)
        for(int i=0;i<children.size();i++)
            delete children.at(i);
    else
        for(int i=0;i<children.size();i++)
        children.at(i)->~Person();
}

/**
 * Have a child.
 * @param child pointer to the new child.
 */
void Person::have_child(Person *child)
{
    /***** Complete this member function. *****/
    child->parent = this;
    this->children.push_back(child);
}

/**
 * Print a person.
 */
void Person::print() const
{
    if (this->parent != nullptr)
    {
        cout<<"+---";
    }
    cout<<this->name;
    if (this->spouse_name != "\0")
    {
        cout<<" (" + this->spouse_name + ")";
    }
    cout<<endl;
    
    if(this->children.empty())
    {
        return;
    }
    else {
        
        for(int i = 0; i<this->children.size();i++)
        {
            this->children[i]->print_bar();
            this->children[i]->print();
        }
    }
    
}

/**
 * Print the vertical bar.
 */
void Person::print_bar() const
{
    /***** Complete this member function: Recursively print vertical bars. *****/
    if (this->parent->parent == NULL)
    {
        cout<<"|"<<endl;
        
    } else if (this->parent->parent->children.back() != this->parent)
    {
        if (this->parent->parent->parent != NULL && this->parent->parent->parent->children.back() == this->parent->parent)
        {
            cout<<"   ";
        }
        cout<<"|   ";
        this->parent->print_bar();
        cout<<"|   ";
    } else{
        if (this->parent->parent->parent != NULL && this->parent->parent->parent->children.back() == this->parent->parent)
        {
            cout<<"   ";
        }
        cout<<"   ";
        this->parent->print_bar();
        cout<<"   ";
    }
    
    
}
