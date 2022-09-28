#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<int> value(n);
        string s;
        cin >> s;
        map<int, vector<int>> m;
        for (long long i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                value[i] = i;
                long long r = n - i - 1;
                long long l = i;
                long long modify = r - l;
                cout << i << " " << modify << endl;
                if (modify <= 0)
                {
                    continue;
                }
                else
                {
                    m[modify].push_back(i);
                }
            }
            else
            {
                value[i] = n - i - 1;
                long long r = n - i - 1;
                long long l = i;
                long long modify = l - r;
                cout << i << " " << modify << endl;
                if (modify <= 0)
                {
                    continue;
                }
                else
                {
                    m[modify].push_back(i);
                }
            }
        }
        cout << m.size() << endl;
        vector<int> added;
        for (auto &val : m)
        {
            // //cout << val.first<<" --> ";
            for (auto &valu : val.second)
            {
                added.push_back(val.first);
            }
        }
        reverse(added.begin(), added.end());
        long long sum = accumulate(value.begin(), value.end(), 0);
        cout << sum << endl;
        vector<int> final(n);
        for (long long i = 0; i < added.size(); i++)
        {
            final[i] = added[i];
        }
        for (long long i = 1; i < n; i++)
        {
            final[i] += final[i - 1];
            // cout << final[i] << " ";
        }
        // cout << endl;
        vector<int> ans(n, sum);
        for (long long i = 0; i < final.size(); i++)
        {
            ans[i] += final[i];
            // cout<<ans[i]<<" ";
        }
        // cout<<endl;
        for (long long i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}