#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> v(2);
    cin >> v[0].first;
    cin >> v[0].second;
    cin >> v[1].first;
    cin >> v[1].second;
    sort(v.begin(), v.end());
    if (v[0].first == 0 && v[0].second == 0)
    {
        // one at origin
        if (v[1].first != 0 && v[1].second != 0)
        {
            if (v[1].first != v[1].second)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << 0 << " " << v[1].second << " " << v[1].first << " " << 0 << endl;
            }
        }
        else if (v[1].first != 0 || v[1].second != 0)
        {
            if (v[1].first == 0)
            {
                cout << v[1].second << " " << v[1].second << " " << v[1].second << " 0 " << endl;
            }
            else
            {
                cout << v[1].first << " " << v[1].first << " 0 " << v[1].first << endl;
            }
        }
    }
    else
    {
        
    }
    return 0;
}