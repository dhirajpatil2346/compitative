#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n, d;
        cin >> d >> n;
        cin >> s;
        string k = "";
        for (int i = 0; i < n; i++)
        {
            k += s;
        }
        s = k;
        // cout << s << endl;
        int a = 0;
        int pre=0,suff=0;
        vector<int> prefix(s.length()),suffix(s.length());
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='1'){pre++;}
            prefix[i]=pre;
        }
        for(int i = s.length()-1 ; i >= 0 ;i--)
        {
            suffix[i]=suff;
            if(s[i]=='1'){suff++;}
        }
        // int a=0;
        for (int i = 0; i < s.length(); i++)
        {
            if(prefix[i]==suffix[i]){a++;}
        }
        cout<<a<<endl;
    }
    return 0;
}