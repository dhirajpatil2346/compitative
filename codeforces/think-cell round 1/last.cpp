#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
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
class Compare
{
public:
    bool operator()(pair<int, pair<int, int>> below, pair<int, pair<int, int>> above)
    {
        if (below.first != above.first)
        {
            return below.first < above.first;
        }
        return below.second.second > above.second.second;
    }
};
void solve()
{
    int n;
    cin >> n;
    // {maxval, {val, ind}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> s;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        s.push({i + val, {val, i}});
    }
    // while (s.size())
    // {
    //     auto tp = s.top();
    //     cout << tp.first << " " << tp.second.first << " " << tp.second.second << endl;
    //     s.pop();
    // }
    set<int> ans;
    auto tp = s.top();
    s.pop();
    ans.insert(tp.first);
    int last = tp.first;
    while (s.size())
    {
        tp = s.top();
        s.pop();
        // index is i
        // 5 , 1
        // 5
        // 5 , 2
        // 4
        if (last != tp.first)
        {
            ans.insert(tp.first);
            last = tp.first;
        }
        else
        {
            if (tp.second.second > 1)
            {
                ans.insert(tp.first - 1);
                last = tp.first - 1;
            }
        }
    }
    while (ans.size())
    {
        cout << *prev(ans.end()) << " ";
        ans.erase(prev(ans.end()));
    }
    cout << endl;
}
signed main()
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