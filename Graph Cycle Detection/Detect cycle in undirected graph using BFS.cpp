#include <bits/stdc++.h>
using namespace std;


vector<int> adj_list[105];
bool visit[105];
int parent[105];
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    
    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par])
        {
            if(visit[child] && parent[par] != child)
                cycle = true;

            if(!visit[child])
            {
                q.push(child);
                visit[child] = true;
                parent[child] = par;
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

    memset(visit, false, sizeof(visit));
    memset(parent, -1, sizeof(parent));

    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if(!visit[i])
            bfs(i);
    }

    if(cycle)
        cout << "Cycle Detected";
    else
        cout << "Cycle Not Detected";
}