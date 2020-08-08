#include <bits/stdc++.h>
using namespace std;

int maximumSum(vector<int> a)
{
    int max_so_far=INT_MIN,sum=0;
	int i=0;
	while(i<a.size())
	{
		sum+= a[i];
		if(max_so_far<sum) max_so_far=sum;
		if(sum<0) sum=0;
		i++;
	}
	return max_so_far;
}

void dfs(vector<int> &par, vector<int> &val, vector<int> &col, int i, vector<vector<int> > &v)
{
    col[i]=1;
    v.back().push_back(val[i]);

    if(par[i]!=-1) dfs(par,val,col,par[i],v);
}

int bestSumDownwardTreePath(vector<int> par, vector<int> val)
{
    vector<vector<int> > v;
    vector<int> col(par.size(),0);
    for(int i=par.size()-1;i>=0;i--)
        if(col[i]==0)
        {
            vector<int> w; v.push_back(w);
            dfs(par,val,col,i,v);
        }
    // for(int i=0;i<v.size();i++)
    // {
    //     for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";
    //     cout<<endl;
    // }
    int m=INT_MIN;
    for(int i=0;i<v.size();i++) m=max(m,maximumSum(v[i]));
    return m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> parent(n);
	for(auto &ele : parent)
		cin >> ele;

	cin >> n;
	vector<int> values(n);
	for(auto &ele : values)
		cin >> ele;

	auto res = bestSumDownwardTreePath(parent, values);
	cout << res << endl;

	return 0;
}