#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        vector<long long> response, vec;
        long long scr = 0;
        for (long long i = 0; i < n; i++)
        {
            if (s[i] == 'R')
            {
                scr += (n - i - 1);
            }
            else
            {
                scr += i;
            }
            if (i < (n - i - 1) && s[i] == 'L')
            {
                vec.push_back(n - 1 - i - i);
            }
            else if (i > (n - i - 1) && s[i] == 'R')
            {
                vec.push_back(i + i + 1 - n);
            }
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        
        long long ans = 0;
        long long m = vec.size();
        for (long long i = 0; i < m; i++)
        {
            ans += vec[i];
            response.push_back(scr + ans);
        }
        for (long long i = m; i < n; i++)
        {
            response.push_back(scr + ans);
        }
        for (long long i = 0; i < response.size(); i++)
        {
            cout << response[i] << " ";
        }
        cout << endl;
    }
    return 0;
}