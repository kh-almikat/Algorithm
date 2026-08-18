#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, e;
    cin >> n >> e;

    vector<int> adj[n]; // array of vector

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << "->";

        for (auto i : adj[i])
            cout << i << " ";

        cout << endl;
    }
}