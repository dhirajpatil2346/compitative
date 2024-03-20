#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    c *= 1000;
    int maxi = c / a, mini = c / b + min(1, c % b);
    cout << mini << " " << maxi << endl;
    cout << floor(4.5) << endl;
    return 0;
}