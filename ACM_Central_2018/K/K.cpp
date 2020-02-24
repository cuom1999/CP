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
typedef pair < ll, ll > II;

const ll K=1e9+7;

ll n,m,k;

// (a+bi)^n
II mu_i(ll a, ll b, ll n){
	if (n==0) return II(1,0);
	II q=mu_i(a,b,n/2);

	ll u=(q.first*q.first-q.second*q.second)%K;
	u=(u+K)%K;
	ll v=2*q.first*q.second%K;
	
	if (n%2==0){
		return II(u,v);
	}
	else{
		ll u1 = (u*a - b*v)%K;
		u1= (u1+K)%K;
		ll v1 = (a*v+b*u)%K;
		return II(u1,v1);
	}
}

ll mu(ll a, ll b, ll n){
    a=(a%K+K)%K;
    b=(b%K+K)%K;
	return mu_i(a,b,n).first;
}

ll gt[1005], rev[1005];

ll i2,s3=82062379;

ll min(ll a, ll b){
	if (a<b) return a;
	return b;
}

ll max(ll a, ll b){
	if (a>b) return a;
	return b;
}

ll Combi(ll n, ll k){
	if (k>n || k<0) return 0;
	return gt[n]*rev[k]%K*rev[n-k]%K;
}

ll e[105][105];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    gt[0]=1; rev[0]=1;
    FOR(i,1,1000){
    	gt[i]=gt[i-1]*1ll*i%K;
    	rev[i]=mu(gt[i],0,K-2);
    }
    i2=rev[2];
    ll i3=mu(3,0,K-2);

    cin>>n>>m>>k;

    if (k==1){
    	cout<<mu(m,0,n)<<endl;
    }
    else if (k==2){
    	ll res=0;
    	FOR (a,0,m){
    		ll b=m-a;
    		ll u=gt[m]*rev[a]%K*rev[b]%K;
    		res=(res+u*mu(a-b,0,n)%K)%K;
    	}
    	res=res*mu(rev[2],0,m)%K;
    	cout<<res<<endl;
    }
    else if (k==3){
    	ll res=0;
    	FOR(a,0,m){
    		FOR (b,0,m){
    			ll c=m-a-b;
    			if (c<0) break;
    			ll u=(a-b*i2%K-c*i2%K)%K;
    			u=(u+K)%K;
    			ll v=s3*i2%K*(b-c)%K;
    			v=(v%K+K)%K;
    			res=(res+mu(u,v,n)*gt[m]%K*rev[a]%K*rev[b]%K*rev[c]%K)%K;
    		}
    	}
    	res=res*mu(i3,0,m)%K;
    	cout<<res<<endl;
    }
    else if (k==4){
    	ll res=0;
        
    	FOR (u,-m,m){
    		FOR (v,-m,m){
    			if ((u+v+m)%2) continue;
    			ll T=(u+v+m)/2;
    			res=(res+Combi(m,T-u-v)*Combi(m,T-u)%K*mu(u,v,n)%K)%K;
    		}
    	}
    	res=res*mu(i2,0,2*m)%K;
    	cout<<res<<endl;
    }
    
	
         return 0;
}