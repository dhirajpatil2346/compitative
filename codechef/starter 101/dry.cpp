#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const long long mod = 1e9 + 7;
int gcd(int A, int B)
{

    if (B == 0)
    {

        return A;
    }

    return gcd(B, A % B);
}

long check(int B, int C, long long mid, long long lcm)
{

    long mid_by_B = mid / B;

    long mid_by_C = mid / C;

    long mid_by_lcm = mid / lcm;

    long ans = mid_by_B + mid_by_C - mid_by_lcm;

    return ans;
}

int solve(int A, int B, int C)
{
    // long long A = A1, B = B1, C = C1;
    long long s = 1;
    long long e = max(B, C) * 1ll * A;
    long long lcm = ((long long)(B * 1ll * C )) / gcd(B, C);
    long long ans = 0;
    while (s <= e)
    {
        long long mid = s + (e - s) / 2;
        long pos = check(B, C, mid, lcm);
        if (pos >= A)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    // ans
    // ans = ans % 1e9 + 7
    // ans = 117 + 7
    // ans = 124
    ans = ans % (mod);
    return (int)ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a = 807414236, b = 3788, c = 38141;
    cout << solve(a, b, c) << endl;
    return 0;
}