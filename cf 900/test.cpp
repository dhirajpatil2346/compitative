#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int count=0;
    // cin>>count;
    for (int i = 0; i < s.length()-3; i++)
    {
        if(s[i]==s[i+1] && s[i]==s[i+2]){
            if(count%2==0){
                cout<<"DA"<<endl;
                break;
            }
            else{
                cout<<"NET"<<endl;
            }
        }
        else if(s[i] != s[i+1]){
            i++;
            count++;
        }
        else{
            i++;
            count++;
        }
    }
    
    return 0;
}