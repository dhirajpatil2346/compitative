/*
1 - 1
2 - (1,2),(2,2) - 4
3 - (1,3)+(2,3)+(3,3) - 12
4 - 4+4+12+4=24
5 - 5 + 5 + 10 + 15+ 20 = 45
6 -  6 6 6 6  12 30 -- 66

(n*n*(1+n)) / 2 - (n*(n-1))
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> lc(21);
    for (int i = 1; i < 21; i++)
    {
        int k = 0;
        for (int j = 1; j <= i; j++)
        {
            k += lcm(i, j);
        }
        lc[i] = k;
    }

    for (int i = 1; i <= 20; i++)
    {
        int n = i;
        cout << n << " --> " << (n * n * (1 + n)) / 2 - (n * (n - 1)) << " " << lc[i] << endl;
        ;
    }

    return 0;
}