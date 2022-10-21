#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int i = 0;
    while (i < n)
    {
        int start = i;
        if (v[i] < i)
        {
            i++;
            continue;
        }
    }
    return 0;
}