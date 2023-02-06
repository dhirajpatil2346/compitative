// 98957
// 2
// bb
// 2
// cb
// 2
// ac
// 2
// bc
// 2
// cc
// 3
// aab
// 3
// bab
// 3
// cab
// 3
// abb
// 3
// bbb
// 3
// cbb
// 3
// acb
// 3
// bcb
// 3
// ccb
// 3
// aac
// 3
// bac
// 3
// cac
// 3
// abc
// 3
// bbc
// 3
// cbc
// 3
// acc
// 3
// bcc
// 3
// ccc
// 4
// aaab
// 4
// baab
// 4
// caab
// 4
// abab
// 4
// bbab
// 4
// cbab
// 4
// acab
// 4
// bcab
// 4
// ccab
// 4
// aabb
// 4
// babb
// 4
// cabb
// 4
// abbb
// 4
// bbbb
// 4
// cbbb
// 4
// acbb
// 4
// bcbb
// 4
// ccbb
// 4
// aacb
// 4
// bacb
// 4
// cacb
// 4
// abcb
// 4
// bbcb
// 4
// cbcb
// 4
// accb
// 4
// bccb
// 4
// cccb
// 4
// aaac
// 4
// baac
// 4
// caac
// 4
// abac
// 4
// bbac
// 4
// cbac
// 4
// acac
// 4
// bcac
// 4
// ccac
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
        string s;
        cin >> s;
        vector<int> one;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                one.pb(i);
        }
        vi a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                a[i]++;
            }
            if (s[i] == 'b')
            {
                b[i]++;
            }
            if (s[i] == 'c')
            {
                c[i]++;
            }
        }
        for (int i = 1; i < n; i++)
        {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
            c[i] += c[i - 1];
        }
        for (auto &val : a)
            cout << val << " ";
        cout << endl;
        for (auto &val : b)
            cout << val << " ";
        cout << endl;
        for (auto &val : c)
            cout << val << " ";
        cout << endl;
        bool got = false;
        for (int i = 2; i <= one.size(); i++)
        {
            if (got)
                break;
            int bc = b[one[i - 1]] - b[one[0]], cc = c[one[i - 1]] - c[one[0]], ac = a[one[i - 1]] - a[one[0]] + 1;
            // cout << ac << " " << bc << " " << cc << endl;
            if (ac > bc && ac > cc)
            {
                got = true;
                cout << one[i - 1] - one[0] + 1 << endl;
                break;
            }
            for (int j = i; j < one.size(); j++)
            {
                if (got)
                    break;
                ac = a[one[j]] - a[one[j - i + 1]] + 1;
                bc = b[one[j]] - b[one[j - i + 1]];
                cc = c[one[j]] - c[one[j - i + 1]];
                // cout << i << " " << j << " " << ac << " " << bc << " " << cc << endl;
                if (ac > bc && ac > cc)
                {
                    // cout << i << " " << j << endl;
                    cout << one[j] - one[j - i + 1] + 1 << endl;
                    got = true;
                    break;
                }
            }
        }
        if (!got)
            cout << -1 << endl;
    }
    return 0;
}