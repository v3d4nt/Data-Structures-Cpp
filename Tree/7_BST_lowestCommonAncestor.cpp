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

    Node *lca(Node *root, int v1, int v2)
    {
        // Write your code here.
        if (!root)
            return nullptr;
        if (root->data == v1 || root->data == v2)
            return root;
        Node *llca = lca(root->left, v1, v2);
        Node *rlca = lca(root->right, v1, v2);

        if (llca && rlca)
            return root;
        return llca ? llca : rlca;
    }

}; //End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;
    cout << "Enter no of nodes: " << endl;
    std::cin >> t;
    cout << "Enter nodes (separated by spaces):-" << endl;
    while (t-- > 0)
    {

        std::cin >> data;
        root = myTree.insert(root, data);
    }

    int v1, v2;
    cout << "Enter the two nodes: " << endl;
    std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

    std::cout << "Lowest common ancester is " << ans->data << endl;
    return 0;
}
/*
6
4 2 3 1 7 6
1 7
*/