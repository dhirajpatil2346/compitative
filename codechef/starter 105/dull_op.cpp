#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solution()
{
    LL sz;
    bool sign_for_boolean = true;
    cin >> sz;
    vector<LL> vctr(sz);
    for (auto &val : vctr)
        cin >> val;
    LL array_accumulation = 0;
    for (auto &val : vctr)
        array_accumulation += val;
    if (array_accumulation % sz != 0)
    {
        sign_for_boolean = false;
    }
    LL d = array_accumulation / sz;
    for (auto &val : vctr)
    {
        LL pos = val - d;
        if (pos % 2 != 0)
        {
            sign_for_boolean = false;
        }
    }
    if (sign_for_boolean)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solution();
    }
    return 0;
}