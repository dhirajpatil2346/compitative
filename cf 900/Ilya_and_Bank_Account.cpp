#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stringstream obj;
    int intdata;
    obj << s;
    obj >> intdata;
    if (intdata >= 0)
    {
        cout << s;
        // return 0;
    }
    else
    {
        string m,n;
        m=s;
        n=s;
        m.erase(m.end() - 2);
        stringstream obj2;
        int intdata2;
        obj2 << m;
        obj2 >> intdata2;
        // cout<<intdata2<<endl;
        n.erase(n.length() - 1);
        stringstream obj3;
        int intdata3;
        obj3 << n;
        obj3 >> intdata3;
        // cout<<intdata3<<endl;
        if (intdata2 >= intdata3)
        {
            cout << intdata2;
        }
        else
        {
            cout << intdata3;
        }
    }
}