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
    int n, k;
    cin >> n >> k;
    vector<int> graph[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    if (graph[k].size() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    vi leaf;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            leaf.pb(i);
        }
    }
    vector<int> lvl(n + 1, -1);
    {
        queue<int> q;
        q.push(k);
        lvl[k] = 0;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for (auto &val : graph[f])
            {
                if (lvl[val] != -1)
                    continue;
                q.push(val);
                lvl[val] = lvl[f] + 1;
            }
        }
    }
    int covered = 0;
    for (int i = 0; i < n + 1; i++)
    {
        // cout << i << " " << lvl[i] << endl;
    }
    set<pair<int, int>> s;
    for (auto &val : leaf)
        s.insert({lvl[val], val});
    vi newlvl(n + 1, -1);
    int cnt = 0;
    while (s.size())
    {
        auto f = *s.begin();
        s.erase(s.begin());
        vector<int> new_lvl(n + 1, -1);
        queue<int> q;
        q.push(f.second);
        // cout << f.second << endl;
        newlvl[f.second] = 0;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for (auto &val : graph[f])
            {
                if (newlvl[val] != -1)
                    continue;
                q.push(val);
                newlvl[val] = newlvl[f] + 1;
            }
        }
        cnt++;
        set<pair<int, int>> ns;
        for (auto &val : s)
        {
            int pt = val.second;
            if (newlvl[pt] <= lvl[pt])
                continue;
            ns.insert(val);
        }
        s = ns;
    }
    cout << cnt << endl;
    return 0;
}