#include <bits/stdc++.h>
using namespace std;

bool check(string &s)
{
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1' && s[i - 1] == '1')
            return 1;
    }
    return 0;
}

int countStr(int i, string &s)
{
    if (i < 0)
    {
        if (check(s))
            return 1;
        return 0;
    }
    s[i] = '0';
    int ans = countStr(i - 1, s);
    s[i] = '1';
    ans += countStr(i - 1, s);
    s[i] = '0';
    return ans;
}

int main()
{
    int N;
    cin >> N;
    string s(N, '0');
    cout << countStr(N - 1, s) << endl;

    return 0;
}
