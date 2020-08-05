// Store graph and trees in Vector of Vector.
// Adjacency list.
/* Types:
        undirected.
        undirected weighted
        directed
        directed weighted
        tree
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int edge;
    int weight;
};

void display(vector<vector<Node>> graph, int N, int E)
{
}

int main()
{
    int u, v, w, N, E;
    cin >> N >> E;
    vector<vector<Node>> Vec;
    Vec.resize(N + 1);
    while (E--)
    {
        cin >> u >> v >> w;
        Node node;
        node.edge = u;
        node.weight = w;
        Vec[u].push_back(node);
        node.edge = v;
        Vec[v].push_back(node);
    }
    return 0;
}