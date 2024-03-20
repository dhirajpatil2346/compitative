#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool ispal(string &s)
{
    if (s[0] == s[2])
        return true;
    return false;
}
bool solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 3 == 1)
        return true;
    if (n % 3 == 0)
    {
        map<char, vector<int>> m;
        for (int i = 0; i < n; i++)
            m[s[i]].push_back(i);
        for (auto &val : m)
        {
            vector<int> mod(3);
            for (auto &valu : val.second)
                mod[valu % 3]++;
            if ((mod[0] > 2 || mod[1] > 2 || mod[2] > 2))
                return true;
        }
        
    }
    else
    {
        // n % 3 is two
        map<char, vector<int>> m;
        for (int i = 0; i < n; i++)
            m[s[i]].push_back(i);
        for (auto &val : m)
        {
            vector<int> mod(3);
            for (auto &valu : val.second)
                mod[valu % 3]++;
            if ((mod[0] > 0 && mod[1] > 0) || (mod[1] > 0 && mod[2] > 0))
                return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
/*
%1 --> no tension


*/