/*THE NUMBER OF STRONGLY CONNECTED COMPONENTS IN A DIRECTED GRAPH. THE TRICK IS TO THE FIND THE VERTEX WITH THE LARGEST POSTORDER IN
REVERSE GRAPH AND START EXPLORATION FROM THAT VERTEX IN NORMAL GRAPH.*/

#include<bits/stdc++.h>
using namespace std;
//INITIALIZING VARIABLES
int n,m;//NODES AND NO. OF EDGES
vector<bool> visited;
vector<bool> in_graph;
int clock1=1;

void pre_order(int a,int preorder[])
{ preorder[a]=-1*clock1;
  clock1++;
}
void post_order(int a,int postorder[])
{ postorder[a]=-1*clock1;
  clock1++;
}
void Explore(int a,vector<int> v[],int preorder[],int postorder[])
{visited[a]=true;
 pre_order(a,preorder);
	for(int i=0;i<v[a].size();i++)
	{
		if(visited[v[a][i]]==false)
		 Explore(v[a][i],v,preorder,postorder);
	}
 post_order(a,postorder);
 in_graph[a]=false;
}

void DFS(vector<int> v[],int preorder[],int postorder[])
{
	for(int i=1;i<n+1;i++)
	{if(visited[i]==false)
	 Explore(i,v,preorder,postorder);
	}
}

int main()
{
	cin>>n>>m;
	vector<int> v[n+1];
	int preorder[n+1];
	int postorder[n+1];
	vector<int> vr[n+1];
	int a,b;
	preorder[0]=-1;
	postorder[0]=-1;
	for(int i=0;i<n+1;i++)
	{
	 visited.push_back(false);
	 in_graph.push_back(true);
	}
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		vr[b].push_back(a);
	}
	DFS(vr,preorder,postorder);
	set<pair<int,int> > postval;
	for(int i=1;i<n+1;i++)
	postval.insert(make_pair(postorder[i],i));
	int count_of_components=0;
	for(int i=0;i<n+1;i++)
	{
	 visited[i]=false;
	 in_graph[i]=true;
	}
	while(postval.size()!=0)
	{  auto itr = postval.begin();
		if(in_graph[itr->second]==true)
		{
		Explore(itr->second,v,preorder,postorder);
		count_of_components++;
		}
		postval.erase(itr);
	}
	cout<<count_of_components;
	
	
	
	
}
