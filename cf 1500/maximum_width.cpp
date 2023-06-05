#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> start(n, -1), end(n, -1);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (s1[i] == s2[j])
        {
            start[j] = i;
            j++;
        }
    }
    for (int i = n - 1, j = k - 1; i >= 0; i--)
    {
        if (s1[i] == s2[j])
        {
            end[j] = i;
            j--;
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, end[i] - start[i - 1]);
    cout << ans << endl;

    return 0;
}