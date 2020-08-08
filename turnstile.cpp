#include <bits/stdc++.h>
using namespace std;

vector<int> getTimes(vector<int> &time, vector<int> &dir)
{
    queue<pair<int,int> > en,lv;
    for(int i=0;i<time.size();i++)
    {
        if(dir[i]) lv.push(make_pair(time[i],i));
        else en.push(make_pair(time[i],i));
    }

    vector<int> v(time.size());
    int fl=1,t=0;
    while(!en.empty() && !lv.empty())
    {
        if(t<min(en.front().first,lv.front().first))
        {
        	t=min(en.front().first,lv.front().first);
        	fl=1;
        }
        en.front().first = max(t,en.front().first);
        lv.front().first = max(t,lv.front().first);

        if(en.front().first > lv.front().first) {v[lv.front().second]=t;lv.pop();fl=1;}
        else if(en.front().first < lv.front().first) {v[en.front().second]=t;en.pop();fl=0;}
        else
        {
            if(fl) {v[lv.front().second]=t;lv.pop();fl=1;}
            else {v[en.front().second]=t;en.pop();fl=0;}
        }
        t++;
    }
    while(!en.empty())
    {
        t=max(t,en.front().first);
        v[en.front().second]=t; en.pop();
        t++;
    }
    while(!lv.empty())
    {
        t=max(t,lv.front().first);
        v[lv.front().second]=t; lv.pop();
        t++;
    }
    return v;
    return v;
}

int main()
{
	int n;
	cin >> n;

	vector<int> time(n);
	for(auto &ele : time)
		cin >> ele;

	cin >> n;
	vector<int> direction(n);
	for(auto &ele : direction)
		cin >> ele;

	auto res = getTimes(time, direction);
	for(auto &ele : res)
		cout << ele << endl;

	return 0;
}