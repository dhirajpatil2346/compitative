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
        vl health(n), dmg(n);
        for (int i = 0; i < n; i++)
        {
            cin >> health[i] >> dmg[i];
        }
        multiset<pair<LL, LL>> s;
        for (int i = 0; i < n; i++)
        {
            s.insert({health[i], i});
        }
        // cout << endl;
        LL ans = 0;
        while (s.size())
        {
            auto f = *s.begin();
            s.erase(s.begin());
            int pt = f.second;
            cout << "pt is " << pt << endl;
            if (health[pt] != f.first || health[pt] == 0)
            {
                continue;
            }
            ans += health[pt];
            cout << "ans is " << ans << endl;
            LL dm = dmg[pt];
            int g = pt + 1;
            while (true)
            {
                if (g == n)
                {
                    g = 0;
                }
                if (health[g] == 0)
                    break;
                if (dm < health[g])
                {
                    health[g] -= dm;
                    s.insert({health[g], g});
                    break;
                }
                else
                {
                    health[g] = 0;
                    dm = dmg[g];
                    g++;
                }
            }
            for (auto &val : health)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
8
7 4 --> c
9 10 --> c
4 8
3 1
1 7
9 5 -> c
1 4
2 5

1-> 7 12  5
2-> 9 24 15
3-> 4 15 11
4-> 3 11 8
5-> 1 3  2
6-> 9 17 8
7-> 1 8  7 
8-> 2 7  5

choose 2 --> 9
7 4 -> 7 7
0 0
0 0
0 0
0 0
2 5 -> 2 10
1 4 -> 1 8
2 5 -> 2 7


*/
/*
8
7 4
9 10
4 8
3 1
1 7
9 5
1 4
2 5
choose 1 7 

7 4
9 10
4 7
3 1
0 0
2 5
1 4 
2 5
choose 2 5

2 4
9 10
4 7
3 1
0 0
0 0
0 0
0 0
chose 2 4

0 0
5 10
4 7
3 1
choose 5 10

0 0
0 0
0 0
0 0
*/