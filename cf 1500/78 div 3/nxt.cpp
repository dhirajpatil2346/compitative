#include<bits/stdc++.h>
	using namespace std;
	int main ( )
	{
vector <int> v(4, -1);
int a = 9;
for(auto val:v)
{
	val  = 5 + a;
	a++;
}	
for(auto &val : v)
{	
	cout<<val<<" ";
}
return 0;
}	
