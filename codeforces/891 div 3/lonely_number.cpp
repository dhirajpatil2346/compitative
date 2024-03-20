#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

vector<int> primes;
void sieve()
{
    vector<bool> prime(1e6 + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < prime.size(); i++)
        if (prime[i])
            for (int j = 2 * i; j < prime.size(); j += i)
                prime[j] = false;
    for (int i = 2; i < prime.size(); i++)
        if (prime[i])
            primes.push_back(i);
}

int solve()
{
    int n;
    cin >> n;
    for(int i = 1 ; i < primes.size() ; i++)
    {
        for(int j = i + 1 ; j < prime)
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}