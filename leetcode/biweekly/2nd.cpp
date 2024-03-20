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

int strtoint(string &s)
{
    int num = 0;
    for (char val : s)
    {
        num *= 10;
        num += (val - '0');
    }
    return num;
}

int Solution(vector<int> numbers)
{
    map<int, set<int>> m;
    int n = numbers.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num = numbers[i];
        string s = to_string(num);
        set<int> ret;
        if (m.find(numbers[i]) != m.end())
        {
            for (auto &val : m[numbers[i]])
                ret.insert(val);
        }
        cout << i << " " << ret.size() << endl;
        int len = s.length();
        for (int j = 0; j < s.length(); j++)
        {
            for (int k = j + 1; k < s.length(); k++)
            {
                swap(s[j], s[k]);
                if (s[0]=='0')
                {
                    swap(s[j], s[k]);
                    continue;
                }
                if (i == 9)
                {
                    cout << s << endl;
                }
                int curr = strtoint(s);
                if (m.find(curr) != m.end())
                {
                    for (auto &val : m[curr])
                        ret.insert(val);
                }
                swap(s[j], s[k]);
            }
        }
        ans += ret.size();
        cout << i << " " << ans << endl;
        m[numbers[i]].insert(i);
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
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    cout << Solution(v) << endl;
    return 0;
}