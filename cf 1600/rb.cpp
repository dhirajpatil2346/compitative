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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<pair<int, pair<int, int>>> vp(n);
    multiset<int> first, second, both;
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].first >> vp[i].second.first >> vp[i].second.second;
        if (vp[i].second.first == 1 && vp[i].second.second == 1)
        {
            both.insert(vp[i].first);
        }
        else if (vp[i].second.first == 1)
        {
            first.insert(vp[i].first);
        }
        else if (vp[i].second.second == 1)
        {
            second.insert(vp[i].first);
        }
    }
    bool fault = false;
    int x = k, y = k;
    LL ans = 0;
    // for (auto &val : both)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : first)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : second)
    //     cout << val << " ";
    // cout << endl;
    while (x > 0 || y > 0)
    {
        // cout << x << " " << y << endl;
        if (fault)
            break;
        // int ch;
        // cin >> ch;
        // cout << ch << endl;
        if (x > 0 && y > 0)
        {
            if (both.size() && first.size() && second.size() && *both.begin() <= *(first.begin()) + *(second.begin()))
            {
                ans += *both.begin();
                both.erase(both.begin());
            }
            else if (first.size() && second.size())
            {
                ans += *first.begin();
                first.erase(first.begin());
                ans += *second.begin();
                second.erase(second.begin());
            }
            else if (both.size())
            {
                ans += *both.begin();
                both.erase(both.begin());
            }
            else
            {
                fault = true;
                break;
            }
            x--, y--;
        }
        else if (x > 0)
        {
            if (first.size())
            {
                ans += *first.begin();
                first.erase(first.begin());
            }
            else
            {
                fault = true;
                break;
            }
            x--;
        }
        else if (y > 0)
        {
            if (second.size())
            {
                ans += *second.begin();
                second.erase(second.begin());
            }
            else
            {
                fault = true;
                break;
            }
            y--;
        }
    }
    if (fault)
    {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;
    return 0;
}