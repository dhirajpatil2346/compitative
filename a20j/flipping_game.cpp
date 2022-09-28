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
        if (val == 1)
        {
            val = -1;
        }
        else
        {
            val = 1;
        }
    }
    int maxi = v[0];
    int curr_sum = maxi;
    int start = 0, end = 0;
    for (auto &val : v)
    {
        // cout << val << " ";
    }
    // cout << endl;
    for (int i = 1; i < n; i++)
    {
        // cout << i << "  " << curr_sum << "    " << v[i] << endl;
        if (curr_sum + v[i] < v[i])
        {
            // cout << "This" << endl;
            start = i, end = i;
            curr_sum = v[i];
            maxi = max(maxi, curr_sum);
        }
        else if (v[i] == 1)
        {
            // cout << "here"<< " " << end << endl;
            end = i;
            curr_sum++;
            maxi = max(maxi, curr_sum);
        }
        else if (v[i] == -1)
        {
            curr_sum--;
        }
    }
    // cout << maxi << "   " << start << " " << end << endl;
    for (auto &val : v)
    {
        if (val == -1)
        {
            val = 1;
        }
        else
        {
            val = 0;
        }
    }
    /*
    for (auto &val : v)
    {
        //cout << val << " ";
    }
    //cout << endl;
    */
    if (maxi < 0)
    {
        cout << accumulate(v.begin(), v.end(), 0) - 1;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            if (v[i] == 0)
            {
                v[i] = 1;
            }
            else
            {
                v[i] = 0;
            }
        }
        cout << accumulate(v.begin(), v.end(), 0);
        /*
        for (auto &val : v)
        {
            //cout << val << " ";
        }
        //cout << endl;
        */
    }
    return 0;
}