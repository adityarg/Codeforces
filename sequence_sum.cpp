#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i,j,k; cin>>i>>j>>k;
	if(i>k) swap(i,k);
	// cout<<
	long long int s = 0;
	for(int w=i;w<k;w++) s+= w;
	for(int w=k;w<j;w++) s+= 2*w;
	s+= j;
	cout<<s<<endl;
}