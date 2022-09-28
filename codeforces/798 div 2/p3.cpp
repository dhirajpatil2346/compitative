#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
    }
    vector<int> vi(n);
    int m1 = 0, m2 = 0;
    if (n == 2)
    {
        cout << 0 << endl;
    }
    else if(v[0].size()==2)
    {
        queue<int> q;
        q.push(v[0][0]);
        while (!q.empty())
        {
            int curr = q.front();
            m1 += v[curr].size();
            for (auto &val : v[curr])
            {
                q.push(val);
            }
            q.pop();
        }

        queue<int> q1;
        q1.push(v[0][1]);
        while (!q1.empty())
        {
            int curr = q1.front();
            m2 += v[curr].size();
            for (auto &val : v[curr])
            {
                q1.push(val);
            }
            q1.pop();
        }
        cout << max(m1, m2) << endl;
    }
    else
    {
        queue<int> q;
        q.push(v[0][0]);
        while (!q.empty())
        {
            int curr = q.front();
            m1 += v[curr].size();
            for (auto &val : v[curr])
            {
                q.push(val);
            }
            q.pop();
        }

        cout<<m1<<endl;
    }
    return 0;
}