#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int get(int ind, int l, int r, vector<int> &v, vector<int> &a, int L, int R)
{
    // l and r we want
    // L and R are om seg tree
    if (l > r)
        return INT_MAX;
    if (l > R || r < L)
        return INT_MAX;
    // L R lies under l ,r
    if (l <= L && R <= r)
    {
        return a[ind];
    }
    int mid = (L + R) / 2;
    return (get(ind * 2, l, r, v, a, L, mid) & get(ind * 2 + 1, l, r, v, a, mid + 1, R));
}

void build(int ind, int l, int r, vector<int> &v, vector<int> &a)
{
    // l and r are array pos
    if (l > r)
        return;
    if (l == r)
    {
        a[ind] = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ind * 2, l, mid, v, a);
    build(ind * 2 + 1, mid + 1, r, v, a);
    a[ind] = (a[ind * 2] & a[ind * 2 + 1]);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> a(4 * n);
    build(1, 1, n, v, a);
    int q;
    cin >> q;
    while (q--)
    {
        int l, x;
        cin >> l >> x;
        int ind = -1;
        int L = l, R = n;
        while (L <= R)
        {
            int mid = (L + R) / 2;
            int val = get(1, l, mid, v, a, 1, n);
            if (val >= x)
            {
                ind = mid;
                L = mid + 1;
            }
            else
                R = mid - 1;
        }
        cout << ind << " ";
    }
    cout << endl;
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
        solve();
    }
    return 0;
}