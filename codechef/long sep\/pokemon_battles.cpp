#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n), v2(n);
        vector<unordered_set<int>> score(n);
        map<int, int> owner;
        // for v1
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
            owner[v1[i]] = i;
        }
        sort(v1.begin(), v1.end());
        unordered_set<int> us;
        for (int i = 0; i < n; i++)
        {
            score[owner[v1[i]]] = us;
            us.insert(owner[v1[i]]);
        }
        owner.clear();
        us.clear();
        // for v2
        for (int i = 0; i < n; i++)
        {
            cin >> v2[i];
            owner[v2[i]] = i;
        }
        sort(v2.begin(), v2.end());
        for (int i = 0; i < n; i++)
        {
            score[owner[v2[i]]].insert(us.begin(), us.end());
            us.insert(owner[v2[i]]);
        }
        int z = n - 1;
        int a = 0;
        int maxi = INT_MIN;
        for (auto &val : score)
        {
            int j = val.size();
            maxi = max(maxi, j);
        }
        for (auto &val : score)
        {
            int j = val.size();
            if (j == maxi)
            {
                a++;
            }
        }
        cout << a << endl;
    }
    return 0;
}