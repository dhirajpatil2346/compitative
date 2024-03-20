#include <bits/stdc++.h>
using namespace std;
#define LL long long
int smallszarr(vector<LL> &arr, int k)
{

    unordered_map<long long, int> unmap;
    int n = arr.size();
    long long ishuSum = 0;
    long long result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ishuSum += arr[i];
        if (ishuSum == k)
        {
            long long currLen = i + 1;
            result = min(result, currLen);
        }
        long long thisWasReq = ishuSum - k;
        if (unmap.count(thisWasReq))
        {
            long long foundIdx =
                unmap[thisWasReq];
            long long currIdx = i;

            result = min(result,
                         currIdx - foundIdx);
        }

        unmap[ishuSum] = i;
    }

    if (result >= INT_MAX)
        return -1;
    return result;
}

class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        long long t = target;
        vector<LL> v;
        for (auto &val : nums)
            v.push_back(val);
        LL ret = 0, n = v.size();
        LL acc = accumulate(v.begin(), v.end(), 0ll);
        LL f = t / acc;
        ret = f * n;
        t %= acc;
        // cout << t << endl;
        if (t == 0)
            return (int)ret;
        // yes i can take and subarray
        LL z = smallszarr(v, t);
        // cout << "func z : " << z << endl;
        // will look for pref
        if (z == -1)
            z = 1e9;
        map<LL, LL> m;
        LL c = 0;
        m[0] = 0;
        for (LL i = 0; i < n; i++)
        {
            c += v[i];
            if (m.find(c) == m.end())
                m[c] = i + 1;
            // cout << c << " ";
        }
        // cout << endl;
        if (m.find(t) != m.end())
        {
            z = min(z, m[t]);
        }
        c = 0;
        for (LL i = n - 1, used = 1; i >= 0; i--, used++)
        {
            c += v[i];
            LL need = t - c;
            // cout << " need : " << need << endl;
            if (need < 0)
                break;
            ;
            if (m.find(need) != m.end())
                z = min(z, used + m[need]);
            // cout << "now z : " << z << endl;
        }
        if (z == 1e9)
            return -1;
        // cout << "z" << z << endl;
        ret += z;
        return (int)ret;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    Solution sc;
    cout << sc.minSizeSubarray(v, target) << endl;
    return 0;
}