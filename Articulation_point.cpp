#include<bits/stdc++.h>
using namespace std;

int n; // number of nodes
vector<int> adj[1001]; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
void IS_CUTPOINT(int v)
{
	cout<<v<<" ";
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

int main() {
	int n,M;
	cin>>n>>M;
	int a,b;
	for(int i=0;i<M;i++)
 	{
 		cin>>a>>b;
 		adj[a].push_back(b);
 		adj[b].push_back(a);
	}
	
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    
    for (int i = 1; i <=n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
