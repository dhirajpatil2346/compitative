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
class Solution
{
public:
    multimap<int, int> combine(int a1, int a2, vector<multimap<int, int>> &a, map<int, int> &freq)
    {
        multimap<int, int> m1 = a[a1], m2 = a[a2];
        for (auto &val : m2)
        {
            m1.insert(val);
        }
        return m1;
    }
    void build(vector<multimap<int, int>> &a, int ind, vector<int> &A, int l, int r, map<int, int> &freq)
    {
        if (r < l)
            return;
        if (l == r)
        {
            a[ind].insert({A[l], freq[A[l]]});
            return;
        }
        int mid = (l + r) / 2;
        build(a, ind * 2, A, l, mid, freq);
        build(a, ind * 2 + 1, A, mid + 1, r, freq);
        a[ind] = combine(ind * 2, ind * 2 + 1, a, freq);
    }
    int search(vector<multimap<int, int>> &a, int ind, vector<int> &A, int l, int r, int L, int R, int k)
    {
        if (r < L)
            return 0;
        if (l > R)
            return 0;
        if (l >= L && r <= R)
        {
            int cnt = 0;
            for (auto &val : a[ind])
            {
                if (val.second == k)
                    cnt++;
            }
            return cnt;
        }
        int mid = (l + r) / 2;
        int a1 = search(a, ind * 2, A, l, mid, L, R, k);
        int a2 = search(a, ind * 2 + 1, A, mid + 1, r, L, R, k);
        return (a1 + a2);
    }
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q)
    {
        vector<multimap<int, int>> a(4 * N);
        map<int, int> freq;
        for (auto &val : A)
            freq[val]++;
        build(a, 1, A, 0, A.size() - 1, freq);
        vi ans;
        for (auto &val : Q)
        {
            int L = val[0], R = val[1], k = val[2];
            int u = search(a, 1, A, 0, A.size() - 1, L, R, k);
            ans.pb(u);
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, num;
    cin >> N >> num;
    vector<int> A(N);
    for (auto &val : A)
        cin >> val;
    vvi Q(num, vi(3));
    for (auto &val : Q)
        for (auto &valu : val)
            cin >> valu;
    Solution obj;
    vi res = obj.solveQueries(N, num, A, Q);
    for (auto &val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}