#include <bits/stdc++.h>
using namespace std;

void trav(map<string,int> &m,string s)
{
    if(s.size()==1)
    {
        if(m.find(s)==m.end()) m.insert({s,1});
        return;
    }
    int c=0;
    for(int i=1;i<s.size();i++)
    {
        string t=s.substr(i,s.size()-i);
        auto itr=m.find(t); if(itr==m.end()) trav(m,t);
        c+= m[t];
    }
    for(int i=s.size()-2;i>=0;i--)
    {
        string t=s.substr(0,i+1);
        auto itr=m.find(t); if(itr==m.end()) trav(m,t);
        c+= m[t];
    }
    m.insert({s,c});
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s; cin>>s;
    map<string,int> m;
    trav(m,s);
    cout<<m[s]<<endl;
	return 0;
}