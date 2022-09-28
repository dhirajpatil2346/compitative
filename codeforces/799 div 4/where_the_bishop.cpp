#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> s(8);
        for (auto &val : s)
        {
            cin >> val;
        }
        vector<int> v(8);
        for (int i = 0; i < 8; i++)
        {
            int curr = 0;
            string k = s[i];
            for (int j = 0; j < 8; j++)
            {
                if (k[j] == '#')
                {
                    curr++;
                }
            }
            v[i] = curr;
        }
        int final = 1;
        for (int i = 1; i < 7; i++)
        {
            if (v[i - 1] == 2 && v[i] == 1 && v[i + 1])
            {
                final = i;
                break;
            }
        }
        string z = s[final];
        int g = 0;
        for (int i = 0; i < 8; i++)
        {
            if(z[i]=='#')
            {
                g=i;
            }
        }
        cout<<final+1<<" "<<g+1<<endl;
    }
    return 0;
}