#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    int n;
    cin >> n;
    int part = n / 2;
    multiset<int> ms;
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        ms.insert(x);
        sum += x;
    }
    // cout << "nfjknkn" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            // cout << i << " " << j << endl;
            multiset<int> curr = ms;
            curr.erase(curr.find(v[i]));
            curr.erase(curr.find(v[j]));
            int k = v[i] + v[j];
            int b = v[j];
            bool fault = false;
            while (curr.size())
            {
                int need = k - b;
                if (curr.find(need) == curr.end())
                {
                    fault = true;
                    break;
                }
                else
                {
                    curr.erase(curr.find(need));
                }
                b = need;
            }
            // cout << i << " " << j << " " << fault << endl;
            if (fault == false)
                return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}