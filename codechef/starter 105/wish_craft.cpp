#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int p, q, n;
    cin >> n >> p >> q;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    LL a = v[0], b = v.back();
    swap(a, b);
    deque<LL> vn;
    for (int i = 1; i < n - 1; i++)
        vn.push_back(v[i]);
    // cout << "->" << a << " " << b << endl;
    while (vn.size())
    {
        if (p == 0 && q == 0)
            break;
        LL f = vn.front(), bc = vn.back();
        LL curr = 0;
        if (abs(f) >= abs(bc))
        {
            curr = f;
            vn.pop_front();
        }
        else
        {
            curr = bc;
            vn.pop_back();
        }
        if (curr == 0)
            continue;
        // cout << curr << endl;
        if (p)
        {
            if (curr >= 0)
            {
                a += curr;
            }
            else
            {
                b += curr;
            }
            p--;
        }
        else
        {
            // we are doing minus now
            if (curr <= 0)
            {
                a -= curr;
            }
            else
            {
                b -= curr;
            }
            q--;
        }
        // cout << a << " " << b << endl;
    }
    cout << a - b << endl;
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
// -6  -1   17
/*
6
1 2
8 -1 -4 2 6 -3

*/