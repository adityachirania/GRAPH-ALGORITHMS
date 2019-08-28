#include<bits/stdc++.h>
using namespace std;

int n,m;
int bellman(int dist[],vector<pair<int,int> > v[],int prev[])
{   int save=-1;
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
		 	
		 if(dist[v[i][j].first]>dist[i]+v[i][j].second)
		 {
		  prev[v[i][j].first]=i;
		  dist[v[i][j].first]=dist[i]+v[i][j].second;
		  save=v[i][j].first;
		 }
		 
		}
	}
	return save;
}

int main()
{  
	
	cin>>n>>m;
	vector<pair<int,int> > v[n+1];
	int dist[n+1];
	int prev[n+1];
	int a,b,c;
	for(int i=0;i<m;i++)
	{
	 cin>>a>>b>>c;
	 v[a].push_back(make_pair(b,c));
	}
    const int src =1;
    
	for(int i=1;i<n+1;i++)
    dist[i]=1000*(n-1)+1;
    
	dist[src]=0;
    int p;
    for(int i=1;i<n;i++)
    p=bellman(dist,v,prev);
    
    p=bellman(dist,v,prev);
    
    if(p!=-1)
    {cout<<"1";
	}
	else
	cout<<"0";
		
	
	
}
