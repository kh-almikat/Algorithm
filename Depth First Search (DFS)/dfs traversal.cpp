#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[10001];
bool visit[10001];

void dfs(int src)
{
    cout << src << " ";
    visit[src] = true;

    for(auto child : adj_list[src])
    {
        if (!visit[child])
            dfs(child);
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

    dfs(0);
}