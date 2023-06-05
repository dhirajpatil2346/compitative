#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
LL mod = 1e9 + 7;
bool bin(vector<int> &a, int x)
{
    int left = 0, right = a.size();
    while (left < right)
    {
        int middle = (left + right) / 2;
        cout << middle << " ";
        if (a[middle] <= x)
            left = middle + 1;
        else
            right = middle;
    }
    cout << endl;
    if (left > 0 && a[left - 1] == x)
        return true;
    return false;
}
void solve()
{
    int n, x, p;
    cin >> n >> x >> p;
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(i);
    bin(v, p);
    vector<int> track;
    {
        int l = 0, r = n;
        int u, P;
        while (l < r)
        {
            int mid = (l + r) / 2;
            // cout << "mid is "
            //      << " " << mid << " " << p << endl;
            if (mid == p)
            {
                // cout << "here" << endl;
                u = mid + 1, P = r - 1;
                // break;
            }
            track.push_back(mid);
            if (p >= mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        // for (auto &val : track)
        //     cout
        //         << val << " ";
        // cout << endl;
        // cout << u << " " << P << endl;
    }
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
        LL a = 78 * 81 * 80 * 79;
        LL b = 41 * 42;
        a = (a * b) % mod;
        for (LL i = 1; i <= 117; i++)
            a = (a * i) % mod;
        cout << a << endl;
        solve();
    }
    return 0;
}
/*
big are 4 and available are 81 -->  81 * 80 * 79 * 78
small are 2 available are 42 --> 42 * 41
remaining 117 --> 117!
*/