#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    sort(v.begin(), v.end());
    int pos = n + 1;
    for (int i = 1; i <= n; i++)
    {
        // cout<<i<<v[i]<<endl;
        if (i != v[i-1])
        {
            pos = i;
            break;
        }
    }
    cout << pos << endl;
    return 0;
}