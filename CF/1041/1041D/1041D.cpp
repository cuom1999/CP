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

int n; ll h; 
ll x1[200005],x2[200005];
ll d[200005], val[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>h;
    FOR (i,1,n){
    	cin>>x1[i]>>x2[i];
    }
    x1[n+1]=1e18;
    FOR (i,1,n){
    	d[i]=d[i-1]+x1[i+1]-x2[i];
    	val[i]=val[i-1]+x2[i]-x1[i];
    }

    ll res=0;
    FOR (st,1,n){
    	ll L=st, R=n;
    	while (L<R){
    		ll mid=(L+R)/2;
    		if (d[mid]-d[st-1]>=h){
    			R=mid;
    		}
    		else L=mid+1;
    	}
    	//cout<<L<<endl;
    	res=max(res,val[L]-val[st-1]);
    	//cout<<st<<" "<<val[L]-val[st-1]<<endl;
    }
    cout<<res+h<<endl;
    
	
         return 0;
}