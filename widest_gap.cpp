// https://www.geeksforgeeks.org/merging-intervals/
#include <bits/stdc++.h>
using namespace std;

int widestGap(int n, vector<pair<int,int> > &v)
{
    sort(v.begin(),v.end());
    stack<pair<int,int> > s;
    for(int i=0;i<v.size();i++)
    {
        if(s.empty()) s.push(make_pair(v[i].first,v[i].second));
        else
        {
            if(s.top().second < v[i].first) s.push(make_pair(v[i].first,v[i].second));
            else if(s.top().second < v[i].second) s.top().second=v[i].second;
        }
    }
    int y=n,m=INT_MIN;
    while(!s.empty())
    {
        m=max(m , y-s.top().second);
        y=s.top().first-1; s.pop();
    }
    m=max(m,y);
    return m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int m;
	cin >> m;

	vector<pair<int,int> > v(m);
	for(auto &ele : v)
		cin >> ele.first;

	cin >> m;
	for(auto &ele : v)
		cin >> ele.second;

	auto res = widestGap(n, v);
	cout << res << endl;

	return 0;
}