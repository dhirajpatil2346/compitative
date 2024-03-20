#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
LL f(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = f(a, p / 2);
    res = (res * res) % mod;
    if (p & 1)
        res = (res * a) % mod;
    return res;
}
bool isPrime(LL n)
{
    for (LL i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void sieve(LL n, map<LL, LL> &mp)
{
    for (LL i = 2; i * i <= n; i++)
        while (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
    if (n > 1)
        mp[n] = 1;
}

void solve()
{
    LL x, n;
    cin >> x >> n;
    map<LL, LL> mp;
    sieve(x, mp);
    LL ans = 1;
    for (auto &val : mp)
    {
        LL curr = val.first;
        while (curr <= n)
        {
            LL ccnt = n / curr;
            if ((curr > (n / val.first)) && ((val.first > (n / curr))))
            {
                ans = (ans * f(curr, ccnt)) % mod;
                curr *= val.first;
                break;
            }
            cout << curr * val.first << endl;
            ccnt -= (n / (curr * val.first));
            cout << " curr " << curr << endl;
            ans = (ans * f(curr, ccnt)) % mod;
            curr *= val.first;
            cout << "ans is : " << ans << endl;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}