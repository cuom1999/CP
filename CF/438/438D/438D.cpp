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

struct node{
	int max, min;
	ll sum; 
	int lz;
} st[400005];

int a[100005];

inline int max(int a, int b){
	if (a<b) return b;
	return a;
}
inline int min(int a, int b){
	if (a<b) return a;
	return b;
}

void build (int id, int l, int r){
	if (l==r){
		st[id].max = st[id].min = st[id].sum = a[l];
		st[id].lz=0;
		return ;
	}

	int mid=(l+r)/2;
	build (id*2,l,mid);
	build (id*2+1,mid+1,r);
	st[id].sum = st[id*2].sum + st[id*2+1].sum;
	st[id].max = max(st[id*2].max, st[id*2+1].max);
	st[id].min = min(st[id*2].min, st[id*2+1].min);
}

void down(int id, int l, int r){
	if (l==r || st[id].lz==0) return ;
	int y = st[id].min;

	st[id*2].min = y;
	st[id*2+1].min = y;

	y=st[id].max;
	st[id*2].max = y;
	st[id*2+1].max = y;
	
	int mid=(l+r)/2;
	st[id*2].sum = 	y*1ll*(mid-l+1);
	st[id*2+1].sum = y*1ll*(r-mid); 
	st[id].lz=0;
	st[id*2].lz=1;
	st[id*2+1].lz=1;
}

void update1(int id, int l, int r, int u, int v, int x){
	if (v<l || r<u || st[id].max<x) {
		return ;
	}
	if (u<=l && r<=v && st[id].max==st[id].min){
		st[id].min = st[id].min%x;
		st[id].max = st[id].max%x;
		st[id].sum = st[id].min*1ll*(r-l+1);
		st[id].lz = 1;
		return ;  
	}
	down(id,l,r);
	int mid=(l+r)/2;

	update1 (id*2,l,mid,u,v,x);
	update1 (id*2+1,mid+1,r,u,v,x);
	st[id].sum = st[id*2].sum + st[id*2+1].sum;
	st[id].max = max(st[id*2].max, st[id*2+1].max);
	st[id].min = min(st[id*2].min, st[id*2+1].min);
}

//a[u]=v;
void update2(int id, int l, int r, int u, int v){
	if (u<l || r<u) return ;
	if (l==r){
		st[id].min = st[id].max = st[id].sum =v;
		return ;
	}
	down(id,l,r);
	int mid=(l+r)/2;
	update2 (id*2,l,mid,u,v);
	update2 (id*2+1,mid+1,r,u,v);
	st[id].sum = st[id*2].sum + st[id*2+1].sum;
	st[id].max = max(st[id*2].max, st[id*2+1].max);
	st[id].min = min(st[id*2].min, st[id*2+1].min);
}

ll getSum(int id, int l, int r, int u, int v){
	if (v<l || r<u) return 0;
	if (u<=l && r<=v){
		return st[id].sum;
	}
	down(id,l,r);
	int mid=(l+r)/2;
	return getSum(id*2,l,mid,u,v) + getSum(id*2+1,mid+1,r,u,v);
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
	int n,m;
	cin>>n>>m;
	FOR (i,1,n) cin>>a[i];
	build(1,1,n);

	FOR (z,1,m){
		int t;
		cin>>t;
		if (t==1){
			int u,v;
			cin>>u>>v;
			cout<<getSum(1,1,n,u,v)<<endl;
		}
		else if (t==2){
			int u,v,x;
			cin>>u>>v>>x;
			update1(1,1,n,u,v,x);
		}
		else{
			int u,v;
			cin>>u>>v;
			update2(1,1,n,u,v);
		}
	}
         return 0;
}