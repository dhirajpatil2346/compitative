#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char serv = 'A';
    map<char, int> m;
    m['A'] = 0, m['B'] = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            if (s[i] == serv)
            {
                m[s[i]]++;
            }
            else
            {
                serv = 'B';
            }
        }
        else
        {
            if (s[i] == serv)
            {
                m[s[i]]++;
            }
            else
            {
                serv = 'A';
            }
        }
    }
    for (auto &val : m)
        cout << val.second << " ";
    cout << endl;
    cout << serv << endl;
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