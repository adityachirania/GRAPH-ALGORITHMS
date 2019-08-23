#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	bool visited[n+1]={false};
	vector<pair<int,int> > v[n+1];
    int a,b,c;
	for(int i=0;i<m;i++)
    {cin>>a>>b>>c;
     v[a].push_back(make_pair(b,c));
	}
	int dist[n+1];
	cin>>a>>b;
	for(int i=1;i<=n;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[a]=0;
	set<pair<int,int> > s;
	s.insert(make_pair(dist[a],a));
	while(!s.empty())
	{   auto itr =s.begin();
	    s.erase(itr);
	    visited[itr->second]=true;
	    int id=itr->second;
	    for(int i=0;i<v[id].size();i++)
	    {   int a1=v[id][i].first;
	        int a2=v[id][i].second;
	    	if(dist[a1]>(dist[id]+a2))
	       { dist[a1]=dist[id]+a2;
	       	 s.insert(make_pair(dist[a1],a1));
		   }
		}
	}
	if(dist[b]!=INT_MAX)
	cout<<dist[b];
	else
	cout<<"-1";
	
	

}
