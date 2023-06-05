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
        vector<int> a(n);
        for (auto &val : a)
            cin >> val;
        int ans = n;
        for (int diff = -201; diff < 202; diff++)
        {
            vector<int> v = a;
            int start = 0, end = 0;
            for (int j = 1; j < n; j++)
            {
                // diff = v[j] - v[j-1]
                // v[j] = diff + v[j-1]
                if ((v[j] - v[j - 1]) == diff)
                    continue;
                start++;
                v[j] = diff + v[j - 1];
            }
            v = a;
            for (int j = n - 2; j >= 0; j--)
            {
                // diff = v[j] - v[j+1]
                // v[j] = diff + v[j+1]
                if ((v[j] - v[j + 1]) == diff)
                    continue;
                end++;
                v[j] = diff + v[j + 1];
            }
            ans = min(ans, min(start, end));
        }
        cout << ans << endl;
    }
    return 0;
}