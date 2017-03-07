#ifndef SORTEDLINKEDLIST_H_
#define SORTEDLINKEDLIST_H_

/***** Convert this to a class template to handle
 ***** multiple types of data stored in the nodes. */

#include <iostream>
#include "Node.h"

using namespace std;
template <typename S>
/**
 * A sorted linked list.
 */
class SortedLinkedList
{
public:
    SortedLinkedList();
    ~SortedLinkedList();
    
    Node<S> *get_head() const;
    
    Node<S> *find(S value) const;
    Node<S> *insert(S value);
    void remove(S value);
    void clear();
    
private:
    Node<S> *head;
};

/**
 * Default constructor.
 */
template <typename S>
SortedLinkedList <S> ::SortedLinkedList() : head(nullptr)
{
}

/**
 * Destructor.
 */
template <typename S>
SortedLinkedList <S> ::~SortedLinkedList()
{
    clear();
}

/**
 * @return the head.
 */
template <typename S>
Node<S> *SortedLinkedList <S> ::get_head() const { return head; }

/**
 * Find a node with a given value in the sorted list.
 * @param value the value of the node to find.
 * @return a pointer to the node if found, else nullptr.
 */
template <typename S>
Node<S> *SortedLinkedList <S> ::find(S value) const
{
    Node<S> *p = head;
    
    // Search the sorted list.
    while ((p != nullptr) && (value > p->data)) p = p->next;
    
    if ((p != nullptr) && (value == p->data)) return p;        // found
    else                                      return nullptr;  // not found
}

/**
 * Insert a node with a given value into the sorted list.
 * @param value the value for the node to insert.
 * @return a pointer to the inserted node.
 */
template <typename S>
Node<S> *SortedLinkedList <S> ::insert(S value)
{
    Node<S> *p = head;
    Node<S> *prev = p;
    Node<S> *new_node = new Node<S>(value);
    
    // Are we inserting the first node?
    if (head == nullptr)
    {
        head = new_node;
        return new_node;
    }
    
    // Will the insertion be the new head?
    else if (value < head->data)
    {
        new_node->next = head;
        head = new_node;
        return new_node;
    }
    
    // Look for where to insert in the sorted list.
    while ((p != nullptr) && (value >= p->data))
    {
        prev = p;
        p = p->next;
    }
    
    // Insert the node.
    prev->next = new_node;
    new_node->next = p;
    
    return new_node;
}

template <typename S>
void SortedLinkedList <S> ::remove(S value)
{
    Node<S> *p = head;
    Node<S> *prev = p;
    
    if (head == nullptr) return;
    
    // Is the value at the head?
    if (value == head->data)
    {
        Node<S> *next = head->next;
        delete head;
        head = next;
        return;
    }
    
    // Look for the node in the sorted list.
    while ((p != nullptr) && (value > p->data))
    {
        prev = p;
        p = p->next;
    }
    
    // If found, remove the node.
    if ((p != nullptr) && (value == p->data))
    {
        Node<S> *next = p->next;
        delete p;
        prev->next = next;
    }
}

/**
 * Clear the list of all nodes.
 */
template <typename S>
void SortedLinkedList <S> ::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node<S> *next = head->next;
        delete head;
        head = next;
    }
}

#endif /* SORTEDLINKEDLIST_H_ */
