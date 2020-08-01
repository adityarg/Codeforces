#include <bits/stdc++.h>
using namespace std;

long long journey(vector<int> &path, int k)
{
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> path(n);
	for(auto &ele : path)
		cin >> ele;

	int k;
	cin >> k;

	auto res = journey(path, k);
	cout << res << endl;

	return 0;
}