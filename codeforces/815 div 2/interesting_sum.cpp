#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = INT_MIN;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    vector<int> maxiStart(n), maxiEnd(n), miniStart(n), miniEnd(n);
    maxiStart[0] = v[0], miniStart[0] = v[0], maxiEnd[n - 1] = v[n - 1], miniEnd[n - 1] = v[n - 1];
    // for maxiStart
    int maxi = v[0];
    for (int i = 1; i < n; i++)
    {
        maxiStart[i] = max(v[i], maxi);
        maxi = max(maxi, v[i]);
    }
    // for maxiEnd
    maxi = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxiEnd[i] = max(v[i], maxi);
        maxi = max(maxi, v[i]);
    }
    // for miniStart
    int mini = v[0];
    for (int i = 1; i < n; i++)
    {
        miniStart[i] = min(v[i], mini);
        mini = min(v[i], mini);
    }
    // for miniEnd
    mini = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        miniEnd[i] = min(v[i], mini);
        mini = min(v[i], mini);
    }
    /*
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto &val : maxiStart)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto &val : miniStart)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto &val : maxiEnd)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto &val : miniEnd)
    {
        cout << val << " ";
    }
    cout << endl;
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int maxiLR = v[i], miniLR = v[i];
            for (int k = i; k <= j; k++)
            {
                maxiLR = max(maxiLR, v[k]);
                miniLR = min(maxiLR, v[k]);
            }
            int t1, t2, t3, t4;
            if (i == 0 && j == n - 1)
            {
                t1 = 0, t2 = 0, t3 = 0, t4 = 0;
            }
            else if (i == 0 && j != n - 1)
            {
                t1=0, t2=maxiEnd[j+1],t3=0, 
            }
            else if (i != 0 && j == n - 1)
            {
            }
            else
            {
            }
            // int f = max(maxiStart[i - 1], maxiEnd[j + 1]) - min(miniStart[i - 1], miniEnd[j + 1]) + maxiLR - miniLR;
            cout << i << " " << j << " " << t1 << " " << t2 << " " << maxiLR << " " << miniLR << " " << f << endl;
            ans = max(f, ans);
        }
    }
    cout << ans << endl;
    return 0;
}



/*
11122356
112788

1718
*/