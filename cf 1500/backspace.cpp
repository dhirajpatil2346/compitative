#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    string a, b;
    cin >> a >> b;
    int len1 = a.length(), len2 = b.length();
    if (len1 == len2)
        return a == b;
    if (len2 > len1)
        return false;
    vector<int> pos;
    for (int i = 0; (i < len1) && (pos.size() < 2); i++)
        if (a[i] == b[0])
            pos.push_back(i);
    for (int _ = 0; _ < pos.size(); _++)
    {
        int i = pos[_] + 1;
        int j = 1;
        for (; j < len2 && i < len1;)
        {
            int c = 0;
            for (; i < len1; i++)
            {
                c++;
                if (a[i] == b[j])
                {
                    // we have got a and b same for particular index
                    // check if c is not equal to 2
                    if (c != 2)
                    {
                        i++;
                        j++;
                        break;
                    }
                }
            }
        }
        // cout << i << " " << j << endl;
        if (j == len2)
        {
            int rem = len1 - i;
            if (rem != 1)
                return true;
        }
    }
    return false;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}