#ifndef NODE_H_
#define NODE_H_

/***** Convert this to a class template to handle
 ***** multiple types of data stored in the nodes. */

using namespace std;
template < typename S>
class Node
{
public:
    Node( S value);
    ~Node();
    
    S data;
    Node<S> *next;
};

template <typename S>
Node<S> ::Node(S value) : data(value), next(nullptr)
{
}
template <typename S>
Node<S> ::~Node()
{
}

#endif /* NODE_H_ */
