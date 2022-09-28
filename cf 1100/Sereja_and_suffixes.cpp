#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m), v3(n);
    for (auto &val : v1)
    {
        cin >> val;
    }
    for (auto &val : v2)
    {
        cin >> val;
    }
    unordered_set<int> us;
    int i = n - 1;
    while (i != -1)
    {
        us.insert(v1[i]);
        v3[i]=us.size();
        i--;
    }
    for (int i = 0; i < m; i++)
    {
        cout<<v3[v2[i]-1]<<endl;
    }
    
    return 0;
}