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

void dfs(char sc, set<char> &vis, string &track, map<char, vector<char>> &mrev)
{
    if (vis.find(sc) != vis.end())
        return;
    vis.insert(sc);
    for (auto &val : mrev[sc])
    {
        dfs(val, vis, track, mrev);
    }
    track.pb(sc);
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
        string s;
        cin >> s;
        int n = s.length();
        map<char, vector<char>> m, mrev;
        for (int i = 0; i < n - 1; i++)
        {
            m[s[i]].pb(s[i + 1]);
        }
        for (auto &val : m)
        {
            for (auto &valu : val.second)
            {
                mrev[valu].pb(val.first);
            }
        }
        char sc = s[n - 1];
        for (auto &val : mrev)
        {
            if (val.second.size() < mrev[sc].size())
            {
                sc = val.first;
            }
        }
        string track = "";
        set<char> vis;
        dfs(sc, vis, track, mrev);
        // cout << track << endl;
        set<pair<char, char>> final;
        for (int i = 0; i < (int)track.size() - 1; i++)
        {
            final.insert({track[i], track[i + 1]});
            final.insert({track[i + 1], track[i]});
        }
        bool fault = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (final.find({s[i], s[i + 1]}) == final.end() || final.find({s[i + 1], s[i]}) == final.end())
            {
                fault = true;
            }
        }
        if (fault)
        {
            cout << "NO" << endl;
        }
        else
        {
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (vis.find(i) == vis.end())
                {
                    track.pb(i);
                }
            }
            cout << "YES" << endl
                 << track << endl;
        }
    }
    return 0;
}
/*
y<->t
^
|
^
z<->x

*/
/*
1 2 4 7

*/