#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double a, b, c;
    cin >> a >> b >> c;
    double no = a * c / 100;
    int d = ceil(no);
    cout << max(0,int (d - b)) << endl;
    return 0;
}