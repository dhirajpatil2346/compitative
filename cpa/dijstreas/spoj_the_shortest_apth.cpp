/*

Input:
1
4
gdansk
2
2 1
3 3
bydgoszcz
3
1 1
3 1
4 4
torun
3
1 3
2 1
4 1
warszawa
2
2 4
3 1
2
gdansk warszawa
bydgoszcz warszawa

*/

/*
Output:
3
2
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<pair<int, int>> g[N];

vector<int> dist(N, INT_MAX);
void reset()
{
    for (auto &val : dist)
    {
        val = INT_MAX;
    }
}

void Dijstras(int source)
{
    vector<bool> vis(N, false);
    set<pair<int, int>> s;
    dist[source] = 0;
    s.insert({0, source});
    while (s.size() > 0)
    {
        pair<int, int> curr = *s.begin();
        s.erase(s.begin());
        int v_wt = curr.first;
        int v = curr.second;
        if (vis[v])
        {
            continue;
        }
        vis[v] = true;
        for (auto &val : g[v])
        {
            int curr_wt = val.second;
            int target_v = val.first;
            if (dist[target_v] > dist[v] + curr_wt)
            {
                dist[target_v] = dist[v] + curr_wt;
                s.insert({dist[target_v], target_v});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<string, int> m;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            m[s] = i;
            int con;
            cin >> con;
            for (int j = 0; j < con; j++)
            {
                int x, y;
                cin >> x >> y;
                g[i].push_back({x, y});
            }
        }
        int tc;
        cin >> tc;
        set<int> to_test;
        map<pair<int, int>, bool> need;
        map<pair<int,int>, int> ans;
        vector<pair<string, string>> test_cases;
        for (int i = 0; i < tc; i++)
        {
            string x, y;
            cin >> x >> y;
            test_cases.push_back({x, y});
            to_test.insert(m[x]);
            need[{m[x],m[y]}]=true;
        }
        for (auto it = to_test.begin(); it != to_test.end(); it++)
        {
            reset();
            Dijstras(*it);
            int sc = *it;
            for (int i = 1; i <= n; i++)
            {
                if(need[{sc,i}])
                {
                    ans[{sc,i}]=dist[i];
                }
            }
        }
        for(auto &val:test_cases)
        {
            cout<<ans[{m[val.first], m[val.second]}]<<endl;
        }
    }
    return 0;
}