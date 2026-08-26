#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[10005];
bool visit[10005];
int level[10005];


void bfs(int src)
{
    queue<int> q;

    q.push(src);
    visit[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : adj_list[par])
        {
            if (!visit[child])
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visit, false, sizeof(visit));
    memset(level, -1, sizeof(level));

    int src, dis;
    cin >> src >> dis;

    bfs(src);

    /*
    node r level print 
    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << level[i] << endl;
    }
    */


    // Shortest distance print
    cout << level[dis] << end;
}