#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    sort(v.begin(), v.end());
    deque<int> q;
    for (auto &val : v)
    {
        q.push_front(val);
    }
    int c = 0;
    while (!q.empty())
    {
        int front = q.front();
        int needed = m / front + 1;
        if (q.size() >= needed)
        {
            c++;
            q.pop_front();
            while (--needed)
            {
                q.pop_back();
            }
        }
        else
        {
            break;
        }
    }
    cout << c << endl;
    return 0;
}