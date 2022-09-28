#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    int len = ceil(sqrt(n));
    vector<int> pre(len);
    for (int i = 0; i < n; i++)
    {
        pre[i / len] += v[i];
    }
    /*
    for (auto &val : pre)
    {
        cout << val << " ";
    }
    cout << endl;
    */
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, sum = 0;
        cin >> l >> r;
        for (int i = l; i <= r;)
        {
            if (i % len == 0 && i + len - 1 <= r)
            {
                sum += pre[i / len];
                i += len;
            }
            else
            {
                sum += v[i];
                i++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
/*
16
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/