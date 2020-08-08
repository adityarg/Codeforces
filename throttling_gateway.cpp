#include <bits/stdc++.h>
using namespace std;

int droppedRequests(vector<int> requestTime)
{
    map<int,int> m;
    for(auto i:requestTime) m[i]++;
    int ct=0;

    for(auto i:m)
        if(i.second>3) ct+= i.second-3;
    
    auto i=m.begin();
    while(i!=m.end())
    {
        auto j=i; int sum=0;
        while(j!=m.end() && j->first - i->first<=9) {sum+=j->second; j++;}
        if(sum>20) ct+= sum-20;
        i=j;
    }

    i=m.begin();
    while(i!=m.end())
    {
        auto j=i; int sum=0;
        while(j!=m.end() && j->first - i->first<=59) {sum+=j->second; j++;}
        if(sum>60) ct+= sum-60;
        i=j;
    }
    return ct;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> requestTime(n);

	for(auto &ele : requestTime)
		cin >> ele;

	auto res = droppedRequests(requestTime);
	cout << res << endl;

	return 0;
}
