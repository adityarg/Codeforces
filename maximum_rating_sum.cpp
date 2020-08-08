#include <bits/stdc++.h>
using namespace std;

long long maximumSum(vector<int> a)
{
    long long int max_so_far=INT_MIN,sum=0;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &ele : a)
		cin >> ele;

	auto res = maximumSum(a);
	cout << res << endl;

	return 0;
}