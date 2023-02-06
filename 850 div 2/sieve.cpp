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
        vector<map<char, int>> v(n);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            SORT(s);
            if (s == "inw")
            {
                vis[i] = true;
            }
            map<char, int> m;
            for (auto &val : s)
            {
                m[val]++;
            }
            v[i] = m;
        }
        int cnt = 0;
        vector<pair<int, char>> vp;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            map<char, int> m = v[i];
            for (int j = i + 1; j < n; j++)
            {
                if (vis[j])
                    continue;
                map<char, int> m1 = v[j];
                if (m['i'] == 0 && m1['i'] > 1)
                {
                    if (m['n'] > 1)
                    {
                        m1['n']++;
                        m['n']--;
                        m['i']++;
                        m1['i']--;
                        vp.pb({i + 1, 'n'});
                        vp.pb({j + 1, 'i'});
                    }
                    else if (m['w'] > 1)
                    {

                        m1['w']++;
                        m['w']--;
                        m1['i']--;
                        m['i']++;
                        vp.pb({i + 1, 'w'});
                        vp.pb({j + 1, 'i'});
                    }
                }
                if (m['n'] == 0 && m1['n'] > 1)
                {
                    if (m['i'] > 1)
                    {
                        m['n']++;
                        m1[n]--;
                        m['i']--;
                        m1['i']++;
                        vp.pb({i + 1, 'i'});
                        vp.pb({j + 1, 'n'});
                    }
                    else if (m['w'] > 1)
                    {

                        m1['w']++;
                        m['w']--;
                        m['n']++;
                        m1['n']--;
                        vp.pb({i + 1, 'w'});
                        vp.pb({j + 1, 'n'});
                    }
                }
                if (m['w'] == 0 && m1['w'] > 1)
                {
                    if (m['i'] > 1)
                    {
                        m['w']++;
                        m1['w']--;
                        m['i']--;
                        m1['i']++;
                        vp.pb({i + 1, 'i'});
                        vp.pb({j + 1, 'n'});
                    }
                    else if (m['n'] > 1)
                    {

                        m1['w']++;
                        m['w']--;
                        m1['n']++;
                        m['n']--;
                        vp.pb({i + 1, 'w'});
                        vp.pb({j + 1, 'n'});
                    }
                }
                v[i] = m;
                v[j] = m1;
                if (m['i' == 1] && m['n'] == 1 && m['w'] == 1)
                    vis[i] = true;
                if (m1['i' == 1] && m1['n'] == 1 && m1['w'] == 1)
                    vis[j] = true;
            }
        }
        cout << vp.size() / 2 << endl;
        for (int i = 0; i < vp.size(); i++)
        {
            cout << vp[i].first << " " << vp[i].second << " ";
            i++;
            cout << vp[i].first << " " << vp[i].second << endl;
        }
    }
    return 0;
}