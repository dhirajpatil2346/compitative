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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    // cout << n << k << endl;
    string s;
    cin >> s;
    // cout << s << endl;
    // return 0;
    string curr = "";
    int i = 0;
    curr.pb(s[i++]);
    while (i < n && s[i] == curr[0])
    {
        // cout << i << endl;
        curr.pb(s[i++]);
    }
    while (i < n && s[i] < curr[0])
    {
        // cout << i << endl;
        curr.pb(s[i++]);
    }
    // cout << curr << endl;
    while (i < n)
    {
        // cout << i << " " << curr << endl;
        if (s[i] < curr[0])
            curr.pb(s[i++]);
        else if (s[i] > curr[0])
            break;
        else
        {
            if (curr.length() * 2 <= s.length())
            {
                // cout << "k" << endl;
                bool fault = false;
                string h = s.substr(i, curr.length());
                if (curr >= h)
                {
                }
                else
                {
                    fault = true;
                }
                if (fault)
                    break;
                else
                {
                    // cout << "1st " << i << " " << c2 << endl;
                    curr += h;
                    i = curr.length();
                    // cout << curr << endl;
                }
            }
            else
            {
                bool can = false;
                int c1 = 0, c2 = i;
                while (c1 < i && c2 < n)
                {
                    // cout << curr[c1] << " " << s[c2] << endl;
                    if (curr[c1] > s[c2])
                    {
                        c1++, c2++;
                        can = true;
                        break;
                    }
                    else if (curr[c1] == s[c2])
                    {
                        c1++, c2++;
                    }
                    else
                    {
                        c1++, c2++;
                        can = false;
                        break;
                    }
                }
                // cout << "can   " << can << " " << curr << endl;
                if (can)
                {
                    // cout << i << " " << c2 << endl;
                    for (int j = i; j < c2; j++)
                    {
                        curr.pb(s[j]);
                    }
                    i = curr.length();
                }
                else
                    break;
            }
        }
    }
    n = curr.length();
    int c = k / n + min(1, k % n);
    string ret = "";
    for (int u = 0; u < c; u++)
        ret += curr;
    curr = ret.substr(0, k);
    cout << curr << endl;
    return 0;
}