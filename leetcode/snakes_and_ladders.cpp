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

vector<int> get(int sc, vector<int> &v, vector<int> &level)
{
    vector<int> ret;
    for (int i = 1; i <= 6; i++)
    {
        if (sc + i >= v.size())
            break;
        ret.push_back(sc + i);
    }
    return ret;
}

int ans(vector<int> &v)
{
    queue<int> q;
    q.push(1);
    int n = v.size();
    vector<int> level(n, INT_MAX);
    level[1] = 0;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        // cout << f << endl;
        if (v[f] != -1)
        {
            if (level[v[f]] >= level[f])
            {
                q.push(v[f]);
                level[v[f]] = level[f];
            }
        }
        else
        {
            vector<int> ret = get(f, v, level);
            for (auto &val : ret)
            {
                if (level[val] > level[f])
                {
                    level[val] = level[f] + 1;
                    q.push(val);
                }
            }
        }
    }
    for (int i = 1; i <= 36; i++)
    {
        cout << i << " " << level[i] << endl;
    }
    return ((level.back() == INT_MAX) ? -1 : level.back());
}

int snakesAndLadders(vector<vector<int>> &board)
{
    vector<int> v(int(int(board.size()) * int(board.size()) + 1));
    int i = 1;
    int n = board.size();
    int l = 0;
    for (int z = n - 1; z >= 0; z--, l++)
    {
        if (l % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                v[i++] = board[z][j];
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                v[i++] = board[z][j];
            }
        }
    }
    return ans(v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vvi v(n, vi(n));
    for (auto &val : v)
    {
        for (auto &valu : val)
        {
            cin >> valu;
        }
    }
    cout << snakesAndLadders(v);
    return 0;
}
// [[-1,4,-1],[6,2,6],[-1,3,-1]]
// [
// [-1,1,2,-1],
// [2,13,15,-1],
// [-1,10,-1,-1],
// [-1,6,2,8]
// ]

// [
//     [-1,-1,30,14,15,-1],
//     [23,9,-1,-1,-1,9],
//     [12,5,7,24,-1,30],
//     [10,-1,-1,-1,25,17],
//     [32,-1,28,-1,-1,32],
//     [-1,-1,23,-1,13,19]
// ]
