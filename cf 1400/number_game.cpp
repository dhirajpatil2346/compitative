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

vi primes;
void sieve()
{
    int n = 4e4 + 1;
    int o = 1e9;
    // cout << (n * n) / o << endl;
    vector<bool> is_prime(n, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (!is_prime[i])
            continue;
        for (int j = 2 * i; j < n; j += i)
        {
            is_prime[j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (is_prime[i])
        {
            primes.pb(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    /*
    for (int i = 0; i < 100; i++)
    {
        cout << primes[i] << " ";
    }
    cout << endl;
    */
    int t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        int moves = 0;
        if (n == 1)
        {
            moves = 0;
        }
        else
        {
            int o = n;
            int z = 0;
            int odds = 0, two = 0;
            map<int, int> m;
            for (int i = 0; i < primes.size() && n >= primes[i]; i++)
            {
                while (n % primes[i] == 0)
                {
                    n /= primes[i];
                    m[primes[i]]++;
                }
            }
            if (n > 1)
            {
                m[n]++;
            }
            if (m[2] != 0)
            {
                m[2] = min(2, m[2]);
                z = m[2];
            }
            for (auto &val : m)
            {
                if (val.first != 2)
                    odds += val.second;
            }
            two = m[2];
            odds = min(2, odds);
            n = o;
            if (two == 0)
            {
                moves = 1;
            }
            else
            {
                if (odds == 2)
                {
                    moves = 1;
                }
                else
                {
                    moves = odds + two;
                }
            }
        }
        if (moves % 2)
        {
            cout << "Ashishgup" << endl;
        }
        else
        {
            cout << "FastestFinger" << endl;
        }
    }
    return 0;
}