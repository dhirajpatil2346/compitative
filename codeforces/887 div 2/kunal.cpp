#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void squarePatternPrint(int n)
{
    int last = n * n;
    vector<string> ans;
    long long p = 1;
    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            string l = to_string(p);
            p++;
            s += l;
            s.push_back('*');
        }
        s.pop_back();
        ans.push_back(s);
    }
    vector<string> vec1, vec2;
    for (int i = 0; i < ans.size(); i += 2)
    {
        vec1.push_back(ans[i]);
        vec2.push_back(ans[i + 1]);
    }
    reverse(vec2.begin(), vec2.end());
    for (auto &val : vec1)
        cout << val << endl;
    for (auto &val : vec2)
        cout << val << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    squarePatternPrint(n);
    return 0;
}