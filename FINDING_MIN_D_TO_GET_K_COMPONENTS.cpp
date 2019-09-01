#include<bits/stdc++.h>
using namespace std;
int count1=0;
double ans=0.0;
int k;
int n;
double dist(double x2,double x1,double y2,double y1)
{ 
    
	return sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2) * 1.0);
}

int getid(int link[],int a)
{
	while(link[a]!=0)
	{
	 a=link[a];
    }
	return a;
}

void Union(int i,int j,int link[],double l)
{
	int a=getid(link,i);
	int b=getid(link,j);
	if(a==b)
	{return;}
	else
	{
	  count1++;	
	  if(count1>n-1-(k-1))
	  {cout<<setprecision(15)<<l;exit(0);}
      link[a]=b;
      ans=ans*1.00+l*1.00;
	}
}
int main()
{   
    
	
	cin>>n;
	double p0=0.000000;
	
	int link[n+1]={0};	
	vector<pair<float,float> > v;
	v.push_back(make_pair(0*1.00,0*1.00));
	
	int x,y;
	for(int i=1;i<=n;i++)
	{
	 cin>>x>>y;
	 v.push_back(make_pair(x*1.00,y*1.00));
	}
	
	cin>>k;
	if(n==1){
	cout<<p0;exit(0);}

	vector< pair<double, pair<int, int> > > v1;
	for(int i=1;i<=n;i++)
	 for(int j=i+1;j<=n;j++)
	 {
	 	v1.push_back(make_pair( dist(v[i].first,v[j].first,v[i].second,v[j].second) , make_pair(i,j) ) );
	 }
    sort(v1.begin(),v1.end());
    
	while(1)
    {
		 auto start=v1.begin();
		 
		 Union(start->second.first,start->second.second,link,start->first);
		 if(count1==n-1)break;
		 v1.erase(v1.begin());
		 if(v1.empty())
		 break;
	}
    
	
	
}
