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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

vector<int> v[200005];
int d[200005];
int p[200005];
void dfs(int a, int par){
	p[a]=par;
	for (auto i:v[a]){
		if (i==par) continue;
		d[i]=d[a]+1;
		dfs(i,a);
	}
}

priority_queue<II> pq;
int used[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i,1,n-1){
    	int x,y;
    	cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    dfs(1,0);
    //FOR (i,1,n) cout<<d[i]<<" "; 
    FOR (i,1,n) {
    	if (d[i]>=3) pq.push(II(d[i],i));
    	else used[i]=1;
    }
    int res=0;
    while (pq.size()){
    	int a=pq.top().second;

    	pq.pop();
    	if (used[a]) continue;
    	a=p[a];
    	for (auto i:v[a]) used[i]=1;
    	used[a]=1;
    	res++;
    }
    cout<<res<<endl;


    
	
         return 0;
}