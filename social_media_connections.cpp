#include <bits/stdc++.h>
#define ll long long int
#define md 1000000007

using namespace std;

void dfs(vector<vector<int> >&v, vector<int>&col, int i,int c,ll &ans, int str)
{
	if(c==3 && col[i]==1)
	{
		// cout<<"bbbb "<<str<<endl;
		if(i==str)
		{
			ans = (ans + (v[i].size()-2)%md)%md;
			cout<<i<<" "<<ans<<endl;
		}
	}
	else if(col[i]==0)
	{
		// cout<<"aa"<<endl;
		col[i]=1;
		for(int j=0;j<v[i].size();j++) dfs(v,col,v[i][j],c+1,ans,str);
		col[i]=0;
	}
}

int bestTrio(int nodes, int edges, vector<int> friends_from, vector<int> friends_to)
{
	vector<vector<int> > v(nodes);
	for(int i=0;i<friends_to.size();i++)
		{v[friends_to[i]-1].push_back(friends_from[i]-1); v[friends_from[i]-1].push_back(friends_to[i]-1);}
	// for(int i=0;i<friends_to.size();i++)
	// {
	// 	cout<<i<<" -> ";
	// 	for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";
	// 	cout<<endl;
	// }
	
	vector<int> col(nodes,0);
	ll ans=INT_MAX,a;
	for(int i=0;i<nodes;i++)
		if(v[i].size()>1) {a=0; dfs(v,col,i,0,a,i); ans=min(ans,a/2);}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int friends_nodes, friends_edges;
	cin >> friends_nodes >> friends_edges;
	
	vector<int> friends_from(friends_edges), friends_to(friends_edges);

	for(int i = 0; i < friends_edges; i++)
	{
		cin >> friends_from[i] >> friends_to[i];
	}

	auto res = bestTrio(friends_nodes, friends_edges, friends_from, friends_to);
	cout << res << endl;

	return 0;
}