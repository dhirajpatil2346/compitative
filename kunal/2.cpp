#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
map<int, int> ind;
bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.second != p2.second)
        return p1.second > p2.second;
    return ind[p1.first] < ind[p2.first];
}
vector<int> freqSort(vector<int> listEle)
{
    ind.clear();
    for (int i = 0; i < listEle.size(); i++)
    {
        if (ind.find(listEle[i]) == ind.end())
            ind[listEle[i]] = i;
    }
    map<int, int> m;
    for (auto &val : listEle)
        m[val]++;
    vector<pair<int, int>> vp;
    for (auto &val : m)
        vp.push_back(val);
    sort(vp.begin(), vp.end(), cmp);
    vector<int> ans;
    for (auto &val : vp)
    {
        for (int i = 0; i < val.second; i++)
            ans.push_back(val.first);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    v = freqSort(v);
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
    return 0;
}