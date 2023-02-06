/*
2 180
2 90
2 45
3 15
3 5
5 1
*/
#include <bits/stdc++.h> // Include every standard library
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#ifdef TESTING
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

inline string IntToString(LL a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}

inline LL StringToInt(string a)
{
    char x[100];
    LL res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}

inline string GetString(void)
{
    char x[1000005];
    scanf("%s", x);
    string s = x;
    return s;
}

inline string uppercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'a' && s[i] <= 'z')
        s[i] = s[i] - 'a' + 'A';
    return s;
}

inline string lowercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    return s;
}

inline void OPEN(string s)
{
#ifndef TESTING
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
#endif
}

vl primes;

void sieve()
{
    vector<bool> is_prime(1e5 + 2, true);
    for (int i = 2; i <= 1e5 + 1; i++)
    {
        if (is_prime[i] == false)
            continue;
        if (is_prime[i])
        {
            for (int j = 2 * i; j <= 1e5 + 1; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < is_prime.size(); i++)
    {
        if (is_prime[i])
        {
            primes.pb(i);
        }
    }
}

bool prime(LL n)
{
    LL sq = sqrt(n);
    for (int i = 0; i < primes.size() && primes[i] <= sq; i++)
    {
        if (n % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

// end of Sektor_jr template v2.0.3 (BETA)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << primes[i] << " ";
    // }
    // cout << endl;
    int t;
    cin >> t;
    while (t--)
    {
        if (prime(4))
        {
            // cout << "YES" << endl;
        }
        long long n;
        cin >> n;
        vl factors;
        LL i = 2;
        if (prime(n))
        {
            factors.pb(n);
        }
        else
        {
            for (int i = 0; i < primes.size(); i++)
            {
                if (n == 1 || primes[i] > n)
                {
                    break;
                }
                if (n % primes[i] != 0)
                {
                    continue;
                }
                while (n % primes[i] == 0)
                {
                    factors.pb(primes[i]);
                    n /= primes[i];
                }
            }
            if(n!=1)
            {
                factors.pb(n);
            }
        }
        // cout << factors.size() << endl;
        int freq = 0;
        sort(factors.begin(), factors.end());
        /*
        for (auto &val : factors)
        {
            cout << val << " ";
        }
        cout << endl;
        */
        map<LL, int> m;
        for (auto &val : factors)
        {
            m[val]++;
        }
        LL maxf = m.begin()->first;
        for (auto &val : m)
        {
            if (val.second >= m[maxf])
            {
                maxf = val.first;
            }
        }
        LL f = maxf;
        for (auto &val : factors)
        {
            if (val != maxf)
                f *= val;
        }
        if (m.size() > 1)
        {
            cout << m[maxf] << endl;
            for (int i = 0; i < m[maxf] - 1; i++)
            {
                cout << maxf << " ";
            }
            cout << f << endl;
        }
        else
        {
            cout << m.begin()->second << endl;
            for (auto &val : factors)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}