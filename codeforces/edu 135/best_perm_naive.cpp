#include <bits/stdc++.h>
using namespace std;
int calc(vector<int> &v)
{
    int x = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (x < v[i])
        {
            x += v[i];
        }
        else
        {
            x = 0;
        }
    }
    return x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        int maxi = calc(v);
        vector<int> ans = v;
        do
        {
            int j = calc(v);
            if (j > maxi)
            {
                ans = v;
                maxi = j;
                if (j == (n + n - 1))
                {
                    break;
                }
            }
        } while (next_permutation(v.begin(), v.end()));
        for (auto &val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}