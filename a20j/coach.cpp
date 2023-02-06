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

void dfs(int sc, vector<bool> &vis, vector<int> v[], vector<int> &ret)
{
    if (vis[sc])
    {
        return;
    }
    vis[sc] = true;
    ret.pb(sc);
    for (auto &child : v[sc])
    {
        if (vis[child])
        {
            continue;
        }
        dfs(child, vis, v, ret);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    vector<bool> vis(n + 1);
    vis[0] = true;
    bool fault = false;
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        if (v[i].size())
        {
            vector<int> l;
            dfs(i, vis, v, l);
            if (l.size() > 3)
            {
                fault = true;
            }
            else
            {
                ans.push_back(l);
            }
        }
    }
    if (fault)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<vector<int>> print;
        int j = 1;
        for (auto &val : ans)
        {
            if (val.size() == 3)
            {
                print.push_back(val);
            }
            else
            {
                while (j < n + 1 && vis[j])
                {
                    j++;
                }
                if (j == n + 1)
                {
                    continue;
                }
                val.pb(j);
                vis[j] = true;
                print.pb(val);
            }
        }
        int cnt = 0;
        vector<int> curr;
        while (j < n + 1)
        {
            if (vis[j])
            {
                j++;
                continue;
            }
            else
            {
                curr.pb(j);
                j++;
                cnt++;
                if (cnt == 3)
                {
                    print.pb(curr);
                    curr.clear();
                    cnt = 0;
                }
            }
        }
        for (auto &val : print)
        {
            if (val.size() <= 2)
            {
                fault = true;
            }
        }
        if (fault || print.size()!=(n/3))
        {
            cout << -1 << endl;
        }
        else
        {
            // cout << "Printing\n";
            for (auto &val : print)
            {
                for (auto &valu : val)
                {
                    cout << valu << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}