#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, vector<long long>> m;
    long long n, x1, y1, x2, y2;
    string s;
    cin >> n >> x1 >> y1 >> x2 >> y2 >> s;
    char c1, c2;
    long long r1 = abs(x1 - x2), r2 = abs(y1 - y2);
    if (x2 > x1)
    {
        c1 = 'E';
    }
    else if (x2 < x1)
    {
        c1 = 'W';
    }
    else
    {
        c1 = ' ';
    }
    if (y2 > y1)
    {
        c2 = 'N';
    }
    else if (y2 < y1)
    {
        c2 = 'S';
    }
    else
    {
        c2 = ' ';
    }
    if (c1 == ' ' && c2 == ' ')
    {
        cout << 0 << endl;
        return 0;
    }
    vector<long long> c11, c22;
    for (long long i = 0; i < n; i++)
    {
        if (s[i] == c1)
        {
            c11.push_back(i);
        }
        else if (s[i] == c2)
        {
            c22.push_back(i);
        }
    }
    m[c1] = c11;
    m[c2] = c22;
    // cout << c1 << "  " << c2 << endl;
    // cout << m[c1].size() << "   " << m[c2].size() << endl;
    // cout << r1 << " " << r2 << endl;
    if (c11.size() < r1 || c22.size() < r2)
    {
        cout << -1 << endl;
        return 0;
    }

    long long num1, num2;
    if (r1 != 0)
    {
        num1 = m[c1][r1 - 1];
    }
    if (r2 != 0)
    {
        num2 = m[c2][r2 - 1];
    }
    if(r1 == 0)
    {
        cout<<num2+1;
    }
    else if(r2==0){
        cout<<num1+1;
    }
    else{
    cout << max(num1 + 1, num2 + 1);
    }
    return 0;
}