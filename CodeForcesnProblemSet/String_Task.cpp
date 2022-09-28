#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<char> d;
    unordered_set<char> e;
    e={'a','e', 'i', 'o', 'u', 'y' ,'Y','A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < s.length(); i++)
    {
        if(e.find(s[i]) != e.end()){}
        else if(s[i] == 'B')
        {
            d.push_back('.');
            d.push_back('b');
        }
        else if(s[i] == 'C')
        {
            d.push_back('.');
            d.push_back('c');
        }
        else if(s[i] == 'D')
        {
            d.push_back('.');
            d.push_back('d');
        }
        else if(s[i] == 'F')
        {
            d.push_back('.');
            d.push_back('f');
        }
        else if(s[i] == 'G')
        {
            d.push_back('.');
            d.push_back('g');
        }
        else if(s[i] == 'H')
        {
            d.push_back('.');
            d.push_back('h');
        }
        else if(s[i] == 'J')
        {
            d.push_back('.');
            d.push_back('j');
        }
        else if(s[i] == 'K')
        {
            d.push_back('.');
            d.push_back('k');
        }
        else if(s[i] == 'L')
        {
            d.push_back('.');
            d.push_back('l');
        }
        else if(s[i] == 'M')
        {
            d.push_back('.');
            d.push_back('m');
        }
        else if(s[i] == 'N')
        {
            d.push_back('.');
            d.push_back('n');
        }
        else if(s[i] == 'P')
        {
            d.push_back('.');
            d.push_back('p');
        }
        else if(s[i] == 'Q')
        {
            d.push_back('.');
            d.push_back('q');
        }
        else if(s[i] == 'R')
        {
            d.push_back('.');
            d.push_back('r');
        }
        else if(s[i] == 'S')
        {
            d.push_back('.');
            d.push_back('s');
        }
        else if(s[i] == 'T')
        {
            d.push_back('.');
            d.push_back('t');
        }
        else if(s[i] == 'V')
        {
            d.push_back('.');
            d.push_back('v');
        }
        else if(s[i] == 'W')
        {
            d.push_back('.');
            d.push_back('w');
        }
        else if(s[i] == 'X')
        {
            d.push_back('.');
            d.push_back('x');
        }
        else if(s[i] == 'Z')
        {
            d.push_back('.');
            d.push_back('z');
        }
        else{
            d.push_back('.');
            d.push_back(s[i]);
        }
    }
    for (int i = 0; i < d.size(); i++)
    {
        /* code */
        cout<<d[i];
    }
    
    return 0;
}