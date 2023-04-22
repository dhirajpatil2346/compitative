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

bool is(string &a, string &b)
{
    // check if a is bigger than b
    int i = 0, j = 0;
    while (i < a.length() && j < b.length())
    {
        if (a[i] == b[j])
        {
            i++, j++;
            continue;
        }
        if (a[i] < b[j])
        {
            return false;
        }
        return true;
    }
    if (j == b.length())
        return true;
    if (i == a.length())
        return false;
    return true;
}

long long f(int ind, vl &vn, vector<string> &v, int prev, vector<vector<LL>> &dp)
{
    // cout << ind << endl;
    if (ind >= v.size())
        return 0;
    if (dp[ind][prev] != -1)
        return dp[ind][prev];
    LL ret = 1e15;
    if (prev == 0)
    {
        string a = v[ind];
        string b = v[ind - 1];
        // cout << prev << " " << is(a, b) << endl;
        if (is(a, b))
        {
            ret = min(ret, f(ind + 1, vn, v, 0, dp));
        }
        reverse(ALL(a));
        if (is(a, b))
            ret = min(ret, vn[ind] + f(ind + 1, vn, v, 1, dp));
    }
    else
    {
        string a = v[ind];
        string b = v[ind - 1];
        reverse(ALL(b));
        if (is(a, b))
        {
            ret = min(ret, f(ind + 1, vn, v, 0, dp));
        }
        reverse(ALL(a));
        if (is(a, b))
            ret = min(ret, vn[ind] + f(ind + 1, vn, v, 1, dp));
    }
    ret = min((LL)1e15, ret);
    return dp[ind][prev] = ret;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> v(n);
    vl vn(n);
    for (auto &val : vn)
        cin >> val;
    for (auto &val : v)
        cin >> val;
    vector<vector<LL>> dp(n, vl(2, -1));
    // o .. prev is normal
    // 1 .. prev is reverrsed
    LL ans = 1e15;
    ans = min(ans, f(1, vn, v, 0, dp));
    ans = min(ans, vn[0] + f(1, vn, v, 1, dp));
    LL fa = accumulate(ALL(vn), 0ll);
    if (ans > fa)
        ans = -1;
    cout << ans << endl;
    return 0;
}