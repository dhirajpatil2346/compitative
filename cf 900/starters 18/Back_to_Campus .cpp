#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N,K;
        cin >> N >> K ;
        if (N % K == 0)
        {
            cout << N / K << endl;
        }
        else
        {
            cout << N / K + 1 << endl;
        }
    }
    return 0;
}