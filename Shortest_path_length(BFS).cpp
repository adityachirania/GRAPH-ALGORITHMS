#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b;
vector<bool> visited;
vector<int> dist;
vector<int> que;
void BFS(vector<int> v[],int a)
{ dist[a]=0;
  que.push_back(a);
  while(!que.empty())
  {
  	int p=que.front();
  	que.erase(que.begin());
  	for(int i=0;i<v[p].size();i++)
  	{ if(dist[v[p][i]]==INT_MAX)
  	   {
  	   	  que.push_back(v[p][i]);
  	   	  dist[v[p][i]]=dist[p]+1;
  	   	  if(v[p][i]==b)
  	   	  {cout<<dist[v[p][i]];
		   exit(0);}
	   }
  		
	}
  }
	
}
int main()
{cin>>n>>m;
 vector<int> v[n+1];
 for(int i=0;i<n+1;i++)
 {
 visited.push_back(false);
 dist.push_back(INT_MAX);
 }
 for(int i=0;i<m;i++)
 {
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
 }
 
 cin>>a>>b;
 BFS(v,a);	
 cout<<"-1";	
}
