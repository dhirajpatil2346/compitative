#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int log = 1;
    while (n /= 2)
    {
        log++;
    }
    cout << log << endl;
    return 0;
}