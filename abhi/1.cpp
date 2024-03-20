#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

long f(vector<long> &v)
{
    long ret = 0;
    int n = v.size();
    map<long, vector<int>> m;
    vector<long> org = v;
    map<long, vector<long>> type;
    for (int i = 0; i < n; i++)
        type[v[i]].push_back(v[i]);
    long two = 2;
    for (auto &val : type)
    {
        for (int i = 1; i < val.second.size(); i++)
            val.second[i] = val.second[i - 1] / two + val.second[i-1] % two;
    }
    for (auto &val : type)
    {
        for (auto &valu : val.second)
            ret += valu;
    }
    return ret;
}
long findTotalExecutionTime(vector<int> execution)
{
    vector<long> v;
    for (auto &val : execution)
        v.push_back(val);
    return f(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    cout << findTotalExecutionTime(v) << endl;
    return 0;
}