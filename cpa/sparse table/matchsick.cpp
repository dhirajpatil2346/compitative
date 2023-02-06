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
    // partitions will be like 1. burning parts 2. not burning one
    // find maximum from non burning part --> mxnb
    // find maximum and minimum from burning part --> mxb , mnb
    // ans will be max(mxnb, (mxb-mnb)/2) + mnb
    int n;
    cin >> n;
    vi v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int lg = log2(n);
    int tablemin[lg + 1][n];
    for (int i = 0; i < lg + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tablemin[i][j] = INT_MAX;
        }
    }
    for (int j = 0; j < n; j++)
    {
        tablemin[0][j] = v[j];
    }
    for (int i = 1; i < lg + 1; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            tablemin[i][j] = min(tablemin[i - 1][j], tablemin[i - 1][j + (1 << (i - 1))]);
        }
    }

    int tablemax[lg + 1][n];
    for (int i = 0; i < lg + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tablemax[i][j] = INT_MIN;
        }
    }
    for (int j = 0; j < n; j++)
    {
        tablemax[0][j] = v[j];
    }
    for (int i = 1; i < lg + 1; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            tablemax[i][j] = max(tablemax[i - 1][j], tablemax[i - 1][j + (1 << (i - 1))]);
        }
    }
    // 18
    // 3 4 2 1 -- 5 7 9 7 10 5 12 -- 3 1 1 2 1 3 2
    //  5 + max(4,3.5)
    // cout << "Enter q : " << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int mxnb1 = 0;
        int mxnb2 = 0;
        if (x == 0)
        {
            mxnb1 = 0;
        }
        else
        {
            int ele1 = x;
            lg = log2(ele1);
            // cout << "lg is " << lg << endl;
            // cout << tablemax[lg][0] << endl;
            // cout << tablemax[lg][x - (1 << lg)] << endl;
            mxnb1 = max(tablemax[lg][0], tablemax[lg][x - (1 << lg)]);
        }
        if (y == (n - 1))
        {
            mxnb2 = 0;
        }
        else
        {
            int ele2 = n - 1 - y;
            // cout << ele2 << endl;
            lg = log2(ele2);
            mxnb2 = max(tablemax[lg][y + 1], tablemax[lg][(n - 1) - (1 << lg) + 1]);
        }
        // cout << mxnb1 << " " << mxnb2 << endl;
        int mxnb = max(mxnb1, mxnb2);
        int ele = y - x + 1;
        lg = log2(ele);
        int mxb = max(tablemax[lg][x], tablemax[lg][y - (1 << lg) + 1]);
        int mnb = min(tablemin[lg][x], tablemin[lg][y - (1 << lg) + 1]);
        // cout << max(mxnb, (mxb - mnb) / 2) + mnb << endl;
        double t2 = double(((double)mxb - (double)mnb) / 2.0);
        // cout << t2 << " " << mxnb << endl;
        // t2=5.5;
        double ans;
        if (t2 >= mxnb)
        {
            ans = t2 + mnb;
        }
        else
        {
            ans = mxnb + mnb;
        }
        cout << fixed << setprecision(1) << ans << endl;
    }
    return 0;
}