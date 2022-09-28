#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countSubstringsUtil(string s)
{
    int count = 0;

    map<char, int> mp;

    int n = s.length();
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;

        while (mp['a'] > 0 && mp['e'] > 0 && mp['i'] > 0 && mp['o'] > 0 && mp['u'] > 0)
        {
            count += n - i;
            mp[s[start]]--;
            start++;
        }
    }

    return count;
}

int countSubstrings(string s)
{
    int count = 0;
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {

        if (isVowel(s[i]))
        {
            temp += s[i];
        }
        else
        {

            if (temp.length() > 0)
                count += countSubstringsUtil(temp);

            temp = "";
        }
    }
    if (temp.length() > 0)
        count += countSubstringsUtil(temp);

    return count;
}

int main()
{
    string s;
    cin >> s;

    cout << countSubstrings(s) << endl;

    return 0;
}
