#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
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
        vector<pair<pair<int, int>, int>> ans;
        int i = 0;
        int tsum = 0;
        int p = 0, neg = 0;
        while (i < n)
        {
            if (i == n)
            {
                break;
            }
            // // cout << i << endl;
            int start = i;
            int sum = 0;
            bool sk = false;
            while (i < n)
            {
                // // cout << i << endl;
                if ((i - start) % 2 == 0)
                {
                    sum += v[i];
                    // cout << i << "  " << sum << endl;
                    i++;
                }
                else
                {
                    sum -= v[i];
                    // cout << i << "  " << sum << endl;
                    i++;
                }
                if (sum >= 2)
                {
                    sk = true;
                    p++;
                    ans.push_back({{start, i + 1}, 1});
                    sum = 0;
                    break;
                }
                if (sum <= -2)
                {
                    // cout << i << "  " << sum << endl;
                    sk = true;
                    neg++;
                    ans.push_back({{start, i + 1}, -1});
                    sum = 0;
                    break;
                }
                if (sum == 1 && neg)
                {
                    neg--;
                    // sum = 0;
                    break;
                }

                if (sum == -1 && p)
                {
                    p--;
                    // sum = 0;
                    break;
                }
                if(sum==0)
                {
                    break;
                }
            }
            if (sk)
            {
            }
            else
            {
                cout << i << endl;
                int end = i;
                tsum += sum;
                ans.push_back({{start, end}, sum});
            }
        }
        tsum = 0;
        for (auto &val : ans)
        {
            tsum += val.second;
        }
        if (tsum != 0)
        {
            cout << -1 << endl;
        }
        // else
        // {
            cout << ans.size() << endl;
            for (auto &val : ans)
            {
                cout << val.first.first + 1 << " " << val.first.second << " " << val.second << endl;
            }
        // }
    }
    return 0;
}