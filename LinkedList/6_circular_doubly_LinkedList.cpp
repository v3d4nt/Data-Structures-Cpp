/* 
    combo of circular and doubly
    advantage:
        could be traversed in both direction
        jumping from tail to head, or head to tail is O(1)
        used in FIBONACCI HEAP !important

    disadv:
        extra memory in each node
        lot of pointer involved
*/

#include <iostream>
using namespace std;

typedef struct CDLL
{
    int data;
    Node *next;
    Node *prev;
} Node;
