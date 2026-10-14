#include <bits/stdc++.h>
using namespace std;


vector<int> adj_list[105];
bool visit[105];
bool path_visit[105];
bool cycle;

void dfs(int src)
{
    visit[src] = true;
    path_visit[src] = true;

    for(int child : adj_list[src])
    {
        if(visit[child] && path_visit[child])
            cycle = true;

        if(!visit[child])
        {
            dfs(child);
        }
    }
    path_visit[src] = false;
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
    }

    memset(visit, false, sizeof(visit));
    memset(path_visit, false, sizeof(path_visit));

    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if(!visit[i])
            dfs(i);
    }

    if(cycle)
        cout << "Cycle Detected";
    else
        cout << "Cycle Not Detected";
}