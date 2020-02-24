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

ld calc(ld a, ld b, ld c){
	return (b*b+c*c-a*a)/2.0/(b*c);
}
ld a[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
    	ll n,P,Q;
    	cin>>n>>P>>Q;
    	ld res=2;
    	FOR (i,1,n) cin>>a[i];
    	FOR (i,1,n){
    		FOR (j,1,n){
    			FOR (k,1,n){
    				if (i==j || i==k || j==k){
    					continue;
    				}

    				ld U=calc(a[i],a[j],a[k]);
    				if (U>=P*1.0/Q && U<1-eps){
    					res=min(res,U);
    				}
    			}
    		}
    	}
    	if (res==2) res=-1;
    	cout<<fixed<<setprecision(8)<<res<<endl;
    }
    
	
         return 0;
}