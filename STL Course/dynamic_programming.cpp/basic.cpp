#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
int dp[N];

// 0 1 1 2 3 5 8 13

int fib(int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    
    cout << fib(n) << endl;
    return 0;
}