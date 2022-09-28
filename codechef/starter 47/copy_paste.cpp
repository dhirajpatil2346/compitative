#include <bits/stdc++.h>
using namespace std;
string a1(string s, string init, int k)
{
    s += init[k];
    return s;
}
string a2(string s)
{
    s += s;
    return s;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string k = "";
        k += s[0];
        bool exceed = false, got = false;
        if(k==s){
            got=true;
        }
        for (int i = 1; i < n; i++)
        {
            // //cout<<i<<"  "<<k<<endl;
            if (k == s)
            {
                // cout<<"c12";
                got = true;
                break;
            }
            if (k.length() >= s.length())
            {
                // cout<<"c12";
                exceed = true;
                break;
            }
            if (i % 2)
            {
                k += k;
            }
            else
            {
                if (k == s)
                {
                    got = true;
                    break;
                }
                if (k.length() >= s.length())
                {
                    exceed = true;
                    break;
                }
                k += s[k.length()];
            }
            if (k == s)
            {
                // cout<<"c21";
                got = true;
                break;
            }
            if (k.length() >= s.length())
            {
                // cout<<"c22";
                exceed = true;
                break;
            }
        }
        if (got)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}