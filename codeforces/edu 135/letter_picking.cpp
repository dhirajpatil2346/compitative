#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string f = "", l = "";
    int cnt=0;
    int front = 0, back = s.length() - 1;
    for (int i = front; i <= back; i++)
    {
        if(cnt%2==0)
        {
            // turn of f
            if(s[front]<=s[back])
            {
                string j = s[front];
                
            }
        }
        else
        {
            // turn of l
        }
        cnt++;
    }

    return 0;
}