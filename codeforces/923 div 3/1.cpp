#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;

int block = 1;
struct query
{
    int L, R, ind;
    pair<int, int> ans = {-1, -1};
    query(int l = 0, int r = 0, int i = 0) : L(l), R(r), ind(i) {}
};

bool cmp(query &a, query &b)
{
    if (((a.L) / block) != ((b.L) / block))
        return ((a.L) / block) < ((b.L) / block);
    return a.R < b.R;
}

void solve()
{
    LL n;
    cin >> n;
    block = sqrt(n);
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> big, small;
    for (int i = 1; i < n; i++)
        if (v[i] > v[i - 1])
            big.push_back(i);
        else if (v[i] < v[i - 1])
            small.push_back(i);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        bool g = false;
        auto it = lower_bound(big.begin(), big.end(), l);
        if (it != big.end() && *it < r)
        {
            cout << *it+1 << " " << *it  << endl;
            continue;
        }
        it = lower_bound(small.begin(), small.end(), l);
        if (it != small.end() && *it < r)
        {
            cout << *it+1 << " " << *it  << endl;
            
        }else cout<<"-1 -1"<<endl;
        
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}