#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }
    sort(v.begin(),v.end());
    int req = (sum / 2) + 1;
    // cout<<req<<endl;
    int take = 0;
    int coins = 0;
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        take += *it;
        coins++;
        if (take >= req)
        {
            // cout<<take<<endl;
            cout << coins;
            return 0;
        }
    }
    return 0;
}