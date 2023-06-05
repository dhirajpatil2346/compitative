#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        long long sum;
        cin >> s >> sum;
        string s1 = "000";
        s1 += s;
        s = s1;
        long long csum = 0;
        for (auto &val : s)
            csum += val - '0';
        long long op = 0;
        for (long long i = s.length() - 1, carry = 0, u = 1; csum > sum, i >= 0; i--, u *= 10)
        {
            if (csum <= sum)
                break;
            // cout << i << " " << op << " " << csum << " " << sum << endl;
            if (s[i] == '0')
                continue;
            csum -= (s[i] - '0');
            long long diff = 10 - (s[i] - '0');
            op += u * diff;
            int j = i - 1;
            while (j >= 0 && s[j] == '9')
            {
                csum -= 9;
                s[j] = '0';
                j--;
            }
            s[j] += 1;
            csum += 1;
        }
        cout << op << endl;
    }
    return 0;
}