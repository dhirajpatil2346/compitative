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
    int maxi = *max_element(v.begin(), v.end());
    int freq = 0;
    for (auto &val : v)
    {
        val == maxi ? freq++ : freq += 0;
    }
    if (freq = 1)
    {
        int maxA = INT_MIN, maxI = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] & maxi < maxA)
            {
                maxI = i;
                maxA = v[i] & maxi;
            }
        }
        cout << v[maxI] << endl;
    }
    return 0;
}