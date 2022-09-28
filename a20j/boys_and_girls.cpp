#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    ofstream g;
    string filename("output.txt");
    g.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    g.close();
    g.open(filename, ios_base::app);
    if (n > k)
    {
        vector<char> v(n + k, 'B');
        int i = k, j = 0;
        while (i--)
        {
            v[j] = 'G';
            j += 2;
        }
        for (auto &val : v)
        {
            g << val;
        }
        g.close();
    }
    else
    {
        vector<char> v(n + k, 'G');
        int i = n, j = 0;
        while (i--)
        {
            v[j] = 'B';
            j += 2;
        }
        for (auto &val : v)
        {
            g << (val);
        }
        g.close();
    }
    return 0;
}