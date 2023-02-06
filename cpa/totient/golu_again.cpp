#include <bits/stdc++.h> // Include every standard library
using namespace std;

vector<int> primes;
void sieve()
{
    vector<bool> v(4 * 1e4 + 1, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i * i <= 4 * 1e4; i++)
    {
        if (!v[i])
        {
            continue;
        }
        for (int j = i * i; j <= 4 * 1e4; j += i)
        {
            v[j] = false;
        }
    }
    for (int i = 0; i < 4 * 1e4 + 1; i++)
    {
        if (v[i])
        {
            primes.push_back(i);
        }
    }
}

bool prime(long long n)
{
    if (n == 1)
    {
        return false;
    }
    long long sq = sqrt(n);
    for (int i = 0; i < primes.size() &&  primes[i] <= sq; i++)
    {
        if (n % primes[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int totient(long long n)
{
    long long ans = n;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            ans -= ans / i;
        }
    }
    if (n > 1)
    {
        ans -= ans / n;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    // cout << primes.size() << endl;
    for (int i = 0; i < 10; i++)
    {
        // cout << primes[i] << " ";
    }
    // cout << endl;

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> phi(n);
    for (int i = 0; i < n; i++)
    {
        phi[i] = totient(v[i]);
        // // cout << v[i] << "--" << totient(v[i]) << endl;
    }

    for (auto &val : phi)
    {
        // cout << val << " ";
    }
    // cout << endl;

    vector<int> zo(n);
    for (int i = 0; i < n; i++)
    {
        if (prime(phi[i]))
        {
            zo[i] = 1;
        }
    }

    for (auto &val : zo)
    {
        // cout << val << " ";
    }
    // cout << endl;

    for (int i = 1; i < n; i++)
    {
        zo[i] += zo[i - 1];
    }
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            cout << zo[y - 1] << endl;
        }
        else
        {
            cout << zo[y - 1] - zo[x - 2] << endl;
        }
    }
    return 0;
}