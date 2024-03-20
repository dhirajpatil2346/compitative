#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

map<char, int> m;
map<int, char> rev;
void solve()
{
    /*
        baaaaa -> cbaaab
        aaaaab ->
    */
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    for (int i = 0; i < n - 1;)
    {
        if (s[i] == 'C')
        {
            i++;
            continue;
        }
        if (s[i] == 'B')
        {
            i++;
            int c = 0;
            if (s[i] == 'B')
                continue;
            else
            {
                while (i < n && s[i] == 'A')
                    i++, ans++;
                i--;
                s[i] = 'B';
            }
        }
        else
        {
            // s[i] == 'A'
            int c = 0;
            while (i < n && s[i] == 'A')
                i++, c++;
            if (i == n)
                continue;
            i++;
            ans += c;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    m['A'] = 0, m['B'] = 1, m['C'] = 2;
    rev[0] = 'A', rev[1] = 'B', rev[2] = 'C';
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}