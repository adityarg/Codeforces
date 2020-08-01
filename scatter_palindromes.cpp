#include<bits/stdc++.h>

using namespace std;

int check(vector<int>&c)
{
    int fl=0;
    for(int i=0;i<26;i++) if(c[i]%2) fl++;
    if(fl<=1) return 1;
    else return 0;
}

int main()
{
    string s;cin>>s;
    int ct=0;
    for(int i=0;i<s.size();i++)
    {
        vector<int> c(26,0);
        for(int j=i;j<s.size();j++) {c[s[j]-'a']++; ct+=check(c);}
    }
    cout<<ct<<endl;
}