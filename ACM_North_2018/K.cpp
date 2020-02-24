#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int n,m;

ll K , a[1005], b[1005];


ll mul (ll a, ll b, ll K){
    a%=K; b%=K;
    ll res=0;
    while (b){
        res=(res+a*(b%1000))%K;
        b/=1000;
        a=a*1000%K;
        //cout<<res<<" "<<b<<endl;
    }
    if (res<0) res+=K;
    return res;
}


int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>K;
	
	FOR (i,1,n){
		cin>>a[i];
	}
	FOR (i,1,m) {
		cin>>b[i];
	}
	FOR (i,1,n){
		FOR (j,1,m){
			ll u=__gcd(a[i],b[j]);
			a[i]/=u;
			b[j]/=u;
		}
	}
	ll P=1, Q=1;
	FOR (i,1,n){
		P=mul(P,a[i],K);
	}
	FOR (i,1,m){
		Q=mul(Q,b[i],K);
	}
	cout<<P<<endl<<Q<<endl;
         return 0;
}