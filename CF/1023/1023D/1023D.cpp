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

ll a[200005];

ll SPT[200005][25];
int n;
void preRMQ(){
    for (ll i=0; (1<<i) <= n ; i++){
        for (ll j=1; j+(1<<i)-1<= n; j++){
            if (i==0){
                SPT[j][i]=a[j];
            }
            else{
                SPT[j][i]=min(SPT[j][i-1],SPT[j+(1<<(i-1))][i-1]);
            }
        }
    }
}

inline ll getRMQ(ll u, ll v){
    ll k=flog2(v-u+1);
    return min(SPT[u][k],SPT[v-(1<<k)+1][k]);
}

int st[200005], en[200005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int q;
    cin>>n>>q;
    bool ir=0, ii=0;
    FOR (i,1,n){ 
    	cin>>a[i];
    	if (a[i]==q) {ir=1;}
    }
    if (ir==0){
    	FOR (i,1,n){ 
    		if (a[i]==0){ 
    			ir=1;
    			a[i]=q;
    			break;
    		}
    	}
    	if (ir==0){ 
    		cout<<"NO";
    		return 0;
    	}
    }
    FOR (i,1,n){ 
    	if (a[i]==0){ 
    		if (i>1) a[i]=a[i-1];
    		else a[i]=1;
    	}
    }
    FOR (i,1,n) { 
    	en[a[i]]=i;
    }
    FORD(i,n,1) st[a[i]]=i;
    preRMQ();
    FOR (i,1,q) { 
    	if (st[i]){ 
    		if (getRMQ(st[i],en[i])<i){ 
    			cout<<"NO";
    			return 0;
    		}
    	}
    }
    cout<<"YES"<<endl;
    FOR (i,1,n) cout<<a[i]<<" ";







         return 0;
}