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

// end of Sektor_jr template v2.0.3 (BETA)
const int n = 1e6 + 1000;
vector<bool> prime(n, true);
vi primes;
const LL mod = 998244353;
void sieve()
{
    prime[0] = false, prime[1] = false;
    for (int i = 2; i < prime.size(); i++)
    {
        if (!prime[i])
            continue;
        for (int j = 2 * i; j < prime.size(); j += i)
        {
            prime[j] = false;
        }
    }
    for (int i = 0; i < prime.size(); i++)
    {
        if (prime[i])
            primes.pb(i);
    }
}

long long dfs(int lastind, int curr, int r, vi &depth)
{
    if (curr > r)
    {
        return 0;
    }
    if (depth[curr] != -1)
        return depth[curr];
    LL a = 0;
    if (curr * primes[lastind] <= r)
        a = max(a, 1 + dfs(lastind, curr * primes[lastind], r, depth));
    if (curr * primes[lastind + 1] <= r)
        a = max(a, 1 + dfs(lastind, curr * primes[lastind + 1], r, depth));
    return depth[curr] = a % mod;
}

long long ans(int fix, int lastind, int curr, int r, vvl &dp, int c, int tar)
{
    // cout << c << " " << curr << endl;
    if (curr > r)
    {
        return 0;
    }
    if (c == tar)
        return 1;
    if (dp[fix][c] != -1)
        return dp[fix][c];
    LL a = 0;
    if (curr * primes[lastind] <= r)
        a += ans(fix, lastind, curr * primes[lastind], r, dp, c + 1, tar);
    a %= mod;
    if (curr * primes[lastind + 1] <= r)
        a += ans(fix, lastind, curr * primes[lastind + 1], r, dp, c + 1, tar);
    a %= mod;
    return dp[fix][c] = a % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        vi depth(r + 10, -1);
        int dep = 1 + dfs(0, l, r, depth);
        // cout << dep << endl;
        vvl dp(r + 10, vl(dep + 10, -1));
        long long a = 0;
        int i = 0;
        while (true)
        {
            if (l + i > r)
            {
                break;
            }
            // cout << l + i << endl;
            a += ans(l + i, 0, l + i, r, dp, 0, dep - 1);
            a %= mod;
            i++;
        }
        cout << dep << " " << a << endl;
    }
    return 0;
}