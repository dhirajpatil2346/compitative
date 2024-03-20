#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.length();
    vector<int> zeros(s.length());
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0')
            zeros[i] = 1;
    for (int i = 1; i < zeros.size(); i++)
        zeros[i] += zeros[i - 1];
    int mx = 1;
    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(zeros.begin(), zeros.end(), zeros[i] - k) - zeros.begin();
        if (zeros[i] <= k)
            mx = max(mx, i - pos + 1);
        else
            mx = max(mx, i - pos); 
    }
    int x = 0;
    for (int i = mx - 1; i < n; i++)
    {
        int r = 0, f = 0;
        r = zeros[i];
        if ((i - mx) >= 0)
            f = zeros[i - mx];
        if ((r - f) <= k)
            x++;
    }
    cout << x << endl;

    return 0;
}