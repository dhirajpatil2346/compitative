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
}

class Solution
{
public:
    map<char, int> ret(map<char, int> a, map<char, int> b)
    {
        for (auto &val : b)
            val.second -= a[val.first];
        return b;
    }
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>> &queries)
    {
        int faults = 0;
        int n = s.length();
        vector<int> v(n);
        for (int i = 0; i < n / 2; i++)
            if (s[i] != s[n - i - 1])
                v[i] = 1, faults++;
        for (int i = 1; i < n; i++)
            v[i] += v[i - 1];
        vector<map<char, int>> a(n);
        for (auto &val : a)
        {
            for (char c = 'a'; c <= 'z'; c++)
                val[c] = 0;
        }
        a[0][s[0]]++;
        for (int i = 1; i < n; i++)
        {
            a[i] = a[i - 1];
            a[i][s[i]]++;
        }
        vector<bool> Ret;
        for (auto &val : queries)
        {
            vector<pair<int, int>> curr;
            curr.push_back({val[0], val[1]});
            curr.push_back({n - val[3] - 1, n - val[2] - 1});
            sort(curr.begin(), curr.end());
            int c = 0;
            bool correct = true;
            for (auto &val : curr)
            {
                int A = val.first, b = val.second;
                int C = n - A - 1, d = n - b - 1;
                map<char, int> X, Y;
                for (char c = 'a'; c <= 'z'; c++)
                    X[c] = 0, Y[c] = 0;
                if (A > 0)
                    X = a[A - 1];
                if (C > 0)
                    Y = a[C - 1];
                map<char, int> m1 = ret(X, a[b]), m2 = ret(Y, a[d]);
                for (char c = 'a'; c <= 'z'; c++)
                {
                    cout << m1[c] << " " << m2[c] << endl;
                    correct &= (m1[c] == m2[c]);
                }
                c += v[b];
                if (A > 0)
                    c -= v[A];
                cout << correct << endl;
            }
            int A = curr[0].first, B = curr[0].second, C = curr[1].first, D = curr[1].second;
            if (C <= B)
            {
                curr.clear();
                curr.push_back({A, max(B, D)});
            }
            for (auto &val : curr)
            {
                int A = val.first, b = val.second;
                c += v[b];
                if (A > 0)
                    c -= v[A];
            }
            if (!correct)
                Ret.push_back(false);
            else
                Ret.push_back(c == faults);
        }
        return Ret;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution sc;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(4));
    for (auto &val : queries)
        for (auto &valu : val)
            cin >> valu;
    vector<bool> ret = sc.canMakePalindromeQueries(s, queries);
    for (auto val : ret)
        cout << val << " ";
    cout << endl;
    return 0;
}