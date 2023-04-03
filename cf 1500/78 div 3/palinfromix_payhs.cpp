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

void dfsu(int sr, int sc, vvi &v, int &n, int &m, vi &one, vi &zero, int lvl, vector<vector<bool>> &vis)
{
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || vis[sr][sc])
    {
        return;
    }
    vis[sr][sc] = true;
    if (v[sr][sc] == 1)
    {
        one[lvl]++;
    }
    else
    {
        zero[lvl]++;
    }
    dfsu(sr - 1, sc, v, n, m, one, zero, lvl + 1, vis);
    dfsu(sr, sc - 1, v, n, m, one, zero, lvl + 1, vis);
}

void dfsd(int sr, int sc, vvi &v, int &n, int &m, vi &one, vi &zero, int lvl, vector<vector<bool>> &vis)
{
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || vis[sr][sc])
    {
        return;
    }
    vis[sr][sc] = true;
    if (v[sr][sc] == 1)
    {
        one[lvl]++;
    }
    else
    {
        zero[lvl]++;
    }
    dfsd(sr + 1, sc, v, n, m, one, zero, lvl + 1, vis);
    dfsd(sr, sc + 1, v, n, m, one, zero, lvl + 1, vis);
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
        int n, m;
        cin >> n >> m;
        vvi v(n, vi(m));
        for (auto &val : v)
            for (auto &valu : val)
                cin >> valu;
        int len = n + m - 1;
        vi p10(len), p11(len), p20(len), p21(len);
        vector<vector<bool>> vis1(n, vector<bool>(m, false));
        vector<vector<bool>> vis2(n, vector<bool>(m, false));
        dfsd(0, 0, v, n, m, p11, p10, 0, vis1);
        dfsu(n - 1, m - 1, v, n, m, p21, p20, 0, vis2);
        // for (auto &val : p11)
        //     cout << val << " ";
        // cout << endl;
        // for (auto &val : p10)
        //     cout << val << " ";
        // cout << endl;
        // for (auto &val : p21)
        //     cout << val << " ";
        // cout << endl;
        // for (auto &val : p20)
        //     cout << val << " ";
        // cout << endl;
        int i = 0, j = len - 1;
        int ans = 0;
        while (i < len / 2)
        {
            int x = p11[i] + p21[i], y = p10[i] + p20[i];
            ans += min(x, y);
            i++, j--;
        }
        cout << ans << endl;
    }
    return 0;
}