#include <bits/stdc++.h>
using namespace std;
vector<string> dictwords(string textInput)
{
    string s = textInput;
    vector<string> w;
    int i = 0, n = s.length();
    while (i < n)
    {
        string h = "";
        while (i < n)
        {
            if (s[i] == ' ')
            {
                i++;
                break;
            }
            else
                h.push_back(s[i++]);
        }
        w.push_back(h);
    }
    map<string, int> m;
    for (auto &val : w)
        m[val]++;
    vector<string> answer;
    for (auto &val : m)
        if (val.second > 1)
            answer.push_back(val.first);
    return answer;
}
int main()
{
    string s;
    getline(cin >> ws, s);
    vector<string> v = dictwords(s);
    for (auto &val : v)
        cout << val << " ";
    return 0;
}