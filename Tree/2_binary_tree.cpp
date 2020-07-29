/*
    Binary tree: (not BST)
    A tree having atmost 2 children.
    As atmost 2 children, we can say left and right child.

    Types:
    Full/Strictly binary tree: Every node must have 2 children except leaves.
    Almost complete/ incomplete BT: every node mjust have 2 children except 2nd last & last level and should be filled L to R
    Complete/perfect binary tree: every node must have 2 chil except leaf(each level there should be 2^L nodes where l is level)
    Right skewed B T: every node should have only right child; 

    diff bw strictly & complete BT:
    complete bt always contain 2 child except leaf node,in but strictly binary tree, we can have zero child at any level
*/
#include <iostream>
using namespace std;

struct Binary
{
    int data;
    Binary *left, *right;
    Binary(int data) : data{data}, left(nullptr), right{nullptr} {}
};

void print_dfs(Binary *root)
{
    Binary *temp = root;
    if (temp == nullptr)
        return;
    cout << temp->data << " ";
    print_dfs(temp->left);
    print_dfs(temp->right);
}
void print_bfs(Binary *root)
{
    Binary *temp = root;
}
void inorder(Binary *node)
{
    //Binary *temp = root;
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
void preorder(Binary *node)
{
    //Binary *temp = root;
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preorder(node->left);

    preorder(node->right);
}
void postorder(Binary *node)
{
    //Binary *temp = root;
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main()
{
    Binary *root = new Binary(1);
    root->left = new Binary(2);
    root->left->left = new Binary(4);
    root->right = new Binary(3);
    root->left->right = new Binary(5);

    cout << "DFS:-" << endl;
    print_dfs(root);
    cout << endl;
    cout << "Inorder:-" << endl;
    inorder(root);
    cout << endl;

    cout << "Pre-order:-" << endl;
    preorder(root);
    cout << endl;

    cout << "Post-order:-" << endl;
    postorder(root);
    cout << endl;
}
