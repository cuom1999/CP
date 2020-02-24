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

vector<int> v[N];

int num[N],low[N],vs[N];
int TIME,res;
vector<int>  STACK;

ll CC[N], val[N];
ll c[N];

void dfs(int a){
    low[a]=num[a]=++TIME;
    STACK.pb(a);
    for (auto i:v[a]){
        if (!num[i]) dfs(i);
        if (!vs[i]) low[a]=min(low[a],low[i]);
    }

    if (num[a]==low[a]) {
        res++;
        while (STACK.size()){
            int b=STACK.back(); CC[b]=res; val[res]=min(val[res],c[b]);
            STACK.pop_back();
            vs[b]=1;
            if (b==a) break;
        }
    }
}

int x[N], dd[N];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR (i,1,n) {
    	cin>>c[i];
    	val[i]=INF;
    }
    FOR (i,1,n) { 
    	cin>>x[i];
    	if (x[i]!=i) v[i].pb(x[i]);
    }
    FOR (i,1,n){ 
    	if (!num[i]) dfs(i);
    }
    //FOR (i,1,n) cout<<CC[i]<<" ";
    FOR (i,1,n){ 
    	if (CC[x[i]]!=CC[i]){ 
    		dd[CC[i]]=1;
    		//cout<<CC[i]<<endl;
    	}
    }
    //cout<<res<<endl;
    ll ans=0;
    FOR (i,1,res) { 
    	if (!dd[i]) ans+=val[i];
    }
    cout<<ans<<endl;
    return 0;
}
