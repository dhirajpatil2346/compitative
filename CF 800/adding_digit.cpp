#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
string solve()
{
    string a;
    int b, n;
    cin >> a >> b >> n;
    vector<int> v(a.length() + n, 9);
    for (int i = 0; i < a.length(); i++)
        v[i] = a[i] - '0';
    int cry = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cry *= 10;
        cry += v[i];
        cry %= b;
        if (cry > 9)
        {
            return "-1";
        }
        v[i] -= cry;
        int c = 0;
        if (v[i] < 0)
        {
            v[i] += 10;
            v[i] %= 10;
            c++;
        }
        int j = i - 1;
        while (true)
        {
            if (j < 0)
                return "-1";
            if (c == 0)
                break;
            v[j] -= c;
            if (v[j] < 0)
            {
                v[j] += 10;
                v[j] %= 10;
                c++;
            }
            j--;
        }
    }
    string ans = "";
    for (int i = 0; i < v.size(); i++)
    {
        ans.push_back('0' + v[i]);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << endl;
    return 0;
}