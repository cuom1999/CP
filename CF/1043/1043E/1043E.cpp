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

struct data {
	ll x,y,i;
	data(ll _x=0, ll _y=0, ll _i=0){
		x=_x; y=_y; i=_i;
	}
	bool operator < (data u){
		return x-y<u.x-u.y;
	}
};
vector<data> V;
ll res[300005];
data a[300005];
int pos[300005];
ll Sx[300005], Sy[300005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    FOR (i,1,n){
    	ll x,y;
    	cin>>x>>y;
    	V.pb(data(x,y,i));
    	a[i] = data(x,y,i);
    }
    sort(all(V));
    Sx[0]=V[0].x;
    FOR (i,1,n-1){
    	Sx[i]=Sx[i-1]+V[i].x;
    }
    Sy[n-1]=V[n-1].y;
    FORD(i,n-2,0){
    	Sy[i]=Sy[i+1]+V[i].y;
    }
    for (int i=0; i<V.size(); i++){
    	res[V[i].i]=V[i].y*1ll*i+V[i].x*1ll*(n-i-1) ;
    	if (i){
    		res[V[i].i]+=Sx[i-1];
    	}
    	res[V[i].i]+=Sy[i+1];

    	pos[V[i].i]=i;
    }
    FOR (i,1,m){
    	int u,v;
    	cin>>u>>v;
    	if (pos[u]<pos[v]){
    		ll s=a[u].x+a[v].y;
    		res[u]-=s;
    		res[v]-=s;
    	}
    	else{
    		ll s=a[u].y+a[v].x;
    		res[u]-=s;
    		res[v]-=s;
    	}
    }
    FOR (i,1,n) cout<<res[i]<<" ";

    
	
         return 0;
}