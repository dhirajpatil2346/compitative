#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int sm = 0, big = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
            sm = i;
        if (v[i] == n)
            big = i;
    }
    cout << sm << " " << big << endl;
    int step1 = INT_MAX;
    int inif = 0, inib = 0;
    set<int> s1;
    s1.clear();
    for (int i = 0; i < n; i++)
    {
        s1.insert(v[i]);
        if (*s1.rbegin() == (i + 1))
        {
            inif++;
        }
    }
    s1.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        int ele = (n - 1 - i + 1);
        s1.insert(v[i]);
        if (*s1.rbegin() == (ele))
        {
            inib++;
        }
    }
    step1 = min(step1, max(inif, inib));
    auto temp = 0;
    int step2 = INT_MAX, step3 = INT_MAX;
    {
        if (big > 0)
        {
            temp = v[big - 1];
            v[big - 1] = v[sm];
            v[sm] = temp;
            inif = 0, inib = 0;
            s1.clear();
            for (int i = 0; i < n; i++)
            {
                s1.insert(v[i]);
                if (*s1.rbegin() == (i + 1))
                {
                    inif++;
                }
            }
            s1.clear();
            for (int i = n - 1; i >= 0; i--)
            {
                int ele = (n - 1 - i + 1);
                s1.insert(v[i]);
                if (*s1.rbegin() == (ele))
                {
                    inib++;
                }
            }
            step3 = min(step2, max(inif, inib));
            temp = v[big - 1];
            v[big - 1] = v[sm];
            v[sm] = temp;
        }
    }
    {
        if (big < n - 1)
        {
            // cout << big << endl;
            temp = v[big + 1];
            v[big + 1] = v[sm];
            v[sm] = temp;
            inif = 0, inib = 0;
            s1.clear();
            for (int i = 0; i < n; i++)
            {
                s1.insert(v[i]);
                if (*s1.rbegin() == (i + 1))
                {
                    inif++;
                }
            }
            s1.clear();
            for (int i = n - 1; i >= 0; i--)
            {
                int ele = (n - 1 - i + 1);
                s1.insert(v[i]);
                if (*s1.rbegin() == (ele))
                {
                    inib++;
                }
            }
            step3 = min(step3, max(inif, inib));
            temp = v[big + 1];
            v[big + 1] = v[sm];
            v[sm] = temp;
        }
    }
    if (step1 <= min(step2, step3))
    {
        cout << "1 1" << endl;
    }
    else if (step2 <= min(step1, step3))
    {
        cout << sm + 1 << " " << big << endl;
    }
    else
    {
        cout << sm + 1 << " " << big + 2 << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}