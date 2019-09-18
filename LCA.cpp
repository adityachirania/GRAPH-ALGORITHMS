#include<bits/stdc++.h>
using namespace std;
int N;
int up[1000][10];
int clock1=1;
int preorder[1000];
int postorder[1000];
void DFS(int child,int parent,vector<int> neighbour[])
{
	up[child][0]=parent;
	preorder[child]=clock1++;
	for(int i=1;i<ceil(log2(N));i++)
	{up[child][i]=up[up[child][i-1]][i-1];}
	
	for(int i=0;i<neighbour[child].size();i++)
	DFS(neighbour[child][i],child,neighbour);
	
	postorder[child]=clock1++;
}
bool is(int a,int anc)
{
	if(preorder[a]>preorder[anc]&&postorder[a]<postorder[anc])
	return true;
	else
	return false;	
}
int LCA(int a,int b)
{
   if (is(a,b)==true)return b;
   else if(is(b,a)==true)return a;
   //THE BINARY LIFTING IS ALL SET TO BEGIN
   else
   {
   	 for(int i = ceil(log2(N));i>=0;i--)
   	 {
   	 	if(!is(b,up[a][i]))
   	 	 a=up[a][i];
	 }
	 return up[a][0];
   }
}
int main()
{
	int T;
	cin>>T;
	for(int k=0;k<T;k++)
	{
		
		cin>>N;
		int n;
		vector<int> neighbour[N];
		for(int i=0;i<N;i++)
		{
			cin>>n;
			for(int j=0;j<n;j++)
			{   int x;
				cin>>x;
				neighbour[i].push_back(x-1);
			}
		}
		const int root=0;
		DFS(root,root,neighbour);
		int Q;
		cin>>Q;
		
		cout<<"Case "<<k+1<<":\n";
		while(Q--)
		{   
			int a,b;
			cin>>a>>b;
			if(a==b)cout<<a<<"\n";
			else
			cout<<LCA(a-1,b-1)+1<<"\n";
    	}
    	
    	for(int i=0;i<N;i++)
		neighbour[i].clear();
		clock1=1;
    	
	}
}
