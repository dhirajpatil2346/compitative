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

bool ispal(string s)
{
    string b = s;
    reverse(b.begin(), b.end());
    return b == s;
}

string breakPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int p1 = i;
        int p2 = n - i - 1;
        if (p1 > p2)
            break;
        if (s[p1] == s[p2])
            continue;
        char mini = min(s[p1], s[p2]);
        s[p1] = mini, s[p2] = mini;
        break;
    }
    if (ispal(s))
        return s;
    return "IMPOSSIBLE";
}

vector<string> bitPattern(vector<int> &num)
{
    multiset<int> prev, later;
    for (auto &val : num)
        later.insert(val);
    vector<string> ans(2, "");
    for (auto &val : num)
    {
        later.erase(later.find(val));
        if (prev.find(val) != prev.end())
            ans[0].push_back('1');
        else
            ans[0].push_back('0');
        if (later.find(val) != later.end())
            ans[1].push_back('1');
        else
            ans[1].push_back('0');
        prev.insert(val);
    }
    return ans;
}

int minPArtitions(vector<int> used, vector<int> totalCapacity)
{
    sort(totalCapacity.begin(), totalCapacity.end());
    int total = accumulate(used.begin(), used.end(), 0), ans = 0;
    while (total > 0)
    {
        total -= totalCapacity.back();
        totalCapacity.pop_back();
        ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> num(n);
    for (auto &val : num)
        cin >> val;
    vector<string> ans = bitPattern(num);
    for (auto &val : ans)
        cout << val << endl;
    return 0;
}