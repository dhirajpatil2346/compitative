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
class Node
{
public:
    int manager;
    int wealth;
    vector<Node *> child;
    Node()
    {
        this->manager = -2;
        this->wealth = -1;
    }
    pair<pair<int, int>, int> ans(Node *root)
    {
        // cout << root->wealth << endl;
        pair<pair<int, int>, int> p1 = {{root->wealth, root->wealth}, 0};
        if (root->child.size() == 0)
        {
            return p1;
        }
        int a = 0;
        pair<pair<int, int>, int> p2 = {{root->wealth, root->wealth}, 0};
        for (auto &ch : root->child)
        {
            auto p = ans(ch);
            // cout << p.first.first << " " << p.first.second << " " << p.second << endl;
            p2.second = max(p.second, p2.second);
            p2.second = max(p2.second, root->wealth - p.first.first);
            p2.second = max(p2.second, root->wealth - p.first.second);
            p2.first.first = min(p2.first.first, p.first.first);
            p2.first.second = max(p2.first.second, p.first.second);
        }
        return p2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    Node *v = new Node[n + 1];
    vi wealt(n + 1), man(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> wealt[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> man[i];
        v[i].manager = man[i];
        if (man[i] != -1)
            v[man[i]].child.pb(&v[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        v[i].manager = man[i];
        v[i].wealth = wealt[i];
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << i << " " << v[i].child.size() << endl;
    }
    int no = 1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].manager == -1)
        {
            no = i;
            break;
        }
    }
    // cout << no << endl;
    Node m;
    auto p = m.ans(&v[no]);
    cout << p.second << endl;
    return 0;
}