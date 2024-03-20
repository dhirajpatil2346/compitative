#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void merge(string &a, int l1, int r1, int l2, int r2)
{
    int ele = r1 - l1 + 1;
    bool f = true;
    for (int i = 0; i < ele; i++)
    {
        if (a[l1 + i] < a[l2 + i])
            break;
        if (a[l1 + i] > a[l2 + i])
        {
            f = false;
            break;
        }
    }
    if (!f)
    {
        for (int i = 0; i < ele; i++)
        {
            swap(a[l1 + i], a[l2 + i]);
        }
    }
}

void merge_sort(string &a, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge(a, l, mid, mid + 1, r);
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
}
void solve()
{
    string a, b;
    cin >> a >> b;
    merge_sort(a, 0, a.length() - 1);
    merge_sort(b, 0, b.length() - 1);
    if (a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}