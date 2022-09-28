#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    string s="";
    s=s+to_string()+to_string();
    */
    int N, Q;
    cin >> N >> Q;
    int a[N]; // to store the array of integers
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int query[Q]; // to store the queries
    int maxi = 0;
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        query[i] = max(x, y);
        maxi = max(maxi, query[i]);
    }
    map<string, int> m;
    for (int i = 0; i < maxi; i++)
    {
        unordered_set<int> us;
        for (int j = i; j < maxi; j++)
        {
            string s = "";
            s = s + to_string(i) + to_string(j);
            us.insert(a[j]);
            // arr[i][j] = us.size();
            m[s] = us.size();
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int req = query[i];
        long long sum = 0;
        for (int j = 0; j < req; j++)
        {
            for (int k = j; k < req; k++)
            {
                string s = "";
                s = s + to_string(j) + to_string(k);
                sum += m[s];
            }
        }
        cout << sum << endl;
    }

    return 0;
}