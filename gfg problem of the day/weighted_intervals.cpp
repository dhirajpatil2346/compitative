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

int bin(int l, int r, vector<pair<int, int>> &vp, int val)
{
    if (l > r)
        return -1;
    if (l == r)
    {
        if (vp[l].second <= val)
            return l;
        return -1;
    }
    int mid = (l + r) / 2;
    if (vp[mid].second <= val)
    {
        int right = bin(mid + 1, r, vp, val);
        if (right == -1)
            return mid;
        else
            return right;
    }
    else
    {
        return bin(l, mid - 1, vp, val);
    }
    return -1;
}

bool compare(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2)
{
    if (p1.first.first == p2.first.first && p1.first.second == p2.first.second)
        return p1.second <= p2.second;
    if (p1.first.second == p2.first.second)
        return p1.second <= p2.second;
    return p1.first.second <= p2.first.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> intervals;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        intervals.pb({a, b, c});
    }
    vector<pair<pair<int, int>, int>> z;
    for (auto &val : intervals)
    {
        z.push_back({{val[0], val[1]}, val[2]});
    }
    // SORT(z);
    sort(z.begin(), z.end(), compare);
    vector<pair<int, int>> vp = {{0, 0}};
    vector<int> v = {0};
    for (auto &val : z)
    {
        vp.push_back(val.first);
        v.push_back(val.second);
    }
    for (auto &val : vp)
    {
        cout << val.first << " " << val.second << endl;
    }
    vector<int> m = {0};
    for (int i = 1; i < v.size(); i++)
    {
        m.push_back(bin(0, i - 1, vp, vp[i].first));
    }
    for (auto &val : m)
        cout << val << " ";
    cout << endl;
    vector<int> M(v.size());
    M[0] = 0;
    for (int i = 1; i < M.size(); i++)
    {
        M[i] = max(M[i - 1], v[i] + M[m[i]]);
    }
    cout << M[M.size() - 1] << endl;
    return 0;
}