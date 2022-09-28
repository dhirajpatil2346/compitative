#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> level(s.length());
    level[0] = 1;
    vector<int> v[n + 1];
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            level[i] = level[i - 1] + 1;
            if (level[i] < level[i - 1])
            {
                
            }
        }
        else
        {
            level[i] = level[i - 1] - 1;
        }
    }

    return 0;
}