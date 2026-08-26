#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[10005];
bool visit[10005];
int level[10005];
int parent[10005];

void bfs(int src)
{
    queue<int> q;

    q.push(src);
    visit[src] = true;
    level[src] = 0;
    // parent[src] = -1; no need for age to sob -1 kora

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(auto child: adj_list[par])
        {
            if(!visit[child])
            {
                q.push(child);

                visit[child] = true;
                level[child] = level[par] + 1;
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
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int src, dis;
    cin >> src >> dis;

    bfs(src);

    /* print shortest distance */
    cout << level[dis] << endl;

    /* print shortest path*/
    int node = dis;
    vector<int> path;

    while(node != -1)
    {
        path.push_back(node);
        node=parent[node];
    }

    reverse(path.begin(), path.end());

    for(auto x: path)
        cout << x << " ";
}