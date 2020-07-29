/*
    USES Stack data structure
    1. push start node in stack and mark it visited
    2. while stack is not empty:
        pop out a node from stack and push all non visited adjacent node of popped nodein stack and mark them visited.
        GOTO step 2->

    It is an algorithm for traversal of graph/tree
    we can use stack of recursive approach.
    order of popping stack is order of traversal

    APPS:- 
    to find MST and all pair shortest path tree, detecting cycle in a graph, path finding, topological sorting, 
    Test if graph is bipartite, maze related problems, finding strongly connected compnent in graph
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> Vec;
vector<bool> visited;

void dfs_rec(int s)
{
    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < Vec[s].size(); i++)
    {
        if (visited[Vec[s][i]] == false)
            dfs_rec(Vec[s][i]);
    }
}

void dfs(const vector<vector<int>> &Vec, int s)
{
    stack<int> stk;
    stk.push(s);
    visited[s] = true;
    cout << "Visited: ";
    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();

        cout << node << " ";
        for (int i = 0; i < Vec[node].size(); i++)
        {
            if (!visited[Vec[node][i]])
            {
                stk.push(Vec[node][i]);
                visited[Vec[node][i]] = true;
            }
        }
    }
}
void initialize()
{
    for (int i = 0; i < visited.size(); i++)
        visited[i] = false;
}

int main()
{
    int nodes, edges, x, y;
    cout << "Enter nodes: ";
    cin >> nodes;
    cout << "Enter edges: ";
    cin >> edges;
    Vec.resize(nodes + 1);
    visited.resize(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        cin >> x >> y;
        Vec[x].push_back(y);
        Vec[y].push_back(x);
    }
    initialize();
    dfs_rec(1);
    initialize();
    dfs(Vec, 1); // may be different
    return 0;
}