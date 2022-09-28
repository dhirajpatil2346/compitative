#include<bits/stdc++.h>
using namespace std;

int main(){
    int k=23,j=23,l=1,L=1;
    vector<int> a, b, c, d;
        while (k != 0)
        {
            a.push_back(k % 2);
            k = k / 2;
        }
        for (auto it = a.rbegin(); it != a.rend(); it++)
        {
            b.push_back(*it);
        }
        while (l != 0)
        {
            c.push_back(l % 2);
            l = l / 2;
        }
        for (auto itr = c.rbegin(); itr != c.rend(); itr++)
        {
            d.push_back(*itr);
        }
        cout<<(a==b)<<endl;
        cout<<(c==d)<<endl;
        if ((a == b) && (c == d))
        {
            cout << j << " " << L << endl;
            // break;
        }
    return 0;
}