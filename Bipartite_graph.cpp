#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b;
vector<bool> visited;
vector<int> color;
vector<int> que;
void BFS(vector<int> v[],int a)
{ color[a]=0;
  que.push_back(a);
  while(!que.empty())
  {
  	int p=que.front();
  	que.erase(que.begin());
  	for(int i=0;i<v[p].size();i++)
  	{ 
	  if(color[v[p][i]]==-1)
  	   {
  	   	  que.push_back(v[p][i]);
  	   	  color[v[p][i]]=(color[p]+1)%2;
	   }
	  else if(color[p]==color[v[p][i]])
	  {cout<<"0";
	   exit(0);
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
 color.push_back(-1);
 }
 for(int i=0;i<m;i++)
 {
  cin>>a>>b;
  v[a].push_back(b);
  v[b].push_back(a);
 }
 
 BFS(v,1);	
 cout<<"1";
}
