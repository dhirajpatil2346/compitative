#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    int i = 0;
    string ans = "";
    while (i < n)
    {
        char key = s[i];
        int c = 0;
        while (i < n && s[i] == key)
        {
            i++, c++;
        }
        string h = "";
        h += key;
        h += to_string(c);
        ans += h;
    }
    cout << ans << endl;
    return 0;
}