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

// end of Sektor_jr template v2.0.3 (BETA)

void p(int sc, int par, vector<bool> &vis, vvi &v, vi &parent)
{
    if (vis[sc])
        return;
    vis[sc] = true;
    parent[sc] = par;
    for (auto &val : v[sc])
        p(val, sc, vis, v, parent);
}

int dfs(int sc, vvi &v, vector<bool> &vis)
{
    if (vis[sc])
        return 0;
    vis[sc] = true;
    int k = 0;
    for (auto &val : v[sc])
        k += dfs(val, v, vis);
    return k + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vi par(n + 1, -1);
        vvi v(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }
        vector<bool> vis1(n + 1, false);
        p(1, -1, vis1, v, par);
        vector<bool> cant(n + 1, false);
        int b = k;
        while (b != -1)
        {
            cant[b] = true;
            b = par[b];
        }
        int ini = 1;
        int j = 0;
        for (auto &val : v[k])
        {
            int h = dfs(val, v, cant);
            if (h >= 1)
                j++;
            if (h >= 1)
                ini += (h - 1);
        }
        int root = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!cant[i])
                root++;
        }
        ini += min(1, j);
        cout << ini << " " << root << endl;
        int m = 0;
        if (ini == 1)
        {
            cout << "Ayush" << endl;
            continue;
        }
        else
        {
            m = ini + root;
            m %= 2;
        }
        if (m != 0)
        {
            cout << "Ayush" << endl;
        }
        else
        {
            cout << "Ashish" << endl;
        }
    }
    return 0;
}
/*
5 5
4 5
4 2
3 5
4 1

n = 5 k = 5
1 - 4
4 - 2 5
5 - 3

    1
    |
    4
   /  \
  2     5
         |
         3

*/
/*
n=6
k=4
1 - 6 3
6 - 4 5
3 - 2



k = 4
3 - 5
1 - 2 4 6
6 - 5

        1
      /  |  \
    2    4   6
              |
              5
*/
/*
10

6 4
3 2
1 6
4 6
6 5
1 3


6 4
3 5
1 2
6 5
4 1
6 1


6 3
6 2
3 1
4 6
1 6
3 5


5 5
4 5
4 2
3 5
4 1


4 1
1 3
2 1
4 1


4 2
1 2
3 2
4 1


6 6
3 4
5 6
1 3
6 2
3 5


3 1
1 2
1 3


3 1
3 1
2 1


3 2
2 1
2 3


*/