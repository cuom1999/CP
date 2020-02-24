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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<II> V;
int a[1000005];
int fen[1000005];

void add(int u, int v){
	for (int i=u; i<=1000000; i+=i&-i){
		fen[i]+=v;
	}
}

int get(int u){
	int res=0;
	for (int i=u; i; i-=i&-i){
		res+=fen[i];
	}
	return res;
}

ll p[1000006], q[1000005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i,1,n){
    	int x;
    	cin>>x;
    	V.pb(II(x,i));
    }
    sort(all(V));
    int C=0;
    for (int i=0; i<n; i++){
    	if (!i || V[i].first!=V[i-1].first){
    		a[V[i].second]=++C;
    	}
    	else a[V[i].second]=C;
    }

	FOR (i,1,n){
		p[i]=get(1000000)-get(a[i]);
		add(a[i],1);
	}
	FOR (i,1,1000000) fen[i]=0;
	FORD (i,n,1){
		q[i]=get(a[i]-1);
		add(a[i],1);
	}
	ll res=0;
	FOR (i,1,n){
		res+=p[i]*q[i];
	}     

	cout<<res<<endl;

	
         return 0;
}