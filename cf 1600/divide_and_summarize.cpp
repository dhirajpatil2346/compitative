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

int pos(int l, int r, vl &v, LL tar)
{
    if (r < l)
        return -1;
    if (l == r)
    {
        if (v[l] <= tar)
            return l;
        return -1;
    }
    int mid = (l + r) / 2;
    if (v[mid] <= tar)
    {
        int right = pos(mid + 1, r, v, tar);
        if (right == -1)
            return mid;
        return right;
    }
    else
    {
        return pos(l, mid - 1, v, tar);
    }
}

void calc(int l, int r, vl &v, vl &pre, set<LL> &track, set<pair<int, int>> &acc)
{
    // cout << l << r << endl;
    // int c;
    // cin >> c;
    if (acc.find({l, r}) != acc.end())
        return;
    acc.insert({l, r});
    if (r < l)
        return;
    if (l == r)
    {
        track.insert(v[l]);
        return;
    }
    if (l == 0)
    {
        track.insert(pre[r]);
    }
    else
    {
        track.insert(pre[r] - pre[l - 1]);
    }
    int mid = (v[l] + v[r]) / 2;
    int ind = l;
    if (*lower_bound(ALL(v), mid) == mid)
    {
        ind = lower_bound(ALL(v), mid + 1) - v.begin() - 1;
    }
    else
    {
        ind = upper_bound(ALL(v), mid) - v.begin() - 1;
    }
    calc(l, ind, v, pre, track, acc);
    calc(ind + 1, r, v, pre, track, acc);
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
        set<LL> track;
        int n, q;
        cin >> n >> q;
        vl v(n);
        for (auto &val : v)
            cin >> val;
        SORT(v);
        vl pre(n);
        pre[0] = v[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + v[i];
        }
        // cout << "nknl" << endl;
        set<pair<int, int>> acc;
        calc(0, n - 1, v, pre, track, acc);
        // for (auto &val : track)
        //     cout << val << " ";
        // cout << endl;
        while (q--)
        {
            LL x;
            cin >> x;
            if (track.find(x) == track.end())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}