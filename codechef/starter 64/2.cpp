#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n=s.length();
	    for(int i = 1 ; i < n ; i++)
	    {
	        if(s[i]=='1' && s[i-1]=='0')
	        {
	            f++;
	        }
	        if(s[i]=='0' && s[i-1]=='1')
	        {
	            f1++;
	        }
	    }
	    int ans=0;
	    for(int i = 0 ; i < n ; i++)
	    {
	        int c = f,c1=f1;
	        if(i==0)
	        {
	            if(s[i]=='0')
	            {
	                if(s[i+1]=='1')
	                {
	                    c1--;
	                }
	                else
	                {
	                    c++;
	                }
	            }
	            else if(s[i]=='1')
	            {
	                if(s[i-1]=='0')
	                {
	                    c--;
	                }
	                else
	                {
	                    c1++;
	                }
	            }
	            if(c==c1)
	            {
	                ans++;
	            }
	        }
	        else if(i== (n-1))
	        {
	            if(s[i]=='0')
	            {
	                if(s[i-1]=='1')
	                {
	                    c1--;
	                }
	                else
	                {
	                    c++;
	                }
	            }
	            else if(s[i]=='1')
	            {
	                if(s[i-1]=='0')
	                {
	                    c--;
	                }
	                else
	                {
	                    c1++;
	                }
	            }
	            if(c==c1)
	            {
	                ans++;
	            }
	        }
	        else if(s[i]=='1')
	        {
	            
	        }
	        else
	        {
	            
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

