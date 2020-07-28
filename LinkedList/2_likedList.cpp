/* //seq data structure
pros:
 dynamic, can grow and shrink
 insertion and del is easy at any position
cons:
 more mem is req, for pointer
 accessing ele is time consuming */

/* Uses of linked list

    implementation of stack, queue
    graph & tree uses adjacency list representation, LL is used for storing adjacent vertices
    dynamic mem alloc
    OS uses LL to loop through all processes

*/

#include <iostream>

using namespace std;

typedef struct LinkedList
{
    int data;
    LinkedList *next;
} LinkedList;

void printList(LinkedList *root)
{
    cout << endl;
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

int main()
{
    LinkedList *root, *second, *third;

    root = new LinkedList;
    second = new LinkedList;
    third = new LinkedList;

    root->data = 10;
    root->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printList(root);
}