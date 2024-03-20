#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

int minimumMoves(vector<string> loggedMoves)
{
    int c = 0;
    for (auto &val : loggedMoves)
    {
        if (val[0] == '.')
        {
            int z = -1, i = 0;
            while (i < val.length() && val[i] == '.')
                z++, i++;
            c -= z;
        }
        else
        {
            c++;
        }
    }
    return c;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &val : v)
        cin >> val;
    cout << minimumMoves(v) << endl;
    return 0;
}