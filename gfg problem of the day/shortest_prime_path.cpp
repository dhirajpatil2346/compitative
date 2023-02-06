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
vector<bool> primes(10001, true);
void sieve()
{
    int n = 1e4 + 1;
    primes[0] = false, primes[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (!primes[i])
            continue;
        for (int j = 2 * i; j < n; j += i)
        {
            primes[j] = false;
        }
    }
}

vector<int> give(int n, vector<bool> &vis)
{
    vector<int> ret;
    string s = to_string(n);
    for (int i = 0; i < 4; i++)
    {
        int f = 0;
        for (int l = 0; l < i; l++)
        {
            f *= 10;
            f += s[l] - '0';
        }
        f *= int(pow(10, (s.length() - i)));
        for (int j = 1; j < 10; j++)
        {
            int last = int(pow(10, s.length() - i - 1));
            int lastn = n % last;
            int c = (s[i] - '0' + j) % 10;
            c *= last;
            if ((f + c + lastn) / 1000 == 0)
                continue;
            ret.push_back(f + c + lastn);
        }
    }
    return ret;
}

class Solution
{
public:
    int shortestPath(int Num1, int Num2)
    {
        sieve();
        // Complete this function using prime vector

        queue<int> q;
        vector<bool> vis(10001, false);
        vector<int> level(10001, INT_MAX);
        q.push(Num1);
        vis[Num1] = true;
        level[q.front()] = 0;
        if (!primes[q.front()])
            return -1;
        while (!q.empty() && vis[Num2] == false)
        {
            int f = q.front();
            // cout << f << endl;
            vector<int> m = give(f, vis);
            for (auto &val : m)
            {
                // cout << val << endl;
                if (vis[val])
                    continue;
                if (!primes[val])
                    continue;
                q.push(val);
                level[val] = level[f] + 1;
                // cout << val << " " << level[val] << endl;
                vis[val] = true;
            }
            q.pop();
        }
        // int t;
        // cin >> t;
        // while (t--)
        // {
        //     int y;
        //     cin >> y;
        //     // cout << level[y] << endl;
        // }
        return ((level[Num2] == INT_MAX) ? -1 : level[Num2]);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution obj;
    int Num1, Num2;
    cin >> Num1 >> Num2;
    int answer = obj.shortestPath(Num1, Num2);
    cout << answer << endl;
    return 0;
}