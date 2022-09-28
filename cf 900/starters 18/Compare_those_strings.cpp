#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int T;
    cin >> T;
    for (long long int j = 0; j < T; j++)
    {
        long long int N;
        cin >> N;
        // N--;
        string A, B;
        cin >> A >> B;
        for(unsigned long long i=0; i<N;i++){
            if(A[i]<B[i]){
                cout<<i+1<<endl;
                break;
            }
        }
        // cout<<max<<endl;
    }
    return 0;
}