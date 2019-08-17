#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> res;
vector<bool> visited;
void Explore(int a,vector<int> v[])
{visited[a]=true;
	for(int i=0;i<v[a].size();i++)
	{
		if(visited[v[a][i]]==false)
		 Explore(v[a][i],v);
	}
	res.push_back(a);
}
void DFS(vector<int> v[])
{
	for(int i=1;i<n+1;i++)
	{if(visited[i]==false)
	 Explore(i,v);
	}
}
int main()
{
	cin>>n>>m;
	vector<int> v[n+1];
	int a,b;
	for(int i=0;i<n+1;i++)
	visited.push_back(false);
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
	}
	DFS(v);
	for(int i=res.size()-1;i>=0;i--)
	cout<<res[i]<<" ";
	
}
