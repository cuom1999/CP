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
typedef pair < ll, ll > II;

ll a[505];

bool factExp(ll m, ll &a, ll &n){
	ld t=log2(m);
	FORD(i,4,2){
		ld y=t*1.0/i;
		ll u=pow(2,y);
		FOR (j,u-2,u+2){
			ll Prod=1;
			FOR (k,1,i){
				Prod*=j;
			}
			if (Prod==m){
				a=j; n=i;
				return 1;
			}
		}
	}
	a=0;
	n=0;
	return 0;
}

ll b[505];

map<ll,ll> prime;
bool c[505]; 
vector<ll> v;
const ll K=998244353;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i,1,n){
    	cin>>a[i];
    	ll p=0,q=0;
    	bool e=factExp(a[i],p,q);
    	if (e){
    		b[i]=p;
			prime[p]+=q;
			c[i]=1;
    	}
    	else{
    		b[i]=a[i];
    	}
    }
    FOR (i,1,n){
    	if (c[i]) continue;
    	FOR (j,1,n){
    		if (b[j]==b[i]) continue;
    		ll t=__gcd(b[i],b[j]);
    		if (t>1){
    			ll p=b[i]/t;
    			prime[p]++;
    			prime[t]++;
    			c[i]=1;
    			break;
    		}
    	}
    }
    FOR (i,1,n){
    	if (c[i]){
    		continue;
    	}
    	int dem=1;
    	FOR (j,i+1,n){
    		if (b[j]==b[i]){
    			dem++;
    			c[j]=1;
    		}
    	}
    	v.pb(dem+1);
    }
    ll res=1;
    for (auto i:prime){
    	res=(i.second+1)*res%K;
    }
    for (auto i:v){
    	res=(i*i%K)*res%K;
    }
    cout<<res<<endl;



    
	
         return 0;
}