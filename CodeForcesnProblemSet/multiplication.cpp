#include<iostream>
#include<vector>
#include<string>
using namespace std;

string multi(){
    string s1 = "1000000000000000000";
    string s2 = "10000000000000000";
    int len1= s1.size();
    int len2= s2.size();
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2=0;
    for (int i = len1-1; i >= 0 ; i--)
    {
        int carry = 0;
        int n1 = s1[i] - '0';
        i_n2=0;
        for (int j = len2-1; j >= 0; j--)
        {
            int n2 = s2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0){
            result[i_n1+i_n2] += carry;
        }
        i_n1++;
    }
    int m = result.size() - 1;
    while(m >=0 && result[m] == 0){
        m--;
    }
    string s="";
    while (m >= 0){
        s += to_string(result[m--]);
    }
    return s;
    
}
int main(){
    cout<<multi();
    return 0;
}