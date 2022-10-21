#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ans = 0;
void merge(vector<int> &v, int l, int r)
{
    // cout << v[l] << " " << v[r] << endl;
    if (v[l] < v[r])
    {
        return;
    }
    ans++;
    for (int i = l; i < r; i++)
    {
        int temp = v[i];
        v[i] = v[i + l];
        v[i + l] = temp;
    }
    cout << l << " " << r << endl;
    for (auto &val : v)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}

void msort(vector<int> &v, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    msort(v, l, mid);
    msort(v, mid + 1, r);
    merge(v, l, mid + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans = 0;
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        vector<int> v1 = v;
        msort(v, 0, n / 2 - 1);
        msort(v, n / 2, n);
        sort(v1.begin(), v1.end());
        if (v == v1)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}