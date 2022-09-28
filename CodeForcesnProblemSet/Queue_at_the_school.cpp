#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if ((s[j] == 'B') && (s[j+1] != 'B'))
            {
                char temp;
                temp = s[j + 1];
                s[j + 1] = s[j];
                s[j] = temp;
                j++;
            }
        }
    }
    cout << s;

    return 0;
}