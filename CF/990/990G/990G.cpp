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

const int N=200005;

int a[N], n;
vector<int> v[N];
vector<int> cnt[N];
vector<int> V;

int CC[N], dd[N], d1[N]; 

void dfs(int a, int C){
	dd[a]=1;
	CC[C]++;
	for (int i=0; i<v[a].size(); i++){
		if (!dd[v[a][i]] && d1[v[a][i]]){
			dfs(v[a][i],C);
		}
	}
}

ll f[N];

void handle(int i){
	FOR (j,1,200000/i){
		if (cnt[i*j].size()){
			for (int k=0; k<cnt[i*j].size(); k++){
				V.pb(cnt[i*j][k]);
				d1[cnt[i*j][k]]=1;
			}
		}
	}
	
	int C=0;
	for (int j=0; j<V.size(); j++){
		if (!dd[V[j]]) dfs(V[j],++C);
	}


	for (auto j:V) {
		d1[j]=dd[j]=0;
	}
	FOR (j,1,C) {
		f[i]+=CC[j]*1ll*(CC[j]+1)/2;
		CC[j]=0;
	}
	V.clear();
}
ll d[N];
int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n){
    	cin>>a[i];
    	cnt[a[i]].pb(i);
    }
    FOR (i,1,n-1){
    	int x,y;
    	cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
/*
    handle(1);
    cout<<f[1]<<endl;
    return 0;
*/

    FOR (i,1,200000) handle(i);

    FORD(i,200000,1){
    	d[i]=f[i];
    	FOR (j,2,200000/i){
    		d[i]-=d[i*j];
    	}
    }
    FOR (i,1,200000){
    	if (d[i]) cout<<i<<" "<<d[i]<<endl;
    }
    
	
         return 0;
}