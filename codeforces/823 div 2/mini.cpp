#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    char minichar = s[0];
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        minichar = min(s[i], minichar);
    }
    int freq = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == minichar)
        {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == minichar)
        {
            freq++;
        }
    }
    if (freq == 1) 
    {
        vector<char> v;
        for (int i = 0; i < pos; i++)
        {
            v.push_back(s[i] + 1);
        }
        string ans="";
        for (int i = pos; i < n; i++)
        {
            ans+=s[i];
        }
        for(auto &val:)
    }
    return 0;
}