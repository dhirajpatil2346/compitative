#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n * n + 1);
    for (int i = 0; i < n * n + 1; i++)
    {
        v[i] = i;
    }
    int i = 1, j;
    vector<int> v1, v2;
    while (i < n * n + 1)
    {
        v1.push_back(i);
        v1.push_back(i + 3);
        v2.push_back(i + 1);
        v2.push_back(i + 2);
        i += 4;
    }
    /*
    for (auto &val : v1)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto &val : v2)
    {
        cout << val << " ";
    }
    cout << endl;
    */
        i = 0,
        j = 0;
    while (i < v1.size() && j < v2.size())
    {
        while (i < v1.size())
        {
            cout << v1[i] << " ";
            i++;
            if (i % n == 0)
            {
                cout << endl;
                break;
            }
        }
        while (j < v2.size())
        {
            cout << v2[j] << " ";
            j++;
            if (j % n == 0)
            {
                cout << endl;
                break;
            }
        }
    }
    return 0;
}