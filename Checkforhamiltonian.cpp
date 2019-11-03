#include<bits/stdc++.h>
using namespace std;
IsThereAHamiltonianPath(vector<int>adj[],int N,int M)
{
	int P[N];
	for(int i=0;i<N;i++)
		P[i]=i+1;
	do
	{   bool valid = true;
		for(int j=0;j<N-1;j++)
		{
			if(find(adj[P[j]].begin(),adj[P[j]].end(),P[j+1])==adj[P[j]].end())
			  {valid=false;
			   break;}
		}
		if(valid)
		 return true;
		
	}while(next_permutation(P,P+N));
	return false;	
}
int main()
{
	int N,M;
	// READING IN THE GRAPH
	cin>>N>>M;
	vector<int> adj[N+1];
	int a,b;
	for(int i=0;i<M;i++)
	{
	 cin>>a>>b;
	 adj[a].push_back(b);
	 adj[b].push_back(a);
	}
	
	if(IsThereAHamiltonianPath(adj,N,M))
	{
		cout<<"There exists a hamiltonian path.";
	}
	else
	{
		cout<<"There exists no hamiltonian path.";
	}
	
	
}
