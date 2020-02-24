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

bool bit(int n, int pos){ 
	return (bool) (n&(1<<pos));
}

struct node{ 
	int val,lz;
	node() {val=lz=0;}
};

int a[100005], b[100005];

struct seg{ 
	node st[400005];
	void build(int id, int l, int r) { 
		if (l==r) { 
			st[id].val=b[l];
			return;
		}
		int mid=(l+r)/2;
		build (id*2, l, mid);
		build (id*2+1,mid+1,r);
		st[id].val=st[id*2].val+st[id*2+1].val;
	}

	void color(int id, int l, int r){
		st[id].val=(r-l+1)-st[id].val;
		st[id].lz^=1;
	}

	void down (int id, int l, int r) { 
		if (l==r || !st[id].lz) return ;
		int mid=(l+r)/2;
		color(id*2,l,mid);
		color(id*2+1,mid+1,r);
		st[id].lz=0;
	}

	void update(int id, int l ,int r, int u, int v) { 
		if (v<l || r<u) return ;
		if (u<=l && r<=v){ 
			color(id,l,r);
			return ;
		}
		down(id,l,r);
		int mid=(l+r)/2;
		update(id*2,l,mid,u,v);
		update(id*2+1,mid+1,r,u,v);
		st[id].val=st[id*2].val+st[id*2+1].val;
	}

	int sum(int id, int l, int r, int u, int v){ 
		if (v<l || r<u) return 0;
		if (u<=l && r<=v) return st[id].val;
		down(id,l,r);
		int mid=(l+r)/2;
		return sum(id*2,l,mid,u,v)+sum(id*2+1,mid+1,r,u,v);
	}
}tree[21];


int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i,1,n){ 
    	cin>>a[i];
    }
    FOR (bi,0,19) { 
    	FOR (i,1,n){ 
    		b[i]=bit(a[i],bi);
    	}
    	tree[bi].build (1,1,n);
    }
    /*FOR (bi,0,3){ 
    	cout<<bi<<" : ";
    	FOR (i,1,n) cout<<tree[bi].sum(1,1,n,i,i)<<" "; cout<<endl;
    }*/

    int m;
    cin>>m;
    FOR (z,1,m){ 
    	int t;
    	cin>>t;
    	if(t==1){ 
    		int l,r;
    		cin>>l>>r;
    		ll res=0;
    		FOR (bi,0,19){ 
    			int k = tree[bi].sum(1,1,n,l,r);
    			res+=k*1LL*(1LL<<bi);
    		}
    		cout<<res<<endl;
    	}
    	else{ 
    		int l,r,x;
    		cin>>l>>r>>x;
    		FOR (bi,0,19){ 
    			if (bit(x,bi)) { 
    				tree[bi].update(1,1,n,l,r);
    			}
    		}
    	}
    }





         return 0;
}