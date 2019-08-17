#include<bits/stdc++.h>
using namespace std;
int n;
//int count=0;
void Explore(int src,bool visited[],vector<int> v[])
{visited[src]=true;
 
 for(int i=0;i<v[src].size();i++)
 {
 	if(visited[v[src][i]]==false)
 	 Explore(v[src][i],visited,v);
 	 
 }
 
}
int DFS(bool visited[],vector<int> v[])
{ static int count =1 ;
	for(int i=1;i<n+1;i++)
	{
		if(visited[i]==false)
		 {Explore(i,visited,v);
		 count++;}
	}
	return count;
}
int main()
{
int m;
cin>>n>>m;
bool visited[n+1]={false};
int src;
vector<int> v[n+1];
int a,b;
for(int i=0;i<m;i++)
{
	cin>>a>>b;
	v[a].push_back(b);
	v[b].push_back(a);
}

int count =DFS(visited,v);
cout<<count-1;
	
}
