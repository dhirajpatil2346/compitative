#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n), curr;
    for (auto &val : v)
        cin >> val;
    stack<int> s;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (s.empty() || j == k)
        {
            s.push(v[i]);
        }
        else
        {
            while (!s.empty() && j < k && s.top() < v[i])
            {
                s.pop();
                j++;
            }
            s.push(v[i]);
        }
    }
    while (!s.empty())
    {
        curr.push_back(s.top());
        s.pop();
    }
    reverse(curr.begin(), curr.end());
    for (auto &val : curr)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}