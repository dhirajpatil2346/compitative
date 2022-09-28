#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << n * n << endl;
    }
    else
    {
        long long a = n * n * n;
        long long b = (n - 2) * (n - 2) * (n - 2);
        cout << a - b << endl;
    }
    return 0;
}