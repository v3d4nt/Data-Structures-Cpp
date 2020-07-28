#include <iostream>
#include <stdexcept>

using namespace std;

struct Node; // Forward declaration
             // XOR needs Node, and a small change to Node meant Node needed XOR
             // this struck me as the most-polite way to resolve the circle

// Unchanged
Node *XOR(Node *prev, Node *next)
{
    return (Node *)((uintptr_t)(prev) ^ (uintptr_t)(next));
}

struct Node
{
    int data;
    Node *npx;
    // add a constructor to make life easier. npx is always computed correctly
    Node(int data, Node *prev, Node *next) : data(data), npx(XOR(prev, next))
    {
    }
    // TODO: GetNext and GetPrev functions could be useful here. eg:
    Node *GetNext(Node *prev)
    {
        return XOR(prev, npx);
    }
    // Along  with a link(prev, next) function this would let you hide the XOR and
    // abstract away all external knowledge of how the linked list is connected from
    // the user.
};

// add a new node to linked list head is the beginning of the list
void Add(Node *&head, int data)
{ // note: using reference rather than double pointer
    if (head == nullptr)
    {                                            // no head, not much to do
        head = new Node(data, nullptr, nullptr); // there is no prev or next
                                                 // if there is only one node
    }
    else
    {
        // book keeping
        Node *prev = nullptr;             // last node visited. On first node, so null
                                          // NOTE: THIS IS A (sort of) LIE! This implementation
                                          // CANNOT be called with a Node from the the middle of a
                                          // a list. Sometimes you want this functionality (Why
                                          // search the whole damn list if you're already part
                                          // way through?) but to get it, you have to provide more
                                          // information so that you can recover the next pointer.
        Node *cur = head;                 // current node is head
        Node *next = XOR(prev, cur->npx); // next node is prev XOR npx
        // OR Node * next = cur->GetNext(prev);

        while (next != nullptr)
        { // there is a node here. Advance to next
            prev = cur;
            cur = next;
            next = XOR(prev, cur->npx);
        }
        // found last node. Append new node
        Node *newNode = new Node(data, cur, nullptr); // new tail node, so
                                                      // npx = current node XOR null
        cur->npx = XOR(prev, newNode);                // current node now has a next. Update npx
                                                      // here is where a cur->link(prev, newNode) function
                                                      // would be handy.
    }
}

//getting data from the list with given index
int Get(int index, Node *cur)
{
    Node *prev = nullptr; // is no previous node yet
    while (index &&       // exit when we've iterated far enough
           cur != nullptr)
    {                                     // or we've run out of nodes
        Node *next = XOR(prev, cur->npx); // find next node
        prev = cur;                       // update book keeping
        cur = next;
        index--; // one less iteration
    }
    if (index != 0) // oops.
    {
        // throwing exception rather than allowing the function to return an
        // incorrect value. Often the correct choice unless incorrect indexes
        // is a common occurrence. If something happens often it is not
        //exceptional and thus should not be an exception.
        throw std::out_of_range("index out of range");
    }
    return cur->data;
}

int main()
{
    Node *head = nullptr; //no need for dynamic allocation

    Add(head, 10); //
    Add(head, 2);
    Add(head, 42);                // added one more just to be sure
    cout << Get(0, head) << '\n'; // testing that the program can read all elements
    cout << Get(1, head) << '\n';
    cout << Get(2, head) << '\n';

    // TODO: iterate through list and free all of the allocated memory
    return 0;
}