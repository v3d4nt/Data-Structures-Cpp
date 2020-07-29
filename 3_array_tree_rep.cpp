/*
    parent is p:
    for 0 index array:
    left is 2*p,
    right is 2*p+1

    below prog is for 1 index array
*/

#include <iostream>
using namespace std;

char tree[10];

void root(char key)
{
    if (tree[1] != '\0')
        cout << "root exist already";
    else
        tree[1] = key;
}

void set_right(char key, int parent)
{
    if (tree[parent] == '\0')
        cout << "Cant set child at " << (parent * 2) + 2 << ", no parent found";
    else
        tree[(parent * 2) + 1] = key;
}
void set_left(char key, int parent)
{
    if (tree[parent] == '\0')
        cout << "Cant set child at " << (parent * 2) + 1 << ", no parent found";
    else
        tree[parent * 2] = key;
}

void print_tree()
{
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] != '\0')
            cout << tree[i];
        else
            cout << "-";
    }
}
int main()
{
    root('A');
    set_left('B', 1);
    set_right('C', 1);
    set_left('D', 2);
    set_right('E', 2);
    set_right('F', 3);
    print_tree();
    cout << endl;
}