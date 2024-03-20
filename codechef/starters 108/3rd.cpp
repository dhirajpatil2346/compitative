#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string is_fair_distribution(int N, const string &S)
{
    int ones_count = 0;
    int zeros_count = 0;

    for (int i = 0; i < N; ++i)
    {
        if (S[i] == '1')
        {
            ones_count--;
        }
        else
        {
            zeros_count--;
        }

        if (abs(ones_count - zeros_count) > (S[i] - '0'))
        {
            return "NO";
        }
    }

    return "YES";
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;

        string S;
        cin >> S;

        string result = is_fair_distribution(N, S);
        cout << result << endl;
    }

    return 0;
}
