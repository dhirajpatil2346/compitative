#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL a, b, c;
        cin >> a >> b >> c;
        cout << ((abs(a + c - 2 * b) % 3) != 0) << endl;
    }
    return 0;
}
/*
113
*/
/*
4 2
2 3
a+c  2b
2    14
3    12
4    10
5    8
6    6
2 5
3 3
check if a+c <= 2b

not a+c > 2b
7 16
8 14
9 12
10 10
if(diff % 3 == 0) or not


*/