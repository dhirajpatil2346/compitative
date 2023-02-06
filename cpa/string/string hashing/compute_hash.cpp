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
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++)
    {
        set<long long> hs;
        cout << "length is : " << l << endl;
        for (int i = 0; i <= n - l; i++)
        {
            long long cur_h = (h[i + l] - h[i] + m) % m;
            cout << "i is : " << i << endl;
            cout << "chash is : " << cur_h << endl;
            ll ccur_h = (cur_h * p_pow[n - i - 1]) % m;
            cout << "cchash is : " << ccur_h << endl;
            hs.insert(ccur_h);
        }
        cnt += hs.size();
    }
    cout << cnt << endl;
    return 0;
}
/*

*/
/*
a
b
c
d
ab
abc
abcd
bc
bcd
cd
*/