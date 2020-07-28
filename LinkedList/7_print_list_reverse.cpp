#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    node *next;
} Node;
Node *head = NULL;

void addToList(int data)
{
    Node *ptr = new Node;
    ptr->data = data;
    if (head == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        ptr->next = head;
    }
    head = ptr;
    //printList();
}
void printList()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL";
}

void reverse()
{
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    addToList(4);
    addToList(3);
    addToList(2);
    addToList(1);
    printList();
    cout << endl;
    reverse();
    //cout << endl;
    cout << "After reversing: " << endl;
    printList();
    cout << endl;
}