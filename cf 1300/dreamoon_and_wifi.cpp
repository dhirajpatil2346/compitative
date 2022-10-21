#include <bits/stdc++.h>
using namespace std;
#define ll long long

int final = 0;
int l = 0;
void pos(const string &s, int sc, int cp, const int &fp)
{
    if (cp == s.length())
    {
        if (sc == fp)
        {
            final++;
            l++;
        }
        else
        {
            l++;
        }
        return;
    }
    if (s[cp] == '+')
    {
        pos(s, sc + 1, cp + 1, fp);
    }
    else if (s[cp] == '-')
    {
        pos(s, sc - 1, cp + 1, fp);
    }
    else
    {
        pos(s, sc + 1, cp + 1, fp);
        pos(s, sc - 1, cp + 1, fp);
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int fp = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == '+')
        {
            fp++;
        }
        else
        {
            fp--;
        }
    }
    pos(s2,0,0,fp);
    // cout << final << " " << l << endl;
    cout<<fixed<<setprecision(12)<<(double(final) / double(l))<<endl;
    return 0;
}