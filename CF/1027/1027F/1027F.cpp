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

const int N=1000005;

int x[N], y[N];
vector<int> V;

int ma(int t){ 
	return lower_bound(all(V),t)-V.begin();
}

int vs[2*N], e[2*N];
vector<int> v[2*N], C[2*N];


void dfs(int i, int c){ 
	if (vs[i]) return;
	C[c].pb(i);
	vs[i]=1;
	//cout<<i<<" "<<c<<endl;
	for (auto j:v[i]){ 
		e[c]++;
		if (!vs[j]) dfs(j,c);
	}
}
int dd[2*N];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i,1,n){ 
    	cin>>x[i]>>y[i];
    	V.pb(x[i]);
    	V.pb(y[i]);
    }
    sort(all(V));
    
    FOR (i,1,n){ 
    	//cout<<ma(x[i])<<" "<<ma(y[i])<<endl;
    	int X=ma(x[i]);
    	int Y=ma(y[i]);
    	v[X].pb(Y);
    	v[Y].pb(X);
    	dd[X]=1;
    	dd[Y]=1;

    }
    int CC=0;
    FOR (i,0,2*n){ 
    	if (dd[i] && !vs[i]){ 
    		dfs(i,++CC);
    	}
    }
    //cout<<CC<<endl;
    int res=-1;
    FOR (i,1,CC){ 
    	//cout<<i<<" "<<e[i]<<" : ";
    	//for (auto j:C[i]) cout<<j<<" "; cout<<endl;
    	sort(all(C[i]));
    	if (e[i]>2*C[i].size()) {
    		cout<<-1;
    		return 0;
    	}
    	if (e[i]==2*C[i].size()){ 
    		res=max(res,C[i].back());
    	}
    	else{ 
    		res=max(res,C[i][C[i].size()-2]);
    	}
    }	
    cout<<V[res]<<endl;




         return 0;
}