#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    unordered_map<char, bool> m;
    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        m[c] = true;
    }

    int i = 0;
    ll cost = 0;
    while (i < n)
    {
        if (!m[s[i]])
        {
            i++;
            continue;
        }
        int z = 0;
        int j = i;
        while (j < n && m[s[j]])
        {
            j++;
            i++;
            z++;
        }
        cost += ((z) * (z + 1)) / 2;
    }
    cout << cost << endl;
    return 0;
}