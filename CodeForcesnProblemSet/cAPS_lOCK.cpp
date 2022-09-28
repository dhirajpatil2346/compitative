#include <bits/stdc++.h>
// #include<string>
using namespace std;
string *k;
void cAPS(string s)
{
    pair<char, char> pairs[26];
    pairs[0] = {'a', 'A'};
    pairs[1] = {'b', 'B'};
    pairs[2] = {'c', 'C'};
    pairs[3] = {'d', 'D'};
    pairs[4] = {'e', 'E'};
    pairs[5] = {'f', 'F'};
    pairs[6] = {'g', 'G'};
    pairs[7] = {'h', 'H'};
    pairs[8] = {'i', 'I'};
    pairs[9] = {'j', 'J'};
    pairs[10] = {'k', 'K'};
    pairs[11] = {'l', 'L'};
    pairs[12] = {'m', 'M'};
    pairs[13] = {'n', 'N'};
    pairs[14] = {'o', 'O'};
    pairs[15] = {'p', 'P'};
    pairs[16] = {'q', 'Q'};
    pairs[17] = {'r', 'R'};
    pairs[18] = {'s', 'S'};
    pairs[19] = {'t', 'T'};
    pairs[20] = {'u', 'U'};
    pairs[21] = {'v', 'V'};
    pairs[22] = {'w', 'W'};
    pairs[23] = {'x', 'X'};
    pairs[24] = {'y', 'Y'};
    pairs[25] = {'z', 'Z'};
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < sizeof(pairs) / 2; j++)
        {
            if (s[i] == pairs[j].first)
            {
                s[i] = pairs[j].second;
            }
            else if (s[i] == pairs[j].second)
            {
                s[i] = pairs[j].first;
            }
            else
            {
            }
        }
    }
    cout << s;
}
int main()
{
    string m;
    cin >> m;
    // cout<<m.length();
    unordered_set<char> sl;
    sl = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    if(m.length() == 1){
        cAPS(m);
        return 0;
    }
    for (int i = 0; i < m.length(); i++)
    {
        if (!(sl.find(m[i]) != sl.end()))
        {
            if (i == (m.length() - 1))
            {
                cAPS(m);
                return 0;
            }
        }
        else
        {
            break;
        }
    }
    if (sl.find(m[0]) != sl.end())
    {
        for (int i = 1; i < m.length(); i++)
        {
            if (!(sl.find(m[i]) != sl.end()))
            {
                if (i == (m.length() - 1))
                {
                    cAPS(m);
                    return 0;
                };
            }
            else
            {
                break;
            }
        }
    }

    cout << m;
    return 0;
}