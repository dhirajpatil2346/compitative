#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double d, s1, s2, m, n, x, y;
    cin >> d >> s1 >> s2 >> m >> n >> x >> y;
    double t1 = d / s1 + m * x;
    double t2 = d / s2 + n * y;
    if (t1 == t2)
    {
        cout << "The perfect date" << endl;
    }
    else if (t1 < t2)
    {
        cout << "Darshan" << endl;
    }
    else
    {
        cout << "Crush" << endl;
    }

    return 0;
}