#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int l = 0, r = s.length() - 1;
        vector<char> inc;
        string ans = "";
        while (l <= r)
        {
            int a = l, b = r;
            char minichar = s[l];
            for (int i = a; i <= b; i++)
            {
                minichar = min(s[i], minichar);
            }
            int pos;
            for (int i = a; i <= b; i++)
            {
                if (s[i] == minichar)
                {
                    pos = i;
                    break;
                }
            }
            cout << l << " " << pos << endl;
            if (s[pos] == '9')
            {
                inc.push_back('9');
            }
            else
            {
                ans += s[pos];
            }
            for (int i = l; i < pos; i++)
            {
                char p = s[i] + 1;
                cout << s[i] << p << endl;
                inc.push_back(min(p, '9'));
            }
            l = pos + 1;
        }
        sort(inc.begin(), inc.end());
        for (auto val : inc)
        {
            ans += val;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1 2 1 4 5
2 
1 1 3 4 5
0 4 8 2 9
4 8 
0 2 5 9 9
0 2 1
2
0 1 3
0  1 4 2 1
4 2
0 1 1 3 5
0 4 2 1 1
2 4
0 1 1 3 5
0 4 2 1 1 4 2
4 2 4
0 1 1 2 3 5 5 
*/