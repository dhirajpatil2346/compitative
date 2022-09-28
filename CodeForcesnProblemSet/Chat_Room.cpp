#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int j;
    int f, g, h, b, v;
    if (s.length() > 5 || s=="hello")
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'h')
            {
                j = i;
                f=i;
                for (; j < s.length() - 1; j++)
                {
                    s[j] = s[j + 1];
                }
                // cout<<f<<endl;
                break;
            }
            else if ((i == s.length() - 1))
            {
                cout << "NO";
                return 0;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] == 'e'))
            {
                j = i;
                g=i+1;
                if(g>f){
                for (; j < s.length() - 1; j++)
                {
                    s[j] = s[j + 1];
                }
                // cout<<g+<<endl;
                break;
                }
            }
            else if ((i == s.length() - 1))
            {
                cout << "NO";
                return 0;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'l')
            {
                j = i;
                h=i+2;
                if(h>g){
                for (; j < s.length() - 1; j++)
                {
                    s[j] = s[j + 1];
                }
                // cout<<h+2<<endl;
                break;
                }
            }
            else if ((i == s.length() - 1))
            {
                cout << "NO";
                return 0;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'l')
            {
                j = i;
                b=i+3;
                if(b>h){
                for (; j < s.length() - 1; j++)
                {
                    s[j] = s[j + 1];
                }
                // cout<<b+3<<endl;
                break;
                }
            }
            else if ((i == s.length() - 1))
            {
                cout << "NO";
                return 0;
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'o')
            {
                j = i;
                v=i+4;
                if(v>b){
                for (; j < s.length() - 1; j++)
                {
                    s[j] = s[j + 1];
                }
                cout << "YES";
                // cout<<v+4<<endl;
                break;
                }
            }
            else if ((i == s.length() - 1))
            {
                cout << "NO";
            }
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}