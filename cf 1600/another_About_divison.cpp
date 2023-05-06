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

// #ifdef TESTING
// #define DEBUG fprintf(stderr, "====TESTING====\n")
// #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
// #define debug(...) fprintf(stderr, __VA_ARGS__)
// #else
// #define DEBUG
// #define VALUE(x)
// #define debug(...)
// #endif

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
#define endl "\n"
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

vi prime;

bool isP(LL n)
{
    if (n == 1)
        return false;
    for (LL i = 0; i < prime.size() && prime[i] <= sqrt(n); i++)
    {
        if (n % prime[i] == 0)
            return false;
    }
    return true;
}

// end of Sektor_jr template v2.0.3 (BETA)

void sieve()
{
    LL n = sqrt(1e9) + 10;
    vector<bool> primes(n, true);
    primes[0] = false, primes[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (primes[i] == false)
            continue;
        // cout << i << endl;
        for (int j = 2 * i; j < n; j += i)
        {
            // cout << i << " " << j << endl;
            primes[j] = false;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (primes[i] == true)
        {
            // cout << i << endl;
            prime.pb(i);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    // cout << prime.size() << endl;
    for (int i = 0; i < 10; i++)
    {
        // cout << prime[i] << " ";
    }
    // cout << endl;
    int t;
    cin >> t;
    while (t--)
    {
        LL a, b, k;
        cin >> a >> b >> k;
        LL g = __gcd(a, b);
        LL A = a, B = b;
        if (isP(a) && isP(b))
        {
            if (k == 2)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }
        else if (a == b && k == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        LL minmoves = 0;
        if (g != a)
            minmoves++;
        if (g != b)
            minmoves++;
        // a /= g, b /= g;
        LL maxmoves = 0;
        LL i = 0;
        while (i < prime.size() && prime[i] <= sqrt(a))
        {
            if (a % prime[i])
            {
            }
            else
            {
                while (a % prime[i] == 0)
                {
                    maxmoves++;
                    a /= prime[i];
                }
            }
            i++;
        }
        if (a > 1)
            maxmoves++;
        i = 0;
        a = A, b = B;
        while (i<prime.size()&&prime[i] <= sqrt(b))
        {
            if (b % prime[i])
            {
            }
            else
            {
                while (b % prime[i] == 0)
                {
                    maxmoves++;
                    b /= prime[i];
                }
            }
            i++;
        }
        if (b > 1)
            maxmoves++;
        // cout << minmoves << " " << maxmoves << endl;
        if (k < minmoves || k > maxmoves)
            cout << "NO" << endl;
        else if (k >= minmoves && k <= maxmoves)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}