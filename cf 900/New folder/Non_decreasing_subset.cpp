#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        int N,K;
        cin>>N>>K;
        int v[N];
        int lds=0;
        int max=0;
        for (int j = 0; j < N; j++)
        {
            cin>>v[j];
        }
            vector<int> finalseq;
        for (int j = 1; j < N; j++)
        {
            vector<int> seq;
            if(v[j]>v[j-14]){
                while(v[j]>v[j-1]){
                    seq.push_back(v[j-1]);
                    j++;
                }
                lds++;
                if(lds>max){
                    max=lds;
                    finalseq=seq;
                }
            }
        }
        cout<<finalseq.size();
        
    }
    
    return 0;
}