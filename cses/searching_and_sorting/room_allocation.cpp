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
    LL n,p=0;
    cin >> n;
    // cout << "h0" << endl;
    vector<pair<int, pair<int, int>>> vp(n);
    for (int i = 0; i < n; i++)
    {
        vp[i].second.second = i;
        cin >> vp[i].first >> vp[i].second.first;
    }
    sort(vp.begin(), vp.end());
    int l = 1, r = n;
    vector<int> ans;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        vector<int> curr(n);
        set<pair<int, int>> m;
        for (int i = 0; i < mid; i++)
            m.insert({0, i + 1});
        bool f = false;
        for (auto &val : vp)
        {
            auto p = *m.begin();
            m.erase(m.begin());
            int last = p.first;
            if (last >= val.first)
            {
                f = true;
                break;
            }
            else
            {
                m.insert({val.second.first, p.second});
                curr[val.second.second] = p.second;
            }
        }
        if (f)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
            p=mid;
            ans = curr;
        }
    }
    cout<<p<<endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}