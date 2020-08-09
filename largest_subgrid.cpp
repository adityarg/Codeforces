#include <bits/stdc++.h>
using namespace std;

int largestSubgrid(vector<vector<int>> grid, int k)
{
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin >> n;

	vector<vector<int>> mat(n, vector<int>(n, 0));
	for(auto &row_vec : mat)
		for(auto &ele : row_vec)
			cin >> ele;

	int k;
	cin >> k;

	auto res = largestSubgrid(mat, k);
	cout << res << endl;

	return 0;
}