#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;

vector<LL> prefix_function(string s)
{
    LL n = (LL)s.length();
    vector<LL> pi(n);
    for (LL i = 1; i < n; i++)
    {
        LL j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

LL bin(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = bin(a, p / 2ll);
    res = (res * res) % mod;
    if (p & 1ll)
        res = (res * a) % mod;
    return res;
}

LL mmi(LL a)
{
    return bin(a, mod - 2);
}

const LL sz = 1e7 + 5;
vector<LL> primes;
void sieve()
{
    vector<bool> isp(sz, true);
    isp[0] = false, isp[1] = false;
    for (LL i = 2; i * i <= sz; i++)
        if (isp[i])
            for (LL j = i * i; j < sz; j += i)
                isp[j] = false;
    for (int i = 2; i < sz; i++)
        if (isp[i])
            primes.push_back(i);
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> bc = {9, 1, 7, 5, 4, 8, 6, 3, 2};
    reverse(bc.begin(), bc.end());
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            v[i][j] = bc.back();
            bc.pop_back();
        }
    for (int i = 3; i < n; i++)
    {
        int row = i, col = i;
        vector<int> even, odd;
        for (int j = i * i + 1; j <= (i + 1) * (i + 1); j++)
            if (j & 1)
                odd.push_back(j);
            else
                even.push_back(j);

        v[0][col] = even.back();
        even.pop_back();
        v[row][0] = even.back();
        even.pop_back();
        for (int j = 1; j < i; j++)
            if (even.size())
            {
                v[row][j] = even.back();
                even.pop_back();
            }
            else
            {
                v[row][j] = odd.back();
                odd.pop_back();
            }
        for (int j = 1; j < i; j++)
        {
            if (even.size())
            {
                v[j][col] = even.back();
                even.pop_back();
            }
            else
            {
                v[j][col] = odd.back();
                odd.pop_back();
            }
        }
        if (odd.size())
            v[i][i] = odd.back();
        else
            v[i][i] = even.size();
    }
    for (auto &val : v)
    {
        for (auto &valu : val)
            cout << valu << " ";
        cout << endl;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int k = 0; k <= i; k++)
    //         sum += (v[0][k] + v[k][0]);
    //     for (int k = 1; k <= i; k++)
    //         sum += (v[k][i] + v[i][k]);
    //     sum -= v[0][0];
    //     if (i != 0)
    //         sum -= v[i][i];
    //     cout << i << " " << sum % 2 << endl;
    // }
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