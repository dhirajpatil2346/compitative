#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    char target = s[s.length() - 1];
    int p = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (s[i] == target)
        {
            p = i;
        }
    }
    int cost = abs(s[0] - v[0]);
    for (int i = 0; i < p; i++)
    {
        cost += (v[i + 1] - v[i]);
    }
    cout << cost << " " << p + 1 << endl;
    return 0;
}