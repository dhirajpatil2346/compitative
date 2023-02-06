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
        int n, k;
        cin >> n >> k;
        vi ans;
        vi v(n);
        for (auto &val : v)
            cin >> val;
        int sum = 0;
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            int x = v[i];
            q.push(x);
            sum += x;
        }
        int ccsem = sum;
        for (int i = k, j; i < n; i++)
        {
            int vz = q.front();
            q.pop();
            ccsem -= vz;
            sum = max(sum, ccsem);
        }

        while (!q.empty())
        {
            q.pop();
        }
        int csum = 0;
        for (int i = 0; i < k - 1; i++)
        {
            q.push(v[i]);
            csum += v[i];
            ans.push_back(v[i]);
        }
        bool fault = false;
        int j = 0;
        cout << sum << endl;
        for (int i = k - 1; i < n; i++)
        {
            int h = v[i];
            if (fault)
                continue;
            while (fault == false && j <= n)
            {
                j++;
                if (j > n)
                    fault = true;
                if (fault)
                    break;
                cout << i << " " << csum << " " << h << endl;
                if (h + csum == sum)
                {
                    q.push(h);
                    ans.pb(h);
                    csum += h;
                    cout << i << endl;
                    csum -= q.front();
                    csum += h;
                    q.pop();
                }
                else if (csum >= sum || h > sum)
                {
                    fault = true;
                }
                else if (h + csum < sum)
                {
                    int diff = sum - (csum);
                    if (diff > n)
                    {
                        fault = true;
                        break;
                    }
                    else
                    {
                        csum += diff;
                        ans.pb(diff);
                        q.push(diff);
                        q.pop();
                    }
                }
                else if (h + csum > sum)
                {
                    int diff = sum - csum;
                    csum += diff;
                    ans.pb(diff);
                    q.push(diff);
                    q.pop();
                }
            }
        }
        if (fault)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans.size() << endl;
            for (auto &val : ans)
                cout << val << " ";
            cout << endl;
        }
    }
    return 0;
}