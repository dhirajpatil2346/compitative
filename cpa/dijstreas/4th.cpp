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

long long fun(vector<int> &a)
{
    vector<long long> v;
    for (auto i = 0; i < a.size(); i++)
    {
        v.push_back(a[i]);
    }
    int n = a.size();
    vl pref(n), suff(n);
    int f = 0, l = n - 1;

    long long ans = 0;
    for (int u = 0; u < 3; u++)
    {
        for (int i = 0; i < f - 1; i++)
        {
            v[i] = 0;
        }
        for (int i = l + 1; i < n; i++)
        {
            v[i] = 0;
        }
        pref[0] = v[0], suff[n - 1] = v[n - 1];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + v[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = suff[i + 1] + v[i];
        }
        for (auto &val : v)
        {
            cout << val << " ";
        }
        cout << endl;
        for (auto &val : pref)
        {
            cout << val << " ";
        }
        cout << endl;
        for (auto &val : suff)
        {
            cout << val << " ";
        }
        cout << endl;
        int pos1 = f;
        int pos2 = l;
        for (int i = f; i < l - 1; i++)
        {
            if (pref[i] > pref[pos1])
            {
                pos1 = i;
            }
        }
        for (int i = l; i > f; i--)
        {
            if (suff[i] > suff[pos2])
            {
                pos2 = i;
            }
        }
        if (pref[pos1] > suff[pos2])
        {
            ans += pref[pos1];
            f = pos1 + 1;
        }
        else
        {
            ans += suff[pos2];
            l = pos2 - 1;
        }

        cout << f << " " << l << " " << ans << endl;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi v(n);
    for (auto &val : v)
        cin >> val;
    cout << fun(v) << endl;
    return 0;
}