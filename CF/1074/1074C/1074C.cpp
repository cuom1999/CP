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

int x[300005], y[300005];
int abs(int n){
	if (n<0) n=-n;
	return n;
}

ll calc (int i, int j, int k){
	return abs(x[i]-x[j])+abs(y[i]-y[j])+abs(x[i]-x[k])+abs(y[i]-y[k])+abs(x[j]-x[k])+abs(y[j]-y[k]); 
}
vector<int> V;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    int maxX=-INF, minX=INF, maxY=-INF, minY=INF;

    FOR (i,1,n){
    	cin>>x[i]>>y[i];
    	maxX=max(maxX,x[i]);
    	minX=min(minX,x[i]);
    	maxY=max(maxY,y[i]);
    	minY=min(minY,y[i]);
    }
    ll Res=2ll*(maxX-minX+maxY-minY);
    FOR (i,1,n){
    	if (x[i]==maxX || x[i]==minX || y[i]==maxY || y[i]==minY){
    		V.pb(i);
    	}
    }
    ll R3=0;
    for (int i=0; i<V.size(); i++){
    	for (int j=i+1; j<V.size(); j++){
    		int u=V[i];
    		int v=V[j];
    		FOR (k,1,n){
    			if (k!=u && k!=v){
    				R3=max(R3,calc(u,v,k));
    			}
    		}
    	}
    }
    cout<<R3<<" ";
    FOR (i,4,n) cout<<Res<<" "; cout<<endl;
	    
	
        return 0;
}