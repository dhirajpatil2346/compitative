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

// end of Sektor_jr template v2.0.3 (BETA)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vl v(n);
        for (auto &val : v)
            cin >> val;
        int pos = 0;
        LL c1 = abs(v[0] - v[1]);
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                LL cc1 = 0, cc2 = 0;
                cc1 = abs(v[i] - v[i - 1]);
                cc2 = abs(v[i] - v[i + 1]);
                if (c1 >= cc1 && c1 >= cc2)
                {
                    pos = i;
                    c1 = max(cc1, cc2);
                }
            }
            else
            {
                LL cc1 = abs(v[i] - v[i - 1]);
                if (c1 >= cc1)
                {
                    pos = i;
                    c1 = cc1;
                }
            }
        }
        vector<int> alice;
        for (int i = 0; i < n; i++)
        {
            LL cc1 = 0, cc2 = 0;
            if ((i - 1) >= 0)
                cc1 = abs(v[i] - v[i - 1]);
            if ((i + 1) < n)
                cc2 = abs(v[i] - v[i + 1]);
            if (max(cc1, cc2) == c1)
                alice.pb(i);
        }
        // for (auto &val : alice)
        //     cout << val << " ";
        // cout << endl;
        LL ans = 0;
        for (auto &val : alice)
        {
            LL cc1 = 0, cc2 = 0;
            int i = val;
            if ((i - 1) >= 0)
                cc1 = abs(v[i] - v[i - 1]);
            if ((i + 1) < n)
                cc2 = abs(v[i] - v[i + 1]);
            ans = max(ans, max(cc1, cc2));
        }
        cout << ans << endl;
    }
    return 0;
}