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

int bin(int val, vector<int> &v, int l, int r)
{
    int mid = (l + r) / 2;
    if (l > r)
        return -1;
    if (l == r)
    {
        if (val >= v[mid])
            return l;
    }
    else if (val >= v[mid])
    {
        int right = bin(val, v, mid + 1, r);
        if (right == -1)
            return mid;
        else
            return right;
    }
    else if (val < v[mid])
    {
        return bin(val, v, l, mid - 1);
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi v1(n);
    vi v2(n);
    for (auto &val : v1)
        cin >> val;
    for (auto &val : v2)
        cin >> val;
    vector<int> c1(n), c2(n);
    for (int i = 0; i < n; i++)
    {
        c1[i] = v1[i] - v2[i];
    }
    for (int i = 0; i < n; i++)
    {
        c2[i] = -1 * c1[i];
    }
    SORT(c2);

    // for (auto &val : c2)
    //     cout << val << " ";
    // cout << endl;

    LL sum = 0;
    for (int i = 0; i < n; i++)
    {
        int z = bin(c1[i] - 1, c2, 0, n - 1);
        // cout << c1[i] << " " << z << endl;
        if (c1[i] <= 0)
            sum += z + 1;
        else
            sum += (z);
    }
    cout << sum / 2 << endl;
    return 0;
}
/*
    4 8 2 6 2
    4 5 4 1 3
    ai + aj > bi + bj
--> ai - bi > bj - aj
ai-bi = 0  3 -2  5 -1  --> -2 -1 0 3 5
bj-aj = 0 -3  2 -5  1  --> -5 -3 0 1 2
            -2 -> -3 -5
            -1 -> -3 -5
            0 -> -3 -5
            3 -> 4
            5 -> 4
*/