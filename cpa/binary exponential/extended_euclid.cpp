// C++ program to demonstrate working of
// extended Euclidean Algorithm
#include <bits/stdc++.h>
using namespace std;

// Function for extended Euclidean Algorithm
int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Driver Code
int main()
{
    int x, y, a = 35, b = 15;
    int g = gcd(a, b, x, y);
    cout << x << " " << y << endl;
    cout << "GCD(" << a << ", " << b
         << ") = " << g << endl;
    return 0;
}
