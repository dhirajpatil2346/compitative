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
        map<int, int> m;
        for (auto &val : v)
        {
            cin >> val;
            m[val]++;
        }
        SORT(v);
        int maxi = 0;
        for (auto &val : m)
        {
            maxi = max(val.second, maxi);
        }
        if (m.size() == 2)
        {
            if (abs(m.begin()->second - m.rbegin()->second) >= 2)
            {
                cout << -1 << endl;
            }
            else
            {
                int freq1 = m.begin()->second, freq2 = m.rbegin()->second;
                if (freq1 >= freq2)
                {
                    cout << m.begin()->first << " ";
                    int i = 0;
                    while (i < freq2)
                    {
                        cout << m.rbegin()->first << " " << m.begin()->first << " ";
                        i++;
                    }
                    cout << endl;
                }
                else
                {
                    cout << m.rbegin()->first << " ";
                    int i = 0;
                    while (i < freq1)
                    {
                        cout << m.begin()->first << " " << m.rbegin()->first << " ";
                        i++;
                    }
                    cout << endl;
                }
            }
        }
        else if (n > 2 && n % 2 && maxi == n / 2 + 1)
        {
            int valu;
            for (auto &val : m)
            {
                if (val.second == maxi)
                {
                    valu = val.first;
                    break;
                }
            }
            vi ans(n);
            for (int i = 0; i < n; i += 2)
            {
                ans[i] = valu;
            }
            int j = 1;
            for (int i = 0; i < n; i++)
            {
                if (v[i] != valu)
                {
                    ans[j] = v[i];
                    j += 2;
                }
            }
            bool fault = false;
            for (int i = 0; i < n - 2; i++)
            {
                if (ans[i + 2] >= ans[i + 1] && ans[i + 1] >= ans[i])
                {
                    // cout << i << i << endl;
                    fault = true;
                }
                if (ans[i + 2] <= ans[i + 1] && ans[i + 1] <= ans[i])
                {
                    // cout << i << endl;
                    fault = true;
                }
            }
            if (fault)
            {
                cout << -1 << endl;
            }
            else
            {
                for (auto &val : ans)
                {
                    cout << val << " ";
                }
                cout << endl;
            }
        }
        else
        {
            vi ans;
            if (n % 2 == 0)
            {
                int i = 0, j = n / 2;
                while (j < n)
                {
                    ans.pb(v[i++]);
                    ans.pb(v[j++]);
                }
            }
            else
            {
                ans.pb(v[n / 2]);
                int i = 0, j = n / 2 + 1;
                while (j < n)
                {
                    ans.pb(v[j++]);
                    ans.pb(v[i++]);
                }
            }
            bool fault = false;
            for (int i = 0; i < n - 2; i++)
            {
                if (ans[i + 2] >= ans[i + 1] && ans[i + 1] >= ans[i])
                {
                    // cout << i << i << endl;
                    fault = true;
                }
                if (ans[i + 2] <= ans[i + 1] && ans[i + 1] <= ans[i])
                {
                    // cout << i << endl;
                    fault = true;
                }
            }
            if (fault)
            {
                cout << -1 << endl;
            }
            else
            {
                for (auto &val : ans)
                {
                    cout << val << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}