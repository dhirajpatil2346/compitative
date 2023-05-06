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
    int _;
    cin >> _;
    while (_--)
    {
        int N;
        cin >> N;
        vl V(N);
        for (auto &val : V)
            cin >> val;
        map<LL, int> m;
        for (auto &val : V)
            m[val]++;
        vl left;
        for (auto &val : m)
        {
            if (val.second % 2 != 0)
                left.pb(val.first);
        }
        vl ans;
        int n = left.size();
        if (n < 2)
        {
            for (auto &val : m)
            {
                if (val.second >= 2)
                {
                    val.second -= 2;
                    left.pb(val.first);
                    left.pb(val.first);
                    break;
                }
            }
        }
        vl v = left;
        n = v.size();
        // cout << n << endl;
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i += 2)
            {
                LL l = 1;
                for (int j = 0; j < 2; j++)
                {
                    l = lcm(l, abs(v[i + j]));
                }
                LL t1 = l, t2 = (-1) * l;
                ans.pb(t1 / v[i]);
                ans.pb(t2 / v[i + 1]);
            }
        }
        else
        {

            int pos = 0;
            LL val = 0;
            LL l = 1;
            for (int i = 0; i < 3; i++)
            {
                l = lcm(l, v[i]);
            }
            LL t1 = l, t2 = (-2) * l;
            val += t1 / v[0];
            val += t1 / v[1];
            val += t2 / v[2];

            for (int j = 0; j < n; j += 2)
            {
                if (j + 3 >= n)
                    break;
                LL cval = 0;
                LL cl = 1;
                for (int i = 0; i < 3; i++)
                {
                    l = lcm(l, v[i + j]);
                }
                t1 = l, t2 = (-2) * l;
                cval += t1 / v[j];
                cval += t1 / v[j + 1];
                cval += t2 / v[j + 2];
                if (cval < val)
                {
                    val = cval;
                    pos = j;
                }
            }
            for (int i = 0; i < n; i += 2)
            {
                if (i == pos)
                {
                    l = 1;
                    for (int j = 0; j < 3; j++)
                    {
                        l = lcm(l, abs(v[j + i]));
                    }
                    t1 = l, t2 = (-2) * l;
                    ans.pb(t1 / v[i]);
                    ans.pb(t1 / v[i + 1]);
                    ans.pb(t2 / v[i + 2]);
                    i++;
                }
                else
                {
                    l = 1;
                    for (int j = 0; j < 2; j++)
                    {
                        l = lcm(l, abs(v[i + j]));
                    }
                    LL t1 = l, t2 = (-1) * l;
                    ans.pb(t1 / v[i]);
                    ans.pb(t2 / v[i + 1]);
                }
            }
        }
        map<LL, queue<int>> track;
        for (int i = 0; i < n; i++)
        {
            track[left[i]].push(ans[i]);
        }
        map<LL, LL> pos, neg;
        for (auto &val : m)
        {
            pos[val.first] = val.second / 2;
            neg[val.first] = val.second / 2;
        }
        for (int i = 0; i < N; i++)
        {
            if (pos[v[i]] > 0)
            {
                cout << 1 << " ";
                pos[v[i]]--;
            }
            else if (neg[v[i]] > 0)
            {
                cout << -1 << " ";
                neg[v[i]]--;
            }
            else
            {
                int y = track[v[i]].front();
                cout << y << " ";
                track[v[i]].pop();
            }
        }
        cout << endl;
    }
    return 0;
}