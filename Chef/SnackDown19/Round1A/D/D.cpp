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

ll d[35][35][35][3];
bool vs[35][35][35][3];

int c[35];
vector<ll> V;

inline void del(ll m){
	int a,b,c,d;
	d=m%100; m/=100;
	c=m%100; m/=100;
	b=m%100; m/=100;
	a=m%100; m/=100;
	vs[a][b][c][d]=0;
}

ll calc (int n, int a, int b, int i){
	if (a<0 || b<0) return 0;
	if (n==0) return d[n][a][b][i];
	if (vs[n][a][b][i]) return d[n][a][b][i];
	
	vs[n][a][b][i]=1;
	V.pb(n*1000000+a*10000+b*100+i);

	if (c[n]==0){
		if (i==0){
			return d[n][a][b][i]=calc(n-1,a,b,0);
		}
		else{
			return d[n][a][b][i]=calc(n-1,a-1,b-1,0)+calc(n-1,a-1,b,1)+calc(n-1,a,b-1,1);
		}
	}
	else{
		if (i==0){
			return d[n][a][b][i]=calc(n-1,a-1,b,0)+calc(n-1,a,b-1,0)+calc(n-1,a,b,1);
		}
		else{
			return d[n][a][b][i]=calc(n-1,a-1,b-1,1);
		}
	}
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    d[0][0][0][0]=1;
    int t;
    cin>>t;
    FOR (z,1,t){
	    int A,B,C;
	    cin>>A>>B>>C;
	    FOR(i,1,32){
	    	c[i]=(bool) ((1<<(i-1))&C);
	    }
	    cout<<calc(flog2(C)+1,popcnt(A),popcnt(B),0)<<endl;
	    for (int i=0; i<V.size(); i++){
	    	del(V[i]);
	    }
	    V.clear();
	}
         return 0;
}