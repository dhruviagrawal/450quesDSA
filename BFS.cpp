#include <bits/stdc++.h>
using namespace std;

//Time Complexity O(V+E)
vector<int>bfsOfGraph(int v, vector<int> adj[])
{
	vector<int>bfs;
	vector<int>vis(v,0);
	queue<int>q;
	q.push(0);//pushing first node in queue
    vis[0]=1; //marking it traversed
	while(!q.empty())
    {
	    int node=q.front();
	    q.pop();
        bfs.push_back(node);//putting the node in bfs
        for(auto i:adj[node]) //checking adjacent nodes of the bfs
	    {
	        if(vis[i]==0)
	        {
	            q.push(i); //pushing adjacent nodes
	            vis[i]=1; //marking it
	        }
	    }
	}
	return bfs;
}
int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i = 0; i < E; i++)
    {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
        //adj[v].push_back(u); here graph is directed
    }
    vector<int>ans = bfsOfGraph(V, adj);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
        cout<<endl;
    return 0;
}