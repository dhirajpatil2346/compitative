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
    for (int i = 0; i < n - 1; i++)
    {
        while (v[i] > -1 && v[i + 1] > -1)
        {
            v[i]--;
            v[i + 1] -= 2;
        }
    }
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;
    return 0;
}