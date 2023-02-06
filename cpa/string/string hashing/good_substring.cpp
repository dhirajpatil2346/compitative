#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL m = 1e9 + 7;

LL binpow(LL a, LL b)
{
    a %= m;
    if (b == 0)
    {
        return 1;
    }
    LL res = binpow(a, b / 2);
    if (b % 2)
    {
        return (((res * 1ll * res) % m) * (1ll * a)) % m;
    }
    return (res * 1ll * res) % m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    string s1;
    cin >> s1;
    int k;
    cin >> k;
    map<char, bool> ms;
    map<int, bool> vis;
    for (int i = 0; i < 26; i++)
    {
        if (s1[i] == '1')
        {
            ms[i + 'a'] = true;
        }
        else
        {
            ms[i + 'a'] = false;
        }
    }
    set<LL> st;
    set<pair<LL, LL>> st1;
    LL curr = 0;
    queue<int> q;
    q.push(-1);
    int j = 0;
    int f = 0;
    while (j < s.length() && !q.empty())
    {
        int start;
        start = q.front() + 1;
        q.pop();
        cout << "start is : " << start << endl;
        int diff = j - start;
        curr /= binpow(31, diff);
        // cout << " " << curr << endl;
        j = start;
        f = 0;
        while (j < s.length())
        {
            cout << "j is : " << j << endl;
            cout << "f is : " << f << endl;
            diff = j - start;
            LL M = (binpow(31, start - j));
            // cout << M << endl;
            curr += ((M * 1ll * (s[j] - 'a' + 1)) % m);
            cout << j << " " << curr << endl;
            if (ms[s[j]])
            {
            }
            else
            {
                f++;
                if (!vis[j])
                {
                    q.push(j);
                }
                vis[j] = true;
            }
            if (f <= k)
            {
                cout << "inserted into -->  " << start << " " << j << endl;
                int z = st.size();
                st.insert(curr);
                if(z!=st.size())
                st1.insert({start, j});
                j++;
            }
            if (f > k)
            {
                j++;
                f--;
                break;
            }
        }
    }
    cout << "the size is" << st.size() << endl;
    for (auto &val : st1)
    {
        cout <<"{ "<< val.first<<" "<<val.second <<" }"<< " ";
    }
    cout << endl;
    return 0;
}
/*
a,ac,c,cb,b,ba,a,ac,ca
*/