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


ll mul (ll a, ll b, ll K){
    a%=K; b%=K;
    ll res=0;
    while (b){
        res=(res+a*(b%1000))%K;
        b/=1000;
        a=a*1000%K;
    }
    if (res<0) res+=K;
    return res;
}

ll mu(ll a, ll n, ll m){
    if (n==0) return 1%m;
    ll q=mu(a,n/2,m);
    if (n%2==0) return mul(q,q,m);
    return mul(mul(q,q,m),a,m);
}

ll n;

ll x;
vector<ll> v;

inline ll phi(ll t){ 
	ll res=t;
	for (ll j=2; j*j<=t; j++) { 
		if (t%j==0) { 
			res=res-res/j;
			while (t%j==0) t/=j;
		}
	}
	if (t>1){
		res=res-res/t; 
	}
	return res;
}

ll S;

ll solve (ll m) {
	v.clear();
	ll t=S;
	for (ll i=2; i*i<=t; i++) { 
		if (t%i==0) { 
			v.pb(i);
			while (t%i==0) t/=i;
		}
	}
	if (t>1){ 
		v.pb(t);
	}
	t=S;
	for (auto j:v){ 
		while (t%j==0 && mu(x,t/j,m)==1){ 
			t/=j;
		}
	}
	return t;
}




int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>x;
    if (x==1){ 
    	cout<<n;
    	return 0;
    }
    ll res=1;
    for (ll i=1; i*i<=n; i++){ 
    	if (n%i==0){ 
    		if (i*i==n) { 
    			S=phi(i);
    			res+=S/solve(i);
    		}
    		else { 
    			if (i>1) {
    				S=phi(i);
    				res+=S/solve(i);
    			}
    			S=phi(n/i);
    			res+=S/solve(n/i);
    		}
    	}
    }
    
	cout<<res<<endl;
	

	
         return 0;
}