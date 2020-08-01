#include<bits/stdc++.h>

using namespace std;

int fun(int n,int k,int c,int i,int s)
{
    if(c==k && n-s>=i) return 1;
    else if(c==k) return 0;
    int sum=0;
    // cout<<i<<" ";
    for(int j=i;j<=n+1-k;j++) sum+=fun(n,k,c+1,j,s+j);
    return sum;
}

int main()
{
    int n,k;cin>>n>>k;
    if(k>n) cout<<0<<endl;
    else cout<<fun(n,k,1,1,0)<<endl;
}