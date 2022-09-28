#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int l1 = a.length(), l2 = b.length();
    vector<char> v1(l1), v2(l2);
    if (l1 != l2)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < l1; i++)
    {
        v1[i] = a[i];
    }
    for (int i = 0; i < l2; i++)
    {
        v2[i] = b[i];
    }
    if (l1 == 2)
    {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if (v1[0] != v2[0])
        {
            cout << "NO" << endl;
            return 0;
        }
        if (v1[1] != v2[1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (l1 == 1)
    {
        if (v1[0] != v2[0])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    int count = 0;
    for (int i = 0; i < l1; i++)
    {
        if (v1[i] != v2[i])
        {
            count++;
        }
    }
    if (count > 2)
    {
        cout << "NO";
        return 0;
    }
    /*
    else
    {
        cout << "YES";
    }
    */
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < l1; i++)
    {
        if (v1[i] != v2[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}