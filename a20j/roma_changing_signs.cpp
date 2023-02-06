#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<int> neg;
    vector<int> pos;
    vector<int> final;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x >= 0)
        {
            pos.push_back(x);
        }
        else
        {
            neg.push_back(x);
        }
        final.push_back(x);
    }
    if (neg.size() >= k)
    {
        sum += accumulate(pos.begin(), pos.end(), 0ll);
        // cout << sum << endl;
        // (neg.begin(), neg.end());
        int op = min(k, int(neg.size()));
        for (int i = 0; i < op; i++)
        {
            sum += abs(neg[i]);
        }
        // cout << op << endl;
        for (int i = op; i < neg.size(); i++)
        {
            sum += neg[i];
        }
        cout << sum << endl;
    }
    else if (((k - neg.size()) % 2) == 0)
    {
        sum += accumulate(pos.begin(), pos.end(), 0ll);
        // reverse(neg.begin(), neg.end());
        int op = min(k, int(neg.size()));
        for (int i = 0; i < op; i++)
        {
            sum += abs(neg[i]);
        }
        for (int i = op; i < neg.size(); i++)
        {
            sum += neg[i];
        }
        cout << sum << endl;
    }
    else
    {
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (abs(final[i]) < abs(final[ind]))
            {
                ind = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == ind)
            {
                continue;
            }
            sum += abs(final[i]);
        }
        final[ind] *= (-1);
        sum += final[ind];
        cout << sum << endl;
    }
    return 0;
}