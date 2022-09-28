#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    while (!s.empty())
    {
        if (s.find("WUB") == 0)
        {
            s.erase(0, 3);
        }
        else
        {
            int y = s.find("WUB");
            if(y!=-1){
            for (int i = 0; i < s.find("WUB"); i++)
            {
                cout << s[i];
            }
            s.erase(0, s.find("WUB"));
            cout << " ";
            }
            else{
                for (int i = 0; i < s.length(); i++)
            {
                cout << s[i];
            }
            s.erase(0, s.length());
            cout << " ";
            }
        }
    }

    return 0;
}