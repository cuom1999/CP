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

struct circle{
	ld x,y,r;
}C[2005];

ld d[2005][2005];

int lab[2005];

int getRoot(int a){
	while (lab[a]>=0) a=lab[a];
	return a;
}

void DSU (int m, int n){
	int x = lab[m]+lab[n];
	if (lab[m]<lab[n]){
		lab[m]=x;
		lab[n]=m;
	}
	else{
		lab[n]=x;
		lab[m]=n;
	}
}

struct edge{
	int x,y;
	ld c;
	bool operator<(edge a){
		return c<a.c;
	}
};
vector<edge> E;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    FOR (i,1,n){
    	cin>>C[i].x>>C[i].y>>C[i].r;
    	lab[i]=-1;
    }

    FOR (i,1,n){
    	FOR (j,i+1,n){
    		ld dist = sqrt(sq(C[i].x-C[j].x)+sq(C[j].y-C[i].y));
    		dist -= C[i].r+C[j].r;
    		dist = max(dist,(ld)0.0);
			d[i][j]=d[j][i]=dist;  
			edge e;
			e.x=i; e.y=j;
			e.c=dist;
			E.pb(e);  		
    	}
    }
    sort(all(E));
    
    ld res=0 ;
    for (auto i:E){
    	int m = getRoot(i.x);
    	int n = getRoot(i.y);
    	if (m==n) continue;
    	else{
    		DSU(m,n);
    		res+=i.c;
    	}
    }

    cout<<fixed<<setprecision(8)<<res<<endl;




	
         return 0;
}