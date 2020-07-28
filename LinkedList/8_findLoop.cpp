/* 
    Mark each node
    keep hash set of all nodes so far
    tortoise and hare algo(fast and slow)
*/

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
void findLoop()
{
    Node *slow = head, *fast = head;
    int flag = 0;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            flag = 1;
            break;
        }
        }
    if (flag == 1)
        cout << "Loop detected!";
    else
        cout << "No loops detected!";
}
void makeLoop()
{
    Node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head;
}

int main()
{
    addToList(4);
    addToList(3);
    addToList(2);
    addToList(1);
    cout << endl;
    findLoop();
    cout << endl;
    makeLoop();
    findLoop();
}