#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

class Solution
{
public:
    int minOperations(string a, string b, int x)
    {
        vector<int> one_but_want_zero, zero_but_want_one;
        int n = a.length();
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                if (a[i] == '0')
                    zero_but_want_one.push_back(i);
                else
                    one_but_want_zero.push_back(i);
        int u = zero_but_want_one.size() + one_but_want_zero.size();
        if (u & 1)
            return -1;
        int ret = 0;
        // i will swap as much i can
        vector<int> v;
        for (auto &val : zero_but_want_one)
            v.push_back(val);
        for (auto &val : one_but_want_zero)
            v.push_back(val);
        if (x == 1)
        {
            int a1 = one_but_want_zero.size();
            a1 += zero_but_want_one.size();
            a1 /= 2;
            return a1;
        }
        vector<int> f;
        for (int i = 0; i < v.size(); i++)
        {
            if (i == v.size() - 1)
            {
                f.push_back(v[i]);
                continue;
            }
            int diff = v[i + 1] - v[i];
            if (diff != 1)
            {
                f.push_back(v[i]);
            }
            else
            {
                ret++;
                i++;
            }
        }
        for (int i = 0; i < f.size() - 1; i += 2)
        {
            int diff = f[i + 1] - f[i];
            ret += min(diff, x);
        }
        return ret;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution sc;
    string a, b;
    cin >> a >> b;
    int x;
    cin >> x;
    cout << sc.minOperations(a, b, x) << endl;
    return 0;
}
/*
11001011111
01111000110
2


*/
/*

"1100011000"
"0101001010"
2

*/