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

/* Min sum m*a_i^2+n*a_i, m,n double <=50
	sum a_i=C */

const int MAXN=200005;

ld m[MAXN], n[MAXN];

ld d[200005], g[200005];
inline ld calc (int i, ll x){
	return m[i]*x*x+n[i]*x;
}
int p[2005][20005];
ll res[200005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N;
    ll C;
    cin>>N>>C;
    
    FOR (i,1,N){
    	cin>>m[i]>>n[i];
    }

    for (int i=1; i<=N; i++){
    	if (i==1){
    		FOR (j,1,C){
    			d[j]=m[1]*j*j+n[1]*j;
    			p[i][j]=j;
    		}
    	}
    	else{
    		FOR (j,0,C) g[j]=d[j];
    		FOR (j,1,C){
    			FOR (k,1,j){
    				//d[j]=min(d[j],g[j-k]+calc(i,k));
    				ld T=g[j-k]+calc(i,k);
    				if (d[j]>T){
    					d[j]=T;
    					p[i][j]=k;
    				}
    			}
    		}
    	}
    }
    int i=N, c=C;
    while (i){
    	res[i]=p[i][c];
    	c-=p[i][c];
    	i--;
    }
    FOR (i,1,N) cout<<res[i]<<" ";cout<<endl;
    //cout<<fixed<<setprecision(8)<<d[C]<<endl;
	ld R=0;
    FOR (i,1,N) {
    	R+=res[i]*res[i]*m[i]+res[i]*n[i];
    }
	cout<<fixed<<setprecision(20)<<R<<endl;


	
         return 0;
}