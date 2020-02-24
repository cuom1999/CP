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


ll SPT_min[100005][25], SPT_max[100005][25];
ll n,a[100005];


void preRMQ(){
    for (ll i=0; (1<<i) <= n ; i++){
        for (ll j=1; j+(1<<i)-1<= n; j++){
            if (i==0){
                SPT_min[j][i]=a[j];
                SPT_max[j][i]=a[j];
            }
            else{
                SPT_min[j][i]=min(SPT_min[j][i-1],SPT_min[j+(1<<(i-1))][i-1]);
                SPT_max[j][i]=max(SPT_max[j][i-1],SPT_max[j+(1<<(i-1))][i-1]);
            }
        }
    }
}

inline ll getMin(ll u, ll v){
    ll k=flog2(v-u+1);
    return min(SPT_min[u][k],SPT_min[v-(1<<k)+1][k]);
}

inline ll getMax(ll u, ll v){
    ll k=flog2(v-u+1);
    return max(SPT_max[u][k],SPT_max[v-(1<<k)+1][k]);
}
/*
struct Node{
	ll lazy, val;
} nodes[400005];

void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;

    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;

    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, ll val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id); 

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}

ll get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return 1e18;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id);

    return min(get(id*2, l, mid, u, v),
        get(id*2+1, mid+1, r, u, v));
}

*/

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n){
    	cin>>a[i];
    }
    preRMQ();
	d[1]=1e17;
	
	compute(2,n,0,n); 
	//FOR (i,2,n) cout<<d[i]<<" ";   
  	cout<<d[n]<<endl;


         return 0;
}