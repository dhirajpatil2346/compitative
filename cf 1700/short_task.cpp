#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<LL> ans(1e7 + 1, 1);
const int A = 1e7 + 1;
vector<int> pre(1e7 + 1, 1e7 + 1);
LL bin(LL v, LL p)
{
    if (p == 0)
        return 1;
    LL res = bin(v, p / 2ll);
    res = res * res;
    if (p & 1ll)
        res *= v;
    return res;
}

void sieve()
{

    vector<LL> value(A), ans(A, 1);
    for (int i = 0; i < value.size(); i++)
        value[i] = i;
    for (int i = 2; i * i < A; i++)
    {
        if (value[i] == i)
            for (int j = i * i; j < A; j += i)
                value[j] = i;
    }
    ans[1] = 1;
    for (LL i = 2; i < A; i++)
    {
        LL val = i;

        if (i == value[i])
        {
            ans[i] = i + 1;
            continue;
        }
        while (val > 1)
        {
            LL c = value[i];
            LL j = value[i];
            while (val % c == 0)
            {
                j *= c;
                val /= c;
            }
            ans[i] *= ((j - 1ll) / (c - 1ll));
        }
    }
    for (int i = ans.size() - 1; i > 0; i--)
        if (ans[i] <= 1e7)
            pre[ans[i]] = i;
}

void solve()
{
    LL n;
    cin >> n;
    if (pre[n] > 1e7)
        cout << -1 << endl;
    else
        cout << pre[n] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}