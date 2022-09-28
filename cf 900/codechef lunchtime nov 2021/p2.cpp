#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        {
            long long int N, K;
            cin >> N >> K;
            long long int req = 1;
            for (int i = K;;)
            {
                if ((i % N == 0) && (i >= N))
                {
                    break;
                }
                req++;
                i = i + K;
            }
            cout << req << endl;
        }
    }
    return 0;
}