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
vector<int> bap(200005), child(200005);

int dfs(int sc, vector<bool> &vis, vvi &graph, int b)
{
    if (vis[sc])
        return 0;
    vis[sc] = true;
    bap[sc] = b;
    int a = 0;
    for (auto &val : graph[sc])
    {
        a += dfs(val, vis, graph, b + 1);
    }
    child[sc] = a;
    return a + 1;
}

bool cmp(int a, int b)
{
    if (bap[a] > bap[b])
        return true;
    if (bap[a] == bap[b])
        return child[a] <= child[b];
    return false;
}

void dfsfinal(int sc, vvi &graph, vector<bool> &vis, int b, vector<bool> &taken, vector<int> &f)
{
    if (vis[sc])
        return;
    vis[sc] = true;
    if (taken[sc])
    {
        f[sc] = b;
    }
    else
    {
        f[sc] = 0;
    }
    for (auto &c : graph[sc])
    {
        if (!taken[sc])
            dfsfinal(c, graph, vis, b + 1, taken, f);
        else
            dfsfinal(c, graph, vis, b, taken, f);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n + 1);
    vi f(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    vector<bool> vis(n + 1, false);
    dfs(1, vis, graph, 0);
    for (int i = 0; i < vis.size(); i++)
    {
        vis[i] = false;
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.pb(i + 1);
    sort(ALL(v), cmp);
    vector<bool> taken(n + 1, false);
    for (int i = 0; i < k; i++)
    {
        // cout << v[i] << " ";
        taken[v[i]] = true;
    }
    // cout << endl;
    dfsfinal(1, graph, vis, 0, taken, f);
    cout << accumulate(ALL(f), 0) << endl;
    return 0;
}