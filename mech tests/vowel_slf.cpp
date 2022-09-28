#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int maxi = 0;
    vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int currc = 0;
    for (int i = 0; i < s.length(); i++)
    {
        bool got = false;
        for (int j = 0; j < 10; j++)
        {
            if (s[i] == v[j])
            {
                got = true;
                break;
            }
        }
        if (got)
        {
            currc++;
            maxi = max(currc, maxi);
        }
        else
        {
            maxi = max(currc, maxi);
            currc = 0;
        }
    }
    cout << maxi << endl;
    return 0;
}