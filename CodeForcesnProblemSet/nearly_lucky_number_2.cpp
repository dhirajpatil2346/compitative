#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    string s = to_string(n);
    // cout << (s.find("447")) << endl;
    // cout << (s.find("474") >= 0) << endl;
    ;
    if ((s.find("444") >= 0) && (s.find("444") < s.length()))
    {
        // cout << "1" << endl;
        // cout << s.find("444");
        cout << "YES";
        return 0;
    }
    else if ((s.find("447") >= 0) && ((s.find("447")) < s.length()))
    {
        // cout << 2 << endl;
        // cout << (s.find("447"));
        cout << "YES";
        return 0;
    }
    else if ((s.find("474") >= 0) && ((s.find("474")) < s.length()))
    {
        // cout << 31 << endl;
        // cout << s.find("474") << endl;
        cout << "YES";
        return 0;
    }
    else if ((s.find("777") >= 0) && (s.find("777") < s.length()))
    {
        // cout << 4 << endl;
        // cout << s.find("777");
        cout << "YES";
        return 0;
    }
    else if ((s.find("774") >= 0) && (s.find("774") < s.length()))
    {
        // cout << 5 << endl;
        // cout << s.find("774");
        cout << "YES";
        return 0;
    }
    else if ((s.find("747") >= 0) && (s.find("747") < s.length()))
    {
        // cout << 6 << endl;
        // cout << s.find("747") << endl;
        cout << "YES";
        return 0;
    }
    // cout<<s.find("47")<<endl;
    // 444
    // 447
    // 477
    // 474
    // 747
    // 777
    // cout<<found<<endl;
    /*
    for (int i = 0; i < s.length(); i++)
    {
        if((s[i] == '4') || (s[i] == '7')){
            continue;
        }
        else if(s[i]!='7'){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    */
    unordered_set<char> us;
    for (int i = 0; i < s.length(); i++)
    {
        us.insert(s[i]);
    }
    if (us.size() > 1)
    {
        // cout<<"conditions"<<endl;
        unordered_set<char>::iterator iter;
        for (iter = us.begin(); iter != us.end(); iter++)
        {
            // if (((s.find("444")) >= 0) || ((s.find("447")) >= 0) || ((s.find("477")) >= 0) || ((s.find("747")) >= 0) || ((s.find("474")) >= 0) || ((s.find("777")) >= 0))
            // {
            //     cout<<7<<endl;
            //     cout << "YES";
            //     return 0;
            // }
            if ((*iter == '4') || (*iter == '7'))
            {
                // cout << 1 << endl;
                if ((iter != us.end()) && (iter != us.begin()))
                {
                    cout << "YES";
                    return 0;
                }
                continue;
            }
            // else if(s.find("477", s.begin(),s.end()))
            else if ((*iter != '4') || (*iter != '7'))
            {
                // cout << 2 << endl;
                cout << "NO";
                return 0;
            }
            else
            {
                // cout << 3 << endl;
                cout << "YES";
                return 0;
            }
        }
    }

    // else if (*us.begin() == '4')
    // {
    //     cout << "YES";
    // }
    else
    {
        cout << "NO";
    }
    return 0;
}