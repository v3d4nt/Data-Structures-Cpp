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
void removeLoop(Node *loopNode)
{
    Node *ptr1 = head, *ptr2;
    while (1)
    {
        ptr2 = loopNode;
        while (ptr2->next != loopNode && ptr2->next != ptr1)
            ptr2 = ptr2->next;
        if (ptr2->next = ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
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
    {
        cout << "Loop detected!, removing loop";
        removeLoop(slow);
    }
    else
        cout << "No loops detected!";
}

int main()
{
    addToList(4);
    addToList(3);
    addToList(2);
    addToList(1);
    addToList(0);
    head->next->next->next = head->next;
    findLoop();
    cout << endl;
    findLoop();
    cout << endl;
}