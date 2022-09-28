#include <bits/stdc++.h>
using namespace std;
int log(int n)
{
    int c = 1;
    while (n /= 2)
    {
        c++;
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    cout << log(n) << endl;
    return 0;
}