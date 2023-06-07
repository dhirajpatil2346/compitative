#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 1000; i++)
    {
        if (n == m)
            return true;
        if (n >= m)
        {
            n--, m++;
        }
        else
        {
            n += 3, m--;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
/*
3 3
1 5
=> 4 4
2 3
=> 3 2
=>4 1
=>


*/
/*
ans = 1
every even pairs => 
2^e - 1 

2^1 
*/