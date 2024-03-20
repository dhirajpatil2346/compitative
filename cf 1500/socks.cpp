#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    map<int, int> left, right;
    for (int i = 0; i < l; i++)
    {
        int x;
        cin >> x;
        left[x]++;
    }
    for (int i = 0; i < r; i++)
    {
        int x;
        cin >> x;
        if (left.find(x) != left.end() && left[x] > 0)
            left[x]--;
        else
            right[x]++;
    }
    for (auto &val : left)
        if (val.second == 0)
            left.erase(left.find(val.first));
    vector<int> sololeft, soloright;
    for (auto &val : left)
        if (val.second & 1)
            sololeft.push_back(val.first);
    for (auto &val : right)
        if (val.second & 1)
            soloright.push_back(val.first);
    int cst = 0;
    while (sololeft.size() && soloright.size())
    {
        left[sololeft.back()]--;
        sololeft.pop_back();
        right[soloright.back()]--;
        soloright.pop_back();
        cst++;
    }
    for (auto &val : left)
        if (val.second == 0)
            left.erase(left.find(val.first));
    for (auto &val : right)
        if (val.second == 0)
            right.erase(right.find(val.first));
    while (sololeft.size() && right.size())
    {
        cst++;
        left.erase(sololeft.back());
        sololeft.pop_back();
        (right.begin())->second--;
        if ((right.begin())->second == 0)
        {
            right.erase(right.begin());
        }
    }
    for (auto &val : left)
        if (val.second == 0)
            left.erase(left.find(val.first));
    for (auto &val : right)
        if (val.second == 0)
            right.erase(right.find(val.first));

    while (soloright.size() && left.size())
    {
        cst++;
        right.erase(soloright.back());
        soloright.pop_back();
        (left.begin())->second--;
        if ((left.begin())->second == 0)
        {
            left.erase(left.begin());
        }
    }
    for (auto &val : left)
        if (val.second == 0)
            left.erase(left.find(val.first));
    for (auto &val : right)
        if (val.second == 0)
            right.erase(right.find(val.first));

    int stock = 0;
    for (auto &val : left)
    {
        if (val.second % 2 == 0)
        {
            cst += val.second / 2;
        }
        else
        {
            cst += val.second / 2 + 1;
        }
    }
    for (auto &val : right)
    {
        if (val.second % 2 == 0)
        {
            cst += val.second / 2;
        }
        else
        {
            cst += val.second / 2 + 1;
        }
    }
    return cst;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}