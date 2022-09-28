#include <iostream>
using namespace std;

int main(){
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        long long int a, b, c;
        cin>>a>>b>>c;
        long long int highest = 0;
        if(a >= highest)
        {
            highest = a;
        }
        if((b> a) && (b > highest))
        { 
            highest = b;
        }
        if((c > a) && (c > b) && (c >= highest))
        {
            highest = c;
        }
        if (a != b || a != c){
            if(a == highest){
                cout<<0<<" ";
            }
            else{
                cout<<highest - a + 1<<" ";
            }
            if(b == highest){
                cout<<0<<" ";
            }
            else{
                cout<<highest - b + 1<<" ";
            }
            if(c == highest){
                cout<<0;
            }
            else{
                cout<<highest - c + 1;
            }
        }
        else {
            cout<<a + 1<<" "<<b + 1<<" "<<c + 1;
        }
        if(i < m-1)
            cout<<endl;
    }
    
    return 0;
}