#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_set<int> us;
        for (auto &val : v)
        {
            cin >> val;
            us.insert(val);
        }
        sort(v.begin(), v.end());
        if (us.size() == n && n == 2)
        {
            printVec(v);
        }
        else if (n == us.size())
        {
            int p1 = 0, p2 = 1;
            int diff = v[1] - v[0];
            for (int i = 0; i < n - 1; i++)
            {
                if ((v[i + 1] - v[i]) < diff)
                {
                    p1 = i, p2 = i + 1;
                    diff = v[i + 1] - v[i];
                }
            }
            vector<int> start, end;
            for (int i = 0; i <= p1; i++)
            {
                end.push_back(v[i]);
            }
            for (int i = p2; i < n; i++)
            {
                start.push_back(v[i]);
            }
            start.insert(start.end(), end.begin(), end.end());
            printVec(start);
        }
        else
        {
            int p1 = 0, p2 = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (v[i] == v[i + 1])
                {
                    p1 = i, p2 = i + 1;
                    break;
                }
            }
            vector<int> start, end;
            for (int i = 0; i <= p1; i++)
            {
                end.push_back(v[i]);
            }
            for (int i = p2; i < n; i++)
            {
                start.push_back(v[i]);
            }
            start.insert(start.end(), end.begin(), end.end());
            printVec(start);
        }
    }
    return 0;
}