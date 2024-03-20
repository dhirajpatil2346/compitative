#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<LL> fib1(1e5 + 15, 0ll), fib2(1e5 + 15, 0ll);
const LL K = 2e5 + 10;
void solve()
{
    LL n, k;
    cin >> n >> k;
    if (k == 3)
    {
        LL a = 0;
        for (LL x = 0;; x++)
        {
            LL y = n - x;
            if (x > y)
                break;
            a++;
        }
        cout << a << endl;
        return;
    }

    if (k > K)
    {
        cout << 0 << endl;
        return;
    }
    k--;
    LL X = fib1[k], Y = fib2[k], a = 0;
    // cout << X << " " << Y << endl;
    if (Y == 0)
    {
        cout << 0 << endl;
        return;
    }
    for (LL x = 0;; x++)
    {
        LL num = n - X * x, den = Y;
        if (num % den)
            continue;
        LL y = num / den;
        // cout << x << " " << y << endl;
        if (x > y)
            break;
        a++;
    }
    cout << a << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fib1[3] = 1, fib2[3] = 2;
    fib1[4] = 2, fib2[4] = 3;
    for (int i = 5; i < fib1.size(); i++)
    {
        fib1[i] = fib1[i - 1] + fib1[i - 2], fib2[i] = fib2[i - 1] + fib2[i - 2];
        if (fib2[i] > K)
            break;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}