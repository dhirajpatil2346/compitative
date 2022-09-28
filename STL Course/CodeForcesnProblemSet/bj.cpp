#include<iostream>
using namespace std;
template<class T> 
int volume (T x, T z, T y){
    return x*y*z;
}
int main(){
    float x=10.1, y=12.1, z=12.7;
    cout<<volume(10,12,12);
    cout<<volume(10.1,12,12);
}