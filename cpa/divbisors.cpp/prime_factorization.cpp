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
/*
#ifdef TESTING
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif
*/
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

int binpow(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int n = 1e6 + 10;
    vi v(n);
    FOR(i, 0, n)
    {
        v[i] = i;
    }
    map<int, int> ans;
    for (int i = 2; i * 1ll * i < n * 1ll; i++)
    {
        if (v[i] != i)
        {
            continue;
        }
        for (int j = i * i; j < n; j += i)
        {
            v[j] = i;
        }
    }
    /*
    for (int i = 0; i < 100; i++)
    {
        cout << i << " " << v[i] << endl;
    }
    */
    int q;
    cin >> q;
    for (int I = 0; I < q; I++)
    {
        int m;
        cin >> m;
        map<int, int> factors;
        while (m > 1)
        {
            factors[v[m]]++;
            m /= v[m];
        }
        vector<pair<int, int>> vp;
        for (auto &val : factors)
        {
            vp.pb({val.fi, val.se});
        }
        /*
        for (auto &val : vp)
        {
            cout << val.fi << " " << val.se << endl;
        }
        */
        unordered_set<int> us;
        for (int i = 0; i < vp.size(); i++)
        {
            auto p1 = vp[i];
            int ele1 = p1.fi;
            int frq1 = p1.se;
            for (int j = i + 1; j < vp.size(); j++)
            {
                auto p2 = vp[j];
                int ele2 = p2.fi, freq2 = p2.se;
                for (int k = 0; k <= frq1; k++)
                {
                    int a = binpow(ele1, k);
                    for (int l = 0; l <= freq2; l++)
                    {
                        int b = binpow(ele2, l);
                        us.insert(a * b);
                    }
                }
            }
        }
        for (auto &val : vp)
        {
            int ele = val.fi, freq = val.se;
            for (int X = 0; X <= freq; X++)

            {
                us.insert(binpow(ele, X));
            }
        }
        for (auto &val : us)
        {
            ans[val]++;
        }
    }
    int h = 1;
    for (auto &val : ans)
    {
        if (val.se >= 2)
        {
            h = max(h, val.fi);
        }
    }
    cout << h << endl;
    return 0;
}
// /home/dhirajpatil2346/compitative/cpa/divbisors.cpp/prime_factorization.cpp