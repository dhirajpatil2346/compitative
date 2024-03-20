#include <bits/stdc++.h>
using namespace std;
int getMaxiMumpower(vector<int> arr, vector<int> power)
{
    const long long mod = 1e9 + 7;
    long long ans = 0;
    int n = arr.size();
    vector<long long> v;
    for (auto &val : arr)
        v.push_back(val);
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    int k = power.size();
    vector<long long> ind;
    for (auto &val : power)
        ind.push_back(val);
    sort(ind.begin(), ind.end());
    int i = 0, j = k - 1;
    while (i < j)
    {
        long long find = ind[i], rind = ind[j];
        long long sumf = 0, sumr = 0;
        if (find > 0)
            sumf = v[find - 1];
        sumr = v[rind];
        long long sum = 0;
        sum = sumr - sumf;
        sum = (sum + mod) % mod;
        ans = (ans + sum) % mod;
        i++, j--;
    }
    int ret = ans;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    const long long mod = 1e9 + 7;
    long long ans = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int k;
    cin >> k;
    vector<int> power(k);
    for (auto &val : power)
        cin >> val;
    cout << getMaxiMumpower(v, power) << endl;
    return 0;
}