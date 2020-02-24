#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define pmod 1000000007
//#define maxn 100005
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int maxn=200005;

int lab[maxn];
vector<int> v[maxn];
vector<int> d,lt;
ll getRoot (ll a){
    while (lab[a]>0){
        a=lab[a];
    }
    return a;
}

void DSU(ll a , ll b){
    if (a==b) return;
    int x=lab[a]+lab[b];
    if (lab[a]<lab[b]){
        lab[b]=a;
        lab[a]=x;
    }
    else{
        lab[a]=b;
        lab[b]=x;
    }
}
int c[maxn],cc[maxn];
vector<int> dd;
ll n;
int r0;
void dfs(ll a){
    dd.clear();
    ll u=0;
    for (auto i: v[a]){
       if (cc[i]==1) c[i]=1;
       else u++;
    }
    //cout<<a<<" "<<u<<endl;
    for (auto i: d) {
        if (c[i]==0){
            dd.pb(i);
        }
        if (c[i]==1) c[i]=0;
    }
    if (u<n-(int)d.size()){
        DSU (getRoot(a), getRoot(r0));
    }
    for (auto i:dd){
        DSU(getRoot(i),getRoot(a));
        //dfs(i);
    }

}
int h[maxn];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll m,aa,bb,uu,vv;
    cin>>n>>m;
    FOR (i,1,m){
        cin>>aa>>bb;
        if (i==1) {uu=aa;vv=bb;}
        v[aa].pb(bb);
        v[bb].pb(aa);
    }
    //ll r0=0;
    ll r=INF;
    FOR (i,1,n) lab[i]=-1;
    FOR (i,1,n){
        if (v[i].size()<r){
            r=v[i].size();
            r0=i;
        }
    }
    for (auto i: v[r0]){
        d.pb(i);
        cc[i]=1;
    }
    //cout<<r0<<endl;
    FOR (i,1,n){
        if (cc[i]==0) {DSU (getRoot(i), getRoot(r0));}
    }
    //FOR (i,1,n) cout<<lab[i]<<" ";
    //d.pb(r0);
    for(auto i: d){
        dfs(i);
        //cout<<i<<" ";
    }
    //cout<<endl;

    FOR (i,1,n){
        if (lab[i]<0) lt.pb(-lab[i]);
        //cout<<lab[i]<<" ";
    }
    //cout<<endl;
    cout<< (int) lt.size() - 1 <<endl;


            return 0;
}