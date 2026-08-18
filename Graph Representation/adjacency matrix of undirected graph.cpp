#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, e;
    cin >> n >> e;

    int adj[n][n];
    /*
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            adj[i][j] = 0;
        }
    }
    */
   /* shortcut - all element make 0 */
    memset(adj, 0, sizeof(adj)); //array, value, size

   
    /* diagonal = 1 */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if (i == j)
            adj[i][j] = 1;
        }  
    }

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        adj[a][b] = 1;
        adj[b][a] = 1; // direct e ai line skip
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

}