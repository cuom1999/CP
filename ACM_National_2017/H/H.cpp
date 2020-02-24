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

ll a[1005], b[1004];


const ll K=1e9+7;

ll mu(ll a, ll n){
	if (n==0) {
		return 1;
	}
	ll q=mu(a,n/2);
	if (n%2==0) return q*q%K;
	return q*q%K*a%K;
}

vector<ll> V,U;
ll mu2[105], rev[105];
int n;

ll calc(){
	FOR (i,1,n) b[i]=a[i];
	ll res=0;
	FORD (k,63,0){
		V.clear();
		U.clear();
		FOR (i,1,n){
			if (b[i]&(1LL<<k)){
				V.pb(b[i]);
			}
			else{
				U.pb(b[i]);
			}
		}
		int N=V.size();

		ll f1=1;
		ll g1=1;
		ll u=1;

		for (auto i:V){
			f1=f1*(i%K+1)%K;
			g1=g1*(mu2[k+1]-i%K-1+K)%K;
		}
		for (auto i:U){
			u=u*(i%K+1)%K;
		}

		ll Q=(f1+g1)*rev[1]%K;

		if (N%2==0){
			ll P=1;
			for (auto i:V){
				P=P*(i%K+1-mu2[k]+K)%K;
			}

			Q=(Q-P+K)%K*u%K*rev[k]%K;
			
			res=(res+Q)%K;

			FOR (i,1,n){
				if (b[i]&(1LL<<k)){
					b[i]-=(1LL<<k);
				}
			}
		}
		else{
			Q=Q*u%K*rev[k]%K;
			res=(res+Q)%K;
			return res;
		}
	}
	res=(res+1)%K;
	return res;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	mu2[0]=1;
	rev[0]=1;
	FOR (i,1,100){
		mu2[i]=mu2[i-1]*2ll%K;
		rev[i]=mu(mu2[i],K-2);
	}

	cin>>n;
	FOR (i,1,n){
		cin>>a[i];
	}
	ll res=calc();
	FOR (i,1,n) a[i]--;
	
	FOR (i,1,n){
		a[i]++;
		res=(res-calc()+K)%K;
		a[i]--;
	}
	res=(res+(n-1)*1ll*calc()%K)%K;

	cout<<res<<endl;
	
	return 0;
}