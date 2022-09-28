#include <bits/stdc++.h>
using namespace std;

string base(long long p, long long b)
{
    string s = "";
    while (p)
    {
        string a = to_string(p % b);
        s += a;
        p /= b;
    }
    return s;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    long long product = 1;
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
        product *= v[i];
    }
    long long b;
    cin >> b;
    string s = base(product, b);
    long long a = 0;
    long long i = 0;
    while (i < s.length() && s[i] == '0')
    {
        a++;
        i++;
    }
    cout << a << endl;
    return 0;
}