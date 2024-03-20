#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> plan(n), exe(n);
    for (auto &val : plan)
        cin >> val;
    for (auto &val : exe)
        cin >> val;
    multiset<int> red, green;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        red.insert(x);
    }
    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        green.insert(x);
    }
    return 0;
}