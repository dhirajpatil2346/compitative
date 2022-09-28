#include <bits/stdc++.h>
using namespace std;
#define ll long long

int bin(int l, int r, int n, vector<int> &v)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == n)
        {
            return mid;
        }
        else if (v[mid] > n)
        {
            return bin(l, mid - 1, n, v);
        }
        else
        {
            return bin(mid + 1, r, n, v);
        }
    }
    return -1;
}

int addBin(int l, int r, int n, vector<int> &v)
{
    // cout << l << "  " << r << endl;
    int mid = (l + r) / 2;
    if (l < r)
    {
        // 2 9 12 16 25
        // n == 1
        if (v[mid] > n)
        {
            return addBin(l, mid, n, v);
        }
        else
        {
            return addBin(mid + 1, r, n, v);
        }
    }
    return mid;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int z = bin(0, n - 1, x, v);
        if (z > -1)
        {
            cout << z + 1 << endl;
        }
        else
        {
            // cout << "2nd" << endl;
            cout << addBin(0, n - 1, x, v) + 1 << endl;
        }
    }
    return 0;
}