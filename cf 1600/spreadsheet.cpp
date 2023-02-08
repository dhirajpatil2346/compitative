// 1000
// R621C406
// ABD815
// R3C24
// R634C162
// R695C621
// R875C898
// AHG626
// AFE664
// R95C969
// R21C933
// R629C648
// R253C417
// WQ20
// AGA989
// XO484
// R912C396
// R292C168
// PI999
// TR254
// PH609
// R207C905
// R762C995
// LL946
// R292C805
// R174C206
// NY237
// R345C125
// R657C212
// AEY185
// BB81
// HG448
// NB654
// VA829
// NH784
// R2C279
// AR66
// R555C813
// R239C905
// YQ299
// R664C480
// IU325
// R691C157
// R39C597
// AF614
// OT619
// R861C285
// UH114
// R128C356
// EU796
// R875C881
// R905C18
// WX612
// R320C311
// R230C827
// BH855
// R228C494
// R537C643
// ABR841
// R338C5
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

string one(string s)
{
    // s = BC23
    // output = R23C55
    string r = "";
    int i = 0;
    while (s[i] >= 65)
    {
        r += s[i];
        i++;
    }
    string next = "";
    while (i < s.length())
    {
        next += s[i];
        i++;
    }
    REVERSE(r);
    // cout << r << endl;
    int a = 1;
    int num = 0;
    for (i = 0; i < r.length(); i++)
    {
        int j = num;
        num = ((r[i] - 'A' + 1) * a) + j;
        a *= 26;
    }
    string ret = "R";
    ret += next;
    ret += "C";
    ret += to_string(num);
    return ret;
}
string two(string s)
{
    // s = R23C55
    // output = BC23
    int i = 1;
    string next = "";
    while (s[i] != 'C')
    {
        next += s[i];
        i++;
    }
    i++;
    int num = 0;
    while (i < s.length())
    {
        num *= 10;
        num += (s[i] - '0');
        i++;
    }
    stack<int> st;
    int b = 1;
    vector<int> p;
    while (b <= 1e6)
    {
        p.pb(b);
        b *= 26;
    }
    vector<int> cnt(p.size());
    while (num != 0)
    {
        for (i = 0; i < p.size(); i++)
        {
            if (num >= p[i])
            {
                cnt[i]++;
                num -= p[i];
            }
        }
    }
    for (i = 0; i < cnt.size() - 1; i++)

    {
        while (cnt[i] > 26)
        {
            cnt[i] -= 26;
            cnt[i + 1]++;
        }
    }
    string h = "";
    // for (auto &val : cnt)
    //     cout << val << " ";
    // cout << endl;
    for (i = 0; i < cnt.size(); i++)
    {
        if (cnt[i] == 0)
            break;
        h += (char('A' + cnt[i] - 1));
    }
    // cout << h << endl;
    REVERSE(h);
    h += next;
    string ret = h;
    return ret;
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
        string s;
        cin >> s;
        int type = 2;
        int i = 0;
        while (s[i] >= 'A')
            i++;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            i++;
        if (i == s.length())
            type = 1;
        // cout << type << endl;
        if (type == 1)
        {
            cout << one(s) << endl;
        }
        else
        {
            cout << two(s) << endl;
        }
    }
    return 0;
}