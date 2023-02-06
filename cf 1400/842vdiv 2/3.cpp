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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi v(n);
        for (auto &val : v)
            cin >> val;
        vi g[n + 1];
        for (int i = 0; i < n; i++)
        {
            g[v[i]].pb(i);
        }
        if (g[1].size() >= 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            bool fault = false;
            for (int i = 2; i <= n; i++)
            {
                if (g[i].size() > 2)
                {
                    fault = true;
                }
            }
            if (fault)
            {
                cout << "NO" << endl;
            }
            vi v1(n), v2(n);
            for (int i = 0; i <= n; i++)
            {
                // cout << i << " " << g[i].size() << endl;
            }

            vector<int> temp;
            for (int i = 1; i <= n; i++)
            {
                if (g[i].size() == 0)
                {
                    temp.pb(i);
                    temp.pb(i);
                }
                if (g[i].size() == 2)
                {
                    v1[g[i][0]] = i;
                    v2[g[i][1]] = i;
                }
                if (g[i].size() == 1)
                {
                    temp.pb(i);
                    v1[g[i][0]] = i;
                }
            }
            // for (auto &val : v1)
            //     cout << val << " ";
            // cout << endl;
            // for (auto &val : v2)
            //     cout << val << " ";
            // cout << endl;
            // for (auto &val : temp)
            //     cout << val << " ";
            // cout << endl;
            for (int i = n; i >= 0 && temp.size(); i--)
            {
                for (auto &val : g[i])
                {
                    // cout << i << " " << val << endl;
                    if (v1[val] == 0 && temp.size())
                    {
                        v1[val] = temp.back();
                        temp.pop_back();
                    }
                    if (v2[val] == 0 && temp.size())
                    {
                        v2[val] = temp.back();
                        temp.pop_back();
                    }
                }
            }
            vi freq1(n + 1), freq2(n + 1);
            for (int i = 0; i < n; i++)
            {
                freq1[v1[i]]++;
            }
            for (int i = 0; i < n; i++)
            {
                freq2[v2[i]]++;
            }
            for (int i = 0; i < n; i++)
            {
                if (freq1[v1[i]] == 2)
                {
                    freq2[v2[i]]--;
                    freq1[v1[i]]--;
                    int tem = v1[i];
                    v1[i] = v2[i];
                    v2[i] = tem;
                    freq1[v1[i]]++;
                    freq2[v2[i]]++;
                }
                if (freq2[v2[i]] == 2)
                {
                    freq2[v2[i]]--;
                    freq1[v1[i]]--;
                    int tem = v1[i];
                    v1[i] = v2[i];
                    v2[i] = tem;
                    freq1[v1[i]]++;
                    freq2[v2[i]]++;
                }
            }
            map<int, int> m1, m2;
            for (auto &val : v1)
            {
                m1[val]++;
            }
            for (auto &val : v2)
            {
                m2[val]++;
            }
            bool flt = false;
            if (m1[0] > 0 || m2[0] > 0)
                flt = true;
            for (auto &val : m1)
            {
                if (val.second > 2)
                    flt = true;
            }
            for (auto &val : m2)
            {
                if (val.second > 2)
                    flt = true;
            }
            if (flt)
            {
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            for (auto &val : v1)
            {
                cout << val << " ";
            }
            cout << endl;
            for (auto &val : v2)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}