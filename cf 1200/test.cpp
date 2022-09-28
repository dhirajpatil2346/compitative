#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int start = 0, end = 0;
    int mstart = 0, mend = 0;
    int curr = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            curr++;
            if (curr >= maxi)
            {
                maxi = curr;
                mstart = start;
                mend = i;
            }
        }
        else
        {
            curr--;
            if (curr < 0)
            {c
                start = i + 1;
                curr = 0;
            }
        }
    }
    // cout << mstart << " " << mend << endl;
    for (int i = mstart; i <= mend; i++)
    {
        if (v[i] == 0)
        {
            v[i] = 1;
        }
        else if (v[i] == 1)
        {
            v[i] = 0;
        }
    }
    cout << accumulate(v.begin(), v.end(), 0);
    return 0;
}