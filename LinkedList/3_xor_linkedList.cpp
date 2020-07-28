/* 
    singly linked list acting doubly
    we can go fwd and reverse
    instead of address storing of next and prev node it stores xor of prev and next
    memory eff doubly LL


    XOR Linked List
    Data        A        B         C        D
    Next    0 XOR B   A XOR C  B XOR D  C XOR 0

    cons:
    debugging is hard
    code complexity
    garbage collection is difficult 

    FORMULA:
        next = (address of previous XOR current->npX)
        prev = (address of next XOR current->npx)
*/

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
struct Node
{
    int data;
    Node *link;
};

// helper fn to return xor of x and y
Node *XOR(Node *x, Node *y)
{
    return (Node *)((uintptr_t)(x) ^ (uintptr_t)(y));
}

void traverse(Node *head)
{
    Node *curr = head, *prev = nullptr, *next;

    while (curr != nullptr)
    {
        cout << curr->data << "->";
        next = XOR(prev, curr->link);
        prev = curr;
        curr = next;
    }
    cout << "nullptr";
}

// fn to insert node
void push(Node *&headref, int data)
{
    // allocate new list
    Node *newNode = new Node();
    newNode->data = data;
    newNode->link = XOR(headref, nullptr);
    // update link value of head if LL is not empty
    if (headref)
    {
        headref->link = XOR(newNode, XOR(headref->link, nullptr));
    }
    headref = newNode;
}
int main()
{
    cout << endl;
    Node *head = nullptr;
    vector<int> keys = {1, 4, 6, 8, 9};
    for (int i = 0; i < keys.size(); i++)
        push(head, keys[i]);

    traverse(head);
    cout << endl;
}