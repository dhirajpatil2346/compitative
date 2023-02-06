#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string j;
    cin >> j;
    string s = j;
    int ans = 0;
    while (s.length() >= 2)
    {
        int num = 0;
        int i = 0;
        while (i < s.length())
        {
            num = num + s[i] - '0';
            i++;
        }
        s = to_string(num);
        ans++;
    }
    cout << ans << endl;
    return 0;
}