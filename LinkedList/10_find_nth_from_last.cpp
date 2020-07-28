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

void findNthFromLast(int n)
{
    Node *ptr = head, *qtr = head;
    for (int i = 0; i < n; i++)
        ptr = ptr->next;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        qtr = qtr->next;
    }
    cout << n << " node from last is " << qtr->data;
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

int main()
{
    for (int i = 10; i > 0; i--)
        addToList(i);
    cout << endl;
    printList();
    cout << endl;
    findNthFromLast(3);
    cout << endl;
}