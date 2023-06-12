/*
1 1 1
3

*/
/*
1 1 1 1
alice 1 3 | 2 2
bob won | 4
alice lose  | won

1 1 1 1 1
alice 3 1 1
bob 3 2

1 1 1 1
1 1 2 alice
2 2 bob
alice 4
bob won

1  1 1 1 1
1 1 3
bob 2 3
alice won

3c + a + b = n
A = a + c
B = b + c

a b c are primes or 1

*/
/*
A + B + c = n
A = ac , B = bc , c = c,n = n
(a+b)c+c = n
c(1+a+b) = n
1 + a + b = n / c
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    // (n / c) >= 3
    if (n & 1)
    {
        int c = 1;
        n--;
        for (int i = 1;; i++)
        {
            int a = i, b = n - i;
            if (__gcd(a, b) == 1 && (a != b && b != c && a != c))
            {
                cout << a << " " << b << " " << 1 << endl;
                return;
            }
        }
    }
    else
    {
        cout << n / 2 << " " << n / 2 - 1 << " " << 1 << endl;
    }
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
        solve();
    }
    return 0;
}
/*
10
1 5 4

11
1 3 7

1 12
1 5 7
*/
/*
2 4 5 
*/