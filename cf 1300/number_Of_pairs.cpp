#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long goe(vector<long long> &v, long long val, long long l, long long r)
{
    long long mid = l + (r - l) / 2;
    if (l == r)
    {
        if (v[l] >= val)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
    if (v[mid] >= val)
    {
        return goe(v, val, l, mid);
    }
    else
    {
        return goe(v, val, mid + 1, r);
    }
}
long long loe(vector<long long> &v, long long val, long long l, long long r)
{
    long long mid = l + (r - l) / 2;
    if (l == r)
    {
        if (v[l] <= val)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
    if (r - l == 1)
    {
        if (v[r] <= val)
        {
            return r;
        }
        if (v[l] <= val)
        {
            return l;
        }
        return -1;
    }
    if (v[mid] <= val)
    {
        return loe(v, val, mid, r);
    }
    else
    {
        return loe(v, val, l, mid);
    }
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, r, l;
        cin >> n >> l >> r;
        vector<long long> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.begin(), v.end());
        for (auto &val : v)
        {
            // cout << val << " ";
        }
        // cout << endl;
        long long ans = 0;
        for (long long i = 0; i < n - 1; i++)
        {
            long long n1 = l - v[i], n2 = r - v[i];
            long long p1 = goe(v, n1, i + 1, n - 1);
            long long p2 = loe(v, n2, i + 1, n - 1);
            // cout << v[i] << " " << n1 << " " << n2 << endl;
            // cout << p1 << " " << p2 << endl;
            if (p1 == -1 || p2 == -1 || p1 > p2)
            {
                continue;
            }
            ans += abs(p1 - p2) + 1;
        }
        cout << ans << endl;
    }
    return 0;
}