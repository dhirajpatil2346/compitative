#include <iostream>
#include <vector>

#define MOD 998244353
#define MAXN 1000006

using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    vector<long long> dp(MAXN, 0);

    dp[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
    }

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        long long answer = (power(dp[K], N)) % MOD;
        cout << answer << endl;
    }

    return 0;
}
