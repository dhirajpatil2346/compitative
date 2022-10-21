#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int i = 0;
    map<int, bool> m;
    int cnt = 0;
    int start = 0;
    int sc = 0;
    while (i < n)
    {
        if (m[v[i]])
        {
            cout << i << endl;
            sc++;
            i++;
        }
        else
        {
            m[v[i]] = true;
            cnt++;
            if (cnt == 6)
            {
                m.clear();
                cnt = 0;
            }
            i++;
        }
    }
    cout << sc + cnt << endl;
    return 0;
}