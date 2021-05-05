#include <bits/stdc++.h>
using namespace std;
//using adjacency list
//time complexity- O(e+n)
//space complexity- O(n+2e)
int main()
{
    int n,e; //n=no. of nodes and e=no. of edges
    cin>>n>>e;
    vector<int>adj[n+1]; //declaring adjacency list
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;//taking edges as input
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"--> ";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//adjacency matrix
//Space Complexity O(n^2)
/*
int adj[n+1][m+1];
initialise adj[][] with zero
adj[u][v]=1;
adj[v][u]=1;
*/
