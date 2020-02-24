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

ll C2(ll n){
	return n*(n-1)/2;
}
ll a[205], b[205];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    FOR (z,1,t){
	    ll n,m,x,y;
		cin>>n>>m>>x>>y;    
	    
	    ll res=(m-1)*C2(n)+(n-1)*C2(m)+C2(x-1)+C2(n-x)+C2(y-1)+C2(m-y);
	    ll a1=0,a2=0;	
	    ll b1=0, b2=0;
	 	FOR (i,1,n){
	 		FOR (j,1,m){
	 			a[i+j]++;
	 			if (i+j==x+y){
	 				if (i<x){a1++;}
	 				if (i>x){a2++;}
	 			}
	 			b[i-j+100]++;
	 			if (i-j==x-y){
	 				if (i<x) b1++;
	 				if (i>x) b2++;
	 			}
	 		}
	 	}
		
		FOR (i,0,200){
			if (i!=x+y){
				res+=C2(a[i]);
			}
			if (i!=x-y+100){
				res+=C2(b[i]);
			}
			a[i]=b[i]=0;
		}
		res+=C2(a1)+C2(a2);
		res+=C2(b1)+C2(b2);
		res=C2(m*n-1)-res;
		res*=2;
		cout<<res<<endl;
	}
         return 0;
}