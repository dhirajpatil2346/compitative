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
    vector<int> neg, pos, final;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < 0)
        {
            neg.push_back(x);
        }
        else
        {
            pos.push_back(x);
        }
        final.push_back(abs(x));
    }
    if (neg.size() >= k)
    {
        ll sum = 0;
        sort(neg.begin(), neg.end());
        for (int i = 0; i < k; i++)
        {
            sum += abs(neg[i]);
        }
        for (int i = k; i < neg.size(); i++)
        {
            sum += neg[i];
        }
        sum += accumulate(pos.begin(), pos.end(), 0ll);
        cout << sum << endl;
    }
    else if ((k - neg.size()) % 2 == 0)
    {
        cout << accumulate(final.begin(), final.end(), 0ll) << endl;
    }
    else
    {
        sort(final.begin(), final.end());
        final[0]*=(-1);
        cout << accumulate(final.begin(), final.end(), 0ll) << endl;
    }
    return 0;
}