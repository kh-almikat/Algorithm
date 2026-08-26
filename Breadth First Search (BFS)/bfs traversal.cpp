#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1001];
bool visit[1001];


void bfs(int sourse_node) // time com - O(N+E) E- edge
{
    queue<int> q;
    q.push(sourse_node);
    visit[sourse_node] = true;

    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for(auto child : adj_list[parent])
        {
            if(visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
            }
        }

    }
}

int main() 
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visit, false, sizeof(visit)); // visit array all idx make false
    bfs(0);
}