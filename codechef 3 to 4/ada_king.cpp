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
bool vis[9][9];
int arr[9][9];

bool is_valid(pair<int, int> p)
{
    int r = p.first, c = p.second;
    if (r <= 0 || r >= 9 || c <= 0 || c >= 9)
        return false;
    if (vis[r][c])
        return false;
    return true;
}

vector<pair<int, int>> pairs(pair<int, int> p)
{
    vector<pair<int, int>> vp;
    int sr = p.first, sc = p.second;
    vp.pb({sr + 1, sc - 1});
    vp.pb({sr + 1, sc + 1});
    vp.pb({sr + 1, sc});
    vp.pb({sr - 1, sc + 1});
    vp.pb({sr - 1, sc - 1});
    vp.pb({sr - 1, sc});
    vp.pb({sr, sc + 1});
    vp.pb({sr, sc - 1});

    vector<pair<int, int>> ret;
    for (auto &val : vp)
    {
        if (is_valid(val))
        {
            ret.pb(val);
        }
    }
    return ret;
}

void solve()
{
    int p1, p2, k;
    cin >> p1 >> p2 >> k;
    memset(vis, false, sizeof(vis));
    memset(arr, -1, sizeof(arr));
    queue<pair<int, int>> q;
    q.push({p1, p2});
    arr[p1][p2] = 0;
    while (!q.empty())
    {
        pair<int, int> f = q.front();
        vis[f.first][f.second] = true;
        vector<pair<int, int>> ret = pairs(f);
        for (auto &val : ret)
        {
            q.push(val);
            arr[val.first][val.second] = arr[f.first][f.second] + 1;
            vis[val.first][val.second] = true;
        }
        q.pop();
    }
    int z = 0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (arr[i][j] <= k)
            {
                z++;
            }
        }
    }
    cout << z << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}