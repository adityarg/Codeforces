#include<bits/stdc++.h>

using namespace std;

bool comp( const vector<int>& v1,const vector<int>& v2 )
{return (v1[0]<v2[0]) || (v1[0]==v2[0] && v1[1]<v2[1]) || (v1[0]==v2[0] && v1[1]==v2[1] && v1[2]<v2[2]);}

int main()
{
    int n;cin>>n;
    vector<vector<int> > cost;
    for(int i=0;i<n;i++)
    {
        vector<int> w;
        for(int j=0;j<n;j++) {int r;cin>>r;w.push_back(r);}
        cost.push_back(w);
    }
    
    sort(cost.begin(),cost.end(),comp);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout<<cost[i][j]<<" ";
    //     cout<<endl;
    // }
    int c=0; set<int> v;
    for(int i=0;i<n;i++)
    {
        int m=INT_MAX,y;
        for(int j=0;j<n;j++)
            if(v.find(j)==v.end() && m>cost[i][j]) {m=cost[i][j];y=j;}
        c+=m; v.insert(y);
    }
    cout<<c<<endl;
}