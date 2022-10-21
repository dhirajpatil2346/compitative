#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> vis(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int i = 0;
    int score = INT_MIN;
    while (i < n)
    {
        if (vis[i] || v[i] == 1)
        {
            i++;
            continue;
        }
        int sc = 0;
        vis[i] = true;
        int csum = 0;
        int j = i + 1;
        int inc = 0;
        while (j < n && csum <= 1)
        {
            if (v[j] == 1)
            {
                csum++;
                if (csum == 2)
                {
                    break;
                }
                else
                {
                    inc++;
                }
            }
            else
            {
                inc++;

                vis[j] = true;
            }
            j++;
        }
        sc += inc;
        inc = 0, csum = 0;
        j = i - 1;
        while (j >= 0 && csum <= 1)
        {
            if (v[j] == 1)
            {
                csum++;
                if (csum == 2)
                {
                    break;
                }
                else
                {
                    inc++;
                }
            }
            else
            {
                inc++;
                vis[j] = true;
            }
            j--;
        }
        sc += inc;
        score = max(sc, score);
        // cout << i << sc << endl;
        i++;
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum <= 1)
    {
        cout << sum << endl;
    }
    else
    {
        cout << score + 1<< endl;
    }
    return 0;
}