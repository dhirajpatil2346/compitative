#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        //cout<<s<<s.length()<<endl;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            //cout<<s.length()<<endl;
            if (i < (s.length() - 3) && s[i + 3] == '0' && s[i + 2] == '0')
            {
                 //cout<<"1st"<<endl;
                int f = s[i] - '0';
                // //cout<<f<<endl;
                int j = f + 'a' - 1;
                j+=0;
                //cout<<j<<endl;
                ans += char(j);
            }
            else if((i==s.length()-2) || (i==s.length()-1))
            {
                //cout<<"third"<<endl;
                int f = s[i] - '0';
                //cout<<"   "<<f<<endl;
                int j = f + 'a' - 1;
                j+=0;
                //cout<<j<<endl;
                ans += char(j);
            }
            else  
            {
                 //cout<<"2nd"<<endl;
                 //cout<<i<<" "<<s.length()-2<<endl;
                int f = s[i] - '0';
                int sc = s[i + 1] - '0';
                int final = f * 10 + sc;
                // //cout<<final<<endl;
                //  ////cout<<final<<endl;
                int j = final + 'a' - 1;
                //cout<<j<<endl;
                j+=0;
                ans += char(j);
                i += 2;
            }
            
        }
        cout << ans << endl;
    }
    return 0;
}

/*
n = ch - a+1;
ch = n+ a - 1;
ch = a + (n-1);

p = ch - a + 1
ch = p + a - 1

*/