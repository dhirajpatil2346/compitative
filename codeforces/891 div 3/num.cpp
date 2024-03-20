#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl "\n"
vector<bool> prime(2e5 + 10, true);
vector<LL> primo;
const LL mod = 1e9 + 7;
void sieve()
{
    prime[0] = false, prime[1] = false;
    for (LL i = 2; i < 2e5 + 10; i++)
        for (LL j = 2 * i; j < 2e5 + 10; j += i)
            prime[j] = false;
    for (LL i = 2; i < 2e5 + 10; i++)
        if (prime[i])
            primo.push_back(i);
}
bool cmp(pair<LL, LL> &p1, pair<LL, LL> &p2)
{
    return p1.first >= p2.first;
}
LL bin(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL fct = bin(a, p / 2);
    fct = (fct * fct) % mod;
    if (p & 1)
        fct *= a;
    fct %= mod;
    return fct;
}
class Solution
{
public:
    int maximumScore(vector<int> &v, LL k)
    {
        LL n = v.size(), ret = 1;
        vector<LL> primes(n), score(n, 1);
        map<LL, vector<LL>> mp;
        for (LL i = 0; i < n; i++)
            mp[v[i]].push_back(i);
        if (prime[4] == true)
            sieve();
        for (LL i = 0; i < n; i++)
        {
            LL val = v[i];
            set<LL> l;
            for (LL j = 0; j < primo.size(); j++)
            {
                if (val <= 0)
                    break;
                if (primo[j] > sqrt(val))
                    break;
                if (val % primo[j])
                    continue;
                l.insert(primo[j]);
                while (val % primo[j] == 0)
                    val /= primo[j];
            }
            if (val > 1)
                l.insert(val);
            primes[i] = l.size();
        }
        vector<LL> right(n, 1);
        for (LL i = n - 2; i >= 0; i--)
            if (primes[i + 1] <= primes[i])
                right[i] = right[i + 1] + 1;
        vector<LL> left(n, 0);
        for (LL i = 1; i < n; i++)
            if (primes[i - 1] < primes[i])
                left[i] = left[i - 1] + 1;
        vector<LL> fin(n);
        for (LL i = 0; i < n; i++)
            fin[i] = left[i] + right[i];
        vector<pair<LL, LL>> vp;
        for (LL i = 0; i < n; i++)
            vp.push_back({v[i], fin[i]});
        sort(vp.begin(), vp.end(), cmp);

        for (auto &val : vp)
        {
            LL mn = min(val.second, k);
            k -= mn;
            LL fct = bin(val.first, mn);
            ret *= fct;
            ret %= mod;
        }
        return (int)ret;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    Solution sc;
    cout << sc.maximumScore(v, x);
    return 0;
}