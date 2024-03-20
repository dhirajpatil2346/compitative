#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
    10 5
    2 3 0 0 0 2 3 1 1 0
    7
    1 2
    1 3
    1 7
    1 10
    2 7
    2 6
    3 8
    1 2 9 11 5 1 4
    */
    int n;
    cin >> n;
    vector<LL> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        v[i] += v[i - 1];
    map<LL, vector<LL>> m;
    for (int i = 0; i < n; i++)
        m[v[i]].push_back(i);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        LL prev = v[l - 1];
        // here we have got prev
        
    }
    return 0;
}