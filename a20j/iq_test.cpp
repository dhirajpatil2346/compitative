#include <bits/stdc++.h>
using namespace std;

bool cal(vector<vector<char>> v1, int i, int j)
{
    int dot = 0, hash = 0;
    (v1[i][j] == '.') ? dot++ : hash++;
    (v1[i][j + 1] == '.') ? dot++ : hash++;
    (v1[i + 1][j] == '.') ? dot++ : hash++;
    (v1[i + 1][j + 1] == '.') ? dot++ : hash++;
    if ((dot == 1 && hash == 3) || (dot == 3 && hash == 1) || dot==4 || hash==4)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<string> v(4);
    for (auto &val : v)
    {
        cin >> val;
    }
    vector<vector<char>> v1(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            v1[i].push_back(v[i][j]);
        }
    }
    /*
    for (auto &val : v1)
    {
        for (auto &valu : val)
        {
            cout << valu;
        }
        cout << endl;
    }
    */
    bool got = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (cal(v1, i, j))
            {
                got = true;
                break;
            }
        }
    }
    if (got)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}