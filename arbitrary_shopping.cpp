#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin>>n; int out[n];
    for(int i=0;i<n;i++) cin>>out[i];
    int mon;cin>>mon;

    // int s[n]; s[0]=0;
    // for(int i=1;i<n;i++) s[i]+=s[i-1];

    int i=0,j=-1,c=0,cmax=INT_MIN,s=0,fl=1;
    while(i<n)
    {
        if(fl) s+=out[i];
        else s-=out[j];

        if(s>mon)
        {
            cmax=max(c,cmax);
            j++;c--;fl=0;
        }
        else {c++;i++;fl=1;}
    }
    cmax=max(c,cmax);
    cout<<cmax<<endl;
}