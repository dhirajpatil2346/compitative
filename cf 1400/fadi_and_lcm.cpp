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
const int N = 1e6 + 5;
vi primes;
void sieve()
{
    vector<bool> is_prime(N, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (!is_prime[i])
            continue;
        for (int j = 2 * i; j < N; j += i)
        {
            // cout << i << endl;
            is_prime[j] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (is_prime[i])
        {
            // cout << i << endl;
            primes.pb(i);
        }
    }
}

LL dp[N][2];
LL Ans(int last, int ind, vl &v, LL total, LL curr)
{
    if (ind == v.size())
    {
        return max(curr, total / curr);
    }
    if (dp[ind][last] != -1)
        return dp[ind][last];
    LL ans = max(curr, total / curr);
     ans = min(ans, Ans(0, ind + 1, v, total, curr));
    ans = min(ans, Ans(1, ind + 1, v, total, v[ind] * curr));
    // return dp[ind][last] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    memset(dp, -1, sizeof(dp));
    LL n;
    cin >> n;
    int sq = sqrt(n);
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << primes[i] << " ";
    // }
    // cout << endl;
    map<LL, int> m;
    for (LL i = 0; i < primes.size() && primes[i] <= sq && primes[i] <= n; i++)
    {
        LL c = 1;
        if (n % primes[i])
            continue;
        else
        {
            while ((n % primes[i]) == 0)
            {
                c *= primes[i];
                n /= primes[i];
            }
        }
        m[c]++;
        // cout << n << " " << primes[i + 1] << endl;
    }
    if (n > 1)
    {
        m[n]++;
    }
    vl v;
    for (auto &val : m)
    {
        LL z = 1;
        for (int i = 0; i < val.second; i++)
        {
            z *= val.first;
        }
        v.pb(z);
    }
    LL M = 1;
    for (auto &val : v)
    {
        M *= val;
        // cout << val << " ";
    }
    // cout << endl;
    LL z = 1;
    z = max(z, Ans(0, 0, v, M, 1));
    cout << z << " " << M / z << endl;
    return 0;
}