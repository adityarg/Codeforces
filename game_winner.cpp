#include <bits/stdc++.h>
using namespace std;

string gameWinner(string str)
{
    int c1=0,c=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='b')
        {
            if(c>2) {c1+=c-2;}
            c=0;
        }
        else if(str[i]=='w') c++;
    }
    if(c>2) c1+=c-2;
    c=0;int c2=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='w')
        {
            if(c>2) {c2+=c-2;}
            c=0;
        }
        else if(str[i]=='b') c++;
    }
    if(c>2) c2+=c-2;
    // cout<<c1<<" "<<c2<<endl;
    if(c1>c2) return "wendy";
    else return "bob";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	auto res = gameWinner(str);
	cout << res << endl;
}