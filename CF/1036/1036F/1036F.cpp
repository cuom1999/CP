#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
#define FORD(i,a,b) for(ll i=a ; i>=b ; i--)
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

set<ll> S;

bool checkScp(ll n){
	ll t= sqrt(n);
	FOR (i,t-2,t+2){
		if (i*i==n){
			return 1;
		}
	}
	return 0;
}

const ll K=1e9+7;

ll mu(ll a, ll n){
	if (n==0) return 1;
	ll q=mu(a,n/2);
	if (n%2==0) return q*q;
	return q*q*a;
}

ll mu1(ll a, ll n){
	if (n==0) return 1;
	ll q=mu1(a,n/2);
	if (n%2==0) return q*q%K;
	return q*q%K*a%K;
}

ll calc (ll n){
	ll t=sqrt(n);
	ll res=0;
	FOR (k,max(t-2,1LL),t+2){
		if (k<=n/k) res=k;
	}
	return res-1;
}

vector<ll> V;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (i,3,59){
 		FOR (a,2,1000000){
 			ll T=mu(a,i);
 			if (T%K==mu1(a,i)){
 				if (!checkScp(T)) S.insert(T);
 			}
 			else break;
 		} 
 	}   
	
	for (auto i:S) V.pb(i);
	//FOR (i,1,20) cout<<calc(i)<<" ";	
	int q;
	cin>>q;
	FOR (z,1,q){
		ll n;
		cin>>n;
		cout<<n-1-(ll) (upper_bound(all(V),n)-V.begin())-calc(n)<<endl;
	}
	     return 0;
}