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

ll sqrt2(ll n){
	ll u = sqrt(n);
	ll q=u;
	FOR (i,max(u-5,1LL), u+5){
		if (i>n/i) {
			q=i-1; break;
		}
	}
	return q;
}
vector<II> V;

int comp(ll a, ll b, ll c, ll a1, ll b1, ll c1){
	ll P=(b*b+c*c-a*a)*b1*c1;
	ll Q=(b1*b1+c1*c1-a1*a1)*b*c;
	if (P<Q) return 1;
	return 0;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
	    ll n,P,Q;
	    cin>>n>>P>>Q;
	    FOR (i,1,n){
	    	ll x;
	    	cin>>x;
	    	V.pb(II(x,i));
	    }
	    sort(all(V));
	    int a=0,b=0,c=0;
	    ll A=0,B=0,C=0;
	    ld res=0;
	    for (int i=0; i<V.size(); i++){
	    	for (int j=i+1; j<V.size(); j++){
	    		ll M=sq(V[i].first)+sq(V[j].first);
	    		ll m1 = 2*P*V[i].first*V[j].first;
	    		if (m1==0) m1=0;
	    		else m1=(m1-1)/Q+1;
	    		M-=m1;
	    		if (M<0) continue;
	    		else {
	    			M=sqrt2(M);
	    			int u = lower_bound(all(V),II(M+1,-1))-V.begin()-1;
	    			FORD(k,u,0){
	    				if (k!=i && k!=j){
	    					if (V[k].first>V[j].first-V[i].first){
	    						if ((a+b+c==0) || comp(V[k].first,V[i].first,V[j].first,A,B,C)){
	    							a=V[k].second; b=V[i].second; c=V[j].second;
	    							A=V[k].first; B=V[i].first; C=V[j].first;
	    							res=(sq(C)+sq(B)-sq(A))/2.0/(B*C);
	    						}
	    					}
	    					break;
	    				}
	    			}
	    		}
	    	}
	    }
	    if (a+b+c==0){
	    	cout<<-1<<endl;
	    }
	    else{
	    	cout<<a<<" "<<b<<" "<<c<<endl;
	    	//cout<<fixed<<setprecision(8)<<res<<endl;
	    }
	    V.clear();
	}

    
	
         return 0;
}