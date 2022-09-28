#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, k;
    cin >> s >> k;
    int y = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == k[i]) || (s[i] == k[i] - 32) || (s[i] == k[i] + 32))
        {
            continue;
        }
        else if ((s[i] != k[i] - 32) && (s[i] != k[i] + 32))
        {
            if ((s[i] < 97 && k[i] < 97) || (s[i] > 96 && k[i] > 96))
            {
            // cout<<"loop 2"<<endl;
                if (s[i] > k[i])
                {
                    y = 1;
                    cout << y;
                    return 0;
                }
                else
                {
                    y = -1;
                    cout << y;
                    return 0;
                }
            }
            else
            {
                // cout<<"loop 3"<<endl;
                if (s[i] < 97 && k[i] > 96)
                {
                    k[i] = k[i] - 32;
                    if (s[i] > k[i])
                    {
                        y = 1;
                        cout << y;
                        return 0;
                    }
                    else
                    {
                        y = -1;
                        cout << y;
                        return 0;
                    }
                }
                else
                {
                    s[i] = s[i] - 32;
                    if (s[i] > k[i])
                    {
                        y = 1;
                        cout << y;
                        return 0;
                    }
                    else
                    {
                        y = -1;
                        cout << y;
                        return 0;
                    }
                }
            }
        }
    }
    cout << y;
    return 0;
}