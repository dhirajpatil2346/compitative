#include<bits/stdc++.h>
using namespace std;

string itb(int N)
{
    long long B_Number = 0;
    int cnt = 0;
    while (N != 0) {
        int rem = N % 2;
        long long c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
        // Count used to store exponent value
        cnt++;
    }
    string s = to_string(B_Number);
    return s;
}


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    vector<int> v(m+1);
    vector<string> bin(m+1);
    for(auto &val:v)
    {
        cin>>val;
    }
    for(int i = 0 ; i < m+1 ; i++)
    {
        bin[i] = itb(v[i]);
        cout<<v[i]<<"   "<<bin[i]<<endl;
    }
    string par = bin[m];
    int p1 = 0;
    for(auto &val:par)
    {
        p1 += (val=='1')?1:0;
    }

    for(int i = 0 ; i < m ; i++)
    {
        cout<<i<<endl;
        int curr=0;
        int mini = min(par.length(), bin[i].length());
        int j = par.length()-1, x= bin[i].length()-1;
        while(mini--)
        {
            if(bin[i][j]!=par[k])
            {
                curr++;
            }
            j--,x--;
        }
        if(curr <= k)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}