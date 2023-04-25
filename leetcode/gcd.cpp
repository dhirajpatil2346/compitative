#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int min_operations(vector<int> &nums)
{
    vector<long long> v;
    for (auto &val : nums)
        v.push_back(val);
    long long g = v[0];
    for (auto &val : v)
    {
        if (g == 1)
            break;
        g = __gcd(g, val);
    }
    if (g != 1)
        return -1;
    else
    {
        int n = v.size();
        long long ret = INT_MAX;
        
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int ops = min_operations(v);
    cout << ops << endl; // expected output: 3
    return 0;
}
