#include<bits/stdc++.h>
using namespace std;
#define ll int
#define INF 999999999999999999
#define MAXN 100005

vector<ll> phi(MAXN,0);
vector<bool> prime2(40001,false);
vector<ll> sum(MAXN,0),prime;
vector<ll> depth(MAXN,0);
ll N;

bool isPrime(ll n)
{
    if(n==1)return false;
    ll sq = sqrt(n);
    ll sz = prime.size();
    for(int i=0;i<sz && prime[i]<=sq;i++)
        if(n%prime[i]==0)
            return false;
    return true;
}

void seive_phi()
{
    for(ll i=1;i<=N;++i)
        cin>>phi[i];

    for(ll i=1;i<=N;++i)
    {
        ll result=phi[i];
        ll n=phi[i];
        for(ll j=2;j*j<=n;j++)
        {
            if(n%j==0)
            {
                while(n%j==0)
                    n/=j;

                result=result-(result/j);
            }
        }

        if(n>1)
            result-=result/n;

        phi[i]=result;
    }

    for(ll i=1;i<=N;++i)
        if(isPrime(phi[i]))
            sum[i]=1;

    for(ll i=1;i<=N;++i)
    {
        sum[i]=sum[i-1]+sum[i];
    }    

    return ;
}

void sieve()
{
    ll M=40001;
    for(ll i=4;i<M;i+=2)
        prime2[i]=true;

    for(ll i=3;i*i<M;i+=2)
    {
        if(!prime2[i])
        {
            for(ll j=i*i;j<M;j+=i)
            {
                prime2[j]=true;
            }
        }
    }
    
    prime.push_back(2);
    for(ll i=3;i<M;i+=2)
    {
        if(!prime2[i])
        {
            prime.push_back(i);
        }
    }

    return ;
}

void solve()
{
    ll i,j,k,n,m;
    cin>>N>>n;
    sieve();
    seive_phi();
    cout<<prime.size()<<endl;
    // for(i=1;i<=3;++i)
    //     cout<<"node: "<<i<<" phi: "<<phi[i]<<" prime: "<<prime[i]<<endl;


    for(i=0;i<n;++i)
    {
        ll a,b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<endl;
    }
    return ;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll i,j,k,n,m,t;
    solve();
    return 0;
}