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
typedef pair < ll, ll > II;

//calculate the n-th digit after point of a/b in base B (a,b,n,B - 10^18)

II div_operation(ll a, ll b, ll c){
	if (b==0) return II(0,0);
	II q=div_operation(a,b/2,c);
	if (b%2==0){
		return II(2*q.first+(2*q.second)/c,(2*q.second)%c);
	}
	return II(2*q.first+(2*q.second+a)/c,(2*q.second+a)%c);
}

ll div(ll a, ll b, ll c) {
	return div_operation(a,b,c).first;
}

ll mul(ll a, ll b, ll k){
	if (b==0) return 0;
	if (b==1) return a%k;
	ll q=mul(a,b/2,k);
	if (b%2==0) return (q+q)%k;
	return (q+q+a)%k; 
}

ll mu(ll a, ll b, ll p){
    if (b==0) return 1%p;
    ll q=mu(a,b/2,p);
    if (b%2==0) return mul(q,q,p);
    return mul(mul(q,q,p),a,p);
}

ll ext_euclid(ll a, ll b, ll &x, ll &y) {
    ll xx=y=0;
    ll yy=x=1;
    while (b){
        ll q=a/b;
        ll t=b; b=a%b; a=t;
        t=xx; xx=x-q*xx; x=t;
        t=yy; yy=y-q*yy; y=t;
    }
    return a;
}

ll inv(ll a, ll b){
	ll x=0,y=0;
	ext_euclid(a,b,x,y);
	x%=b;
	x=(x+b)%b;
	return x;
}

ll solve(ll n, ll a, ll b, ll B){
	ll g=__gcd(a,b);
    a/=g; b/=g;
    ll cnt=0;
    ll temp=b;
    vector<ll> P;
    	
    while (1){
    	ll q=__gcd(b,B);
    	if (q==1) break;
    	b/=q;
    	P.pb(B/q);
    	cnt++;
    }
    swap(b,temp);
    if (n<=cnt){
    	a%=b;
        FOR (i,1,n-1){
            a=mul(a,B,b);
        }
        return div(a,B,b);
    }
    else{
    	b=temp;
    	a%=b;
    	ll prod=1;
    	for (auto i:P) prod=mul(prod,i,b); 
    	a=mul(a,prod,b);
    	ll r=mul(a, mu(B,n-cnt,b), b);
    	
    	ll u=b%B;
    	
    	u=inv(u,B);
    	r=mul(r,u,B);
    	r=-r;
    	r=(r+B)%B;
    	return r;
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    ll a,b;
    cin>>n>>a>>b;
    ll B=10;
    FOR (i,1,15) cout<<solve(i,7,75,12)<<" ";
		
         return 0;
}