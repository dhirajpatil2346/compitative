#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
        }
        sort(v.begin(), v.end());
        int key = 1;
        int ans = 1;
        int i=0;
        while(i<n)
        {
            if (v[i] < key)
            {
                ans++;
                key = 1;
                continue;
            }
            i++;
            key++;
        }
        cout << ans<<endl;
    }
    return 0;
}