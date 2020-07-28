/* 

    mod ver of singly linked list 
    last node points to first node
    advantages:
        cpu scheduling
        apps where dont want to reset when reach end
        queue can be implemented using one pointer(last) 
*/

#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *addToEmpty(Node *last, int data)
{
    if (last)
        return last;
    Node *temp = new Node();
    temp->data = data;
    last = temp;
    last->next = last;
    return last;
}

Node *addToEnd(Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
    Node *temp = new Node();
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

void traverse(Node *first)
{
    Node *temp = first;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != first);
    cout << "(repeat)";
    cout << endl;
}

int main()
{
    Node *last = NULL;
    last = addToEmpty(last, 10);
    last = addToEnd(last, 8);
    last = addToEnd(last, 6);
    last = addToEnd(last, 4);
    traverse(last->next);
    return 0;
}