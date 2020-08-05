#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    int height(Node *root)
    {
        // Write your code here.
        if (!root)
            return -1;
        int lh = height(root->left);
        int rh = height(root->right);
        return lh < rh ? rh + 1 : lh + 1;
    }

}; //End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;
    cout << "Enter the number of nodes: " << endl;
    cin >> t;
    cout << "Enter nodes is series (seperated by space: " << endl;
    while (t-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }

    int height = myTree.height(root);

    std::cout << "Height is " << height;

    return 0;
}
