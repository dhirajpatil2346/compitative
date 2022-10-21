#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "=" << endl;
        }
        else if (a == "M")
        {
            if (b[b.length() - 1] == 'L')
            {
                cout << "<"<<endl;
            }
            else
            {
                cout << "<" << endl;
            }
        }
        else if (b == "M")
        {
            if (a[a.length() - 1] == 'L')
            {
                cout << ">"<<endl;
            }
            else
            {
                cout << "<" << endl;
            }
        }
        else
        {
            if (a[a.length() - 1] == b[b.length() - 1])
            {
                if (a[a.length() - 1] == 'S')
                {
                    if (a.length() > b.length())
                    {
                        cout << "<" << endl;
                    }
                    else
                    {
                        cout << ">" << endl;
                    }
                }
                else
                {
                    if (a.length() > b.length())
                    {
                        cout << ">" << endl;
                    }
                    else
                    {
                        cout << "<" << endl;
                    }
                }
            }
            else if (a[a.length() - 1] == 'L')
            {
                cout << ">" << endl;
            }
            else
            {
                cout << "<" << endl;
            }
        }
    }
    return 0;
}