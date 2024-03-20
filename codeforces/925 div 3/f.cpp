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

bool ret(vector<vector<int>> &v, vector<int> &seq)
{
    // for (auto &val : seq)
    //     cout << val << " ";
    // cout << endl;
    int n = v[0].size();
    map<int, int> pos;
    for (int i = 0; i < n; i++)
        pos[seq[i]] = i;
    // for (auto &val : pos)
    //     cout << val.first << " " << val.second << endl;
    for (auto &rows : v)
    {
        for (int i = 1; i < n - 1; i++)
        {
            if (pos[rows[i]] > pos[rows[i + 1]])
            {
                return false;
            }
        }
    }
    return true;
}

vector<int> give(vector<int> &v1, vector<int> &v2)
{
    vector<int> seq;
    int right_off = -1;
    int n = v1.size();
    for (int i = 1; i < n - 1; i++)
    {
        if (v2[i + 1] == v1[0])
        {
            right_off = v2[i];
            break;
        }
    }
    if (right_off == -1)
    {
        seq.push_back(v1[0]);
    }
    for (int i = 1; i < n; i++)
    {
        seq.push_back(v1[i]);
        if (v1[i] == right_off)
            seq.push_back(v1[0]);
    }
    return seq;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k, vector<int>(n));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;
    vector<int> seq;
    if (k == 1)
    {
        cout << "YES" << endl;
        return;
    }
    else if (k == 2)
    {
        vector<int> seq = give(v[0], v[1]);
        if (ret(v, seq) || ret(v, v[0]) || ret(v, v[1]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        map<int, int> m;
        for (auto &val : v)
            m[val[1]]++;
        // for (auto &val : m)
        //     cout << val.first << " " << val.second << endl;
        int p = -1;
        for (auto &val : m)
        {
            if (val.second > 1)
            {
                // cout << p << endl;
                p = val.first;
                // cout << "--> " << val.first << " " << val.second << endl;
                // cout << p << endl;
                break;
            }
        }
        // cout << p << endl;
        if (p == -1)
        {
            cout << "NO" << endl;
        }
        else
        {
            int ind = 0;
            for (int i = 0; i < k; i++)
                if (v[i][0] == p)
                    ind = i;
            // cout << ind << endl;
            if (ret(v, v[ind]))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
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
        // cout << t << endl;
        solve();
    }
    return 0;
}
/*
3 3
1 2 3
2 1 3
3 2 1

*/