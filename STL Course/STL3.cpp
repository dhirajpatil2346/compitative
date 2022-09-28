#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    cout << "size : " << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        // v.size() ->O(1)
        cout << v[i]<<" ";;
    }
    // v.push_back(2);
    cout << endl;
}

int main()
{
    /*
    vector<pair<int, int> > v = {{1, 2}, {2,3}, {4,5}};
    printVec(v);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        // v.size() ->O(1)
        int x, y;
        cin>>x >>y;
        v.push_back(make_pair(x,y));
    }
    printVec(v);
    */
   /*
    int N;
    cin >> N;
    vector<int> v[N];
    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < N; ++i)
    {
        printVec(v[i]);
    }
    cout<<v[0][0];
    */

    int N;
    cin >> N;
    vector<vector<int> > v;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    for (int i = 0; i < v.size(); ++i)
    {
        printVec(v[i]);
    }
    cout<<v[0][1];

    return 0;
}