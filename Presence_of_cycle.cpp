#include<bits/stdc++.h>
using namespace std;
int n;
bool arr[1001]={false};
bool visited[1001];
//int count=0;
void Explore(int src,vector<int> v[])
{visited[src]=true;
 arr[src]=true;
 for(int i=0;i<v[src].size();i++)
 { 
   if(visited[v[src][i]]==false)
 	 Explore(v[src][i],v); 
 
    else if(arr[v[src][i]]==true)
       {
       	cout<<"1";exit(0);
	   }	 
 }
  arr[src]=false;
 
}
void DFS(vector<int> v[])
{
	for(int i=1;i<n+1;i++)
	{
		if(visited[i]==false)
		 {Explore(i,v);}
		for(int i=1;i<n+1;i++)
		arr[i]=false;
	}
	return ;
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
	
}

DFS(v);
cout<<"0";
	
}
