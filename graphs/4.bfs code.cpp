#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& adj)
{
    vector<bool> visited(adj.size(), false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}