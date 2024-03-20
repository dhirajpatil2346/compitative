#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<LL> primes;
void sieve()
{
    int N = 1e4 + 1;
    vector<bool> prime(N, true);
    prime[0] = false, prime[1] = false;
    for (int i = 0; i < prime.size(); i++)
        if (prime[i])
            for (int j = i * i; j < prime.size(); j += i)
                prime[j] = false;
    for (LL i = 0; i < prime.size(); i++)
        if (prime[i])
            primes.push_back(i);
}
void handle(int &n)
{
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    for (int i = 0; i < n; i += 2)
    {
        int num1 = v[i], num2 = v[i + 1];
        if ((num1 > 0 && num2 < 0) || (num1 < 0 && num2 > 0))
        {
            cout << abs(num2) << " " << abs(num1) << " ";
        }
        else
        {
            cout << (-1ll) * abs(num2) << " " << abs(num1) << " ";
        }
    }
    cout << endl;
}

vector<LL> three(vector<LL> &v, int ind)
{
    LL a = v[ind], b = v[ind + 1], c = v[ind + 2];
    if ((a + b) != 0)
    {
        // -4 6 8
        LL g = __gcd(abs(a + b), abs(c));
        LL f1 = (a + b) / g, f2 = c / g;
        if ((a + b) * c < 0)
            return {abs(f2), abs(f2), abs(f1)};
        else
            return {abs(f2), abs(f2), (-1ll) * abs(f1)};
    }
    else if ((b + c) != 0)
    {
        // -5 5 5
        LL g = __gcd(abs(a), abs(b + c));
        LL f1 = a / g, f2 = (b + c) / g;
        if ((b + c) * a < 0)
            return {abs(f2), abs(f1), abs(f1)};
        else
            return {(-1ll) * abs(f2), abs(f1), abs(f1)};
    }
    else
    {
        // a + c != 0
        LL g = __gcd(abs(a + c), abs(b));
        LL f1 = (a + c) / g, f2 = b / g;
        if ((a + c) * b < 0)
        {
            return {abs(f2), abs(f1), abs(f2)};
        }
        return {abs(f2), (-1ll) * abs(f1), abs(f2)};
    }
}

void solve()
{
    int n;
    cin >> n;
    if (!(n & 1))
    {
        handle(n);
        return;
    }
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    // sort(v.begin(), v.end());
    LL mini = 1e11, p = 0;
    vector<LL> ans;
    for (int i = 0; i < n - 2; i++)
    {
        vector<LL> cur = three(v, i);
        LL s = 0;
        for (auto &val : cur)
            s += abs(val);
        if (s < mini)
        {
            p = i, mini = s;
            ans = cur;
        }
    }
    set<LL> s;
    if (n > 2)
        s = {p, p + 1, p + 2};
    vector<int> vn;
    for (int i = 0; i < n; i++)
        if (s.find(i) == s.end())
            vn.push_back(v[i]);
    vector<int> vans(n);
    for (int i = 0; i < vn.size(); i += 2)
    {
        int num1 = vn[i], num2 = vn[i + 1];
        if ((num1 > 0 && num2 < 0) || (num1 < 0 && num2 > 0))
            vans[i] = abs(num2), vans[i + 1] = abs(num1);
        else
            vans[i] = num2, vans[i + 1] = (-1) * num1;
        LL g = __gcd(abs(vans[i]), abs(vans[i + 1]));
        vans[i] /= g, vans[i + 1] /= g;
        // cout << g << endl;
    }
    int cp = 0, i = 0, j = 0;
    for (cp = 0; cp < n; cp++)
    {
        if (cp >= p && i < 3)
        {
            cout << ans[i++] << " ";
        }
        else
            cout << vans[j++] << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}