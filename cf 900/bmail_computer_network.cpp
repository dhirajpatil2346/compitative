#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> parent(n + 1, -1);
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
    }
    vector<int> ans;
    int p = n;
    while (p != -1)
    {
        ans.push_back(p);
        p = parent[p];
    }
    reverse(ans.begin(), ans.end());
    for (auto &val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}