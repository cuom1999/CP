#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define pmod 1000000007
#define maxn (ll) 1e12+5
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

bool comp[1000005];
vector<ll> prime;
ll mob[1000005];
void sieve(ll n){
    mob[1]=1;
    FOR (i,2,n){
        if (comp[i]==0){
            prime.pb(i);
            mob[i]=-1;
        }
        for (ll j=0; j<prime.size() && prime[j] * i<=n;j++){

            comp[i*prime[j]]=1;
            if (i%prime[j]==0){
                mob[i*prime[j]]=0;break;
            }
            else{
                mob[i*prime[j]]=mob[i]*mob[prime[j]];
            }
        }
    }
}
ll f[1000005],d[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //phi[1]=1;
    sieve(1000000);

    FOR (i,1,20){
        cout<<i<<" "<<mob[i]<<endl;
    }

         return 0;
}
