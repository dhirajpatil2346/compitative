#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<int> q;
    int n;
    cin >> n;
    int s1 = 0, s2 = 0;
    bool turn = true;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if (turn)
        {
            if (q.front() >= q.back())
            {
                s1 += q.front();
                q.pop_front();
            }
            else
            {
                s1 += q.back();
                q.pop_back();
            }
        }
        else
        {
            if (q.front() >= q.back())
            {
                s2 += q.front();
                q.pop_front();
            }
            else
            {
                s2 += q.back();
                q.pop_back();
            }
        }
        turn = !turn;
    }
    cout << s1 << " " << s2 << endl;
    return 0;
}