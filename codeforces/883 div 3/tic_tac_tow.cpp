#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    char v[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> v[i][j];
    map<char, int> m;
    // for rows
    for (int i = 0; i < 3; i++)
    {
        set<char> s;
        for (int j = 0; j < 3; j++)
            s.insert(v[i][j]);
        if (s.size() >= 2)
            continue;
        if (*s.begin() == '.')
            continue;
        m[*s.begin()]++;
    }
    // for col
    for (int i = 0; i < 3; i++)
    {
        set<char> s;
        for (int j = 0; j < 3; j++)
            s.insert(v[j][i]);
        if (s.size() >= 2)
            continue;
        if (*s.begin() == '.')
            continue;
        m[*s.begin()]++;
    }
    // for diagonal
    set<char> s;
    for (int i = 0; i < 3; i++)
        s.insert(v[i][i]);
    if (s.size() >= 2)
    {
    }
    else if (*s.begin() == '.')
    {
    }
    else
        m[*s.begin()]++;
    s.clear();
    s.insert(v[0][2]);
    s.insert(v[1][1]);
    s.insert(v[2][0]);
    if (s.size() >= 2)
    {
    }
    else if (*s.begin() == '.')
    {
    }
    else
        m[*s.begin()]++;
    if (m.size() == 0)
        cout << "DRAW" << endl;
    else
        cout << (*m.begin()).first << endl;
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
        solve();
    }
    return 0;
}
/*
3 3 120 => 3 6 126 =>135
20 15 100 => 15 , 35 , 135 => 185
90 90 100 => 90 180 280 => 550 
40 40 40 => 40 80 120 => 240

*/