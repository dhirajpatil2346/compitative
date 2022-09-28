#include <bits/stdc++.h>
using namespace std;

struct query
{
    int l, r, sol;
};

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    int arr[n][2];
    map<int, vector<int>> m;
    map<pair<int,int>,int> sol;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        m[arr[i][0]].push_back(arr[i][1]);
    }
    for (auto &val : m)
    {
        int start = val.first;
        for (int i = 0; i < val.second.size(); i++)
        {
            int curr = 0;
            int end = val.second[i];
            for (int j = start - 1; j < end - 1; j++)
            {
                if (s[j] == s[j + 1])
                {
                    curr++;
                }
            }
            sol[{start,end}]=curr;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = arr[i][0],k=arr[i][1];
        cout<<sol[{j,k}]<<endl;
    }
    
    return 0;
}