/*
    Notes:
    it is one of tree/graph traversal algorithm
    it traverse level-wise
    it uses queue data structure for achieving order of traversal
    graph has cycle so we have to keep track of visited nodes and shouldnt visit again,
    to keep track of node, we keep array of boolean and make visited node boolean to true


    Usage:
    shortest path and MST for unweighted graph
    social nw website
    braodcasting in  network
    find all node within one connected  component

    ALGO:
    1. push start in queue and mark visited:
    2. until queue is not empty:
        pop out a node from queue and push non visited adjacent nodes in queue and mark them visited
        goto step 2.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> vec;
vector<bool> visited;

void bfs(int node)
{
    queue<int> list;
    list.push(node);
    visited[node] = true;
    while (!list.empty())
    {
        node = list.front();
        list.pop();
        cout << node << " ";
        for (int i = 0; i < vec[node].size(); ++i)
        {
            if (!visited[vec[node][i]])
            {
                list.push(vec[node][i]);
                visited[vec[node][i]] = true;
            }
        }
    }
}

int main()
{
    int N, u, v;
    cout << "N: ";
    cin >> N;
    vec.resize(N + 1);
    visited.resize(N + 1);
    while (N--)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cout << endl;
    bfs(1);
    cout << endl;
    return 0;
}
// N: 7
// 1 2
// 1 4
// 4 5
// 2 4
// 2 3
// 3 6
// 4 6