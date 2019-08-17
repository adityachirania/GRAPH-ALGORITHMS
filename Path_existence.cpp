#include<bits/stdc++.h>
using namespace std;
int dest;
int n;
void Explore(int src,bool visited[],vector<int> v[])
{visited[src]=true;
 if(src==dest)
 {cout<<"1";exit(0);}
 
 for(int i=0;i<v[src].size();i++)
 {
 	if(visited[v[src][i]]==false)
 	 Explore(v[src][i],visited,v);
 }
 
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
cin>>src>>dest;
Explore(src,visited,v);
cout<<"0";
	
}
