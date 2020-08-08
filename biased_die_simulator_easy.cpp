#include <bits/stdc++.h>
using namespace std;

int countDiceSequences(int n, vector<int> &mroll)
{
    
}

int main()
{
	int n;
	cin >> n;

	vector<int> roll_max(6);
	for(auto &ele : roll_max)
		cin >> ele;

	auto res = countDiceSequences(n, roll_max);
	cout << res << endl;

	return 0;
}