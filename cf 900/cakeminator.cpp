#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    unordered_set<int> row;
    unordered_set<int> col;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    cout << n * m - row.size() * col.size() << endl;
    return 0;
}