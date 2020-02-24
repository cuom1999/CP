#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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

ll n;
vector<int> v[200005],diameter;
ll visit [200005],d[200005],p[200005];
void dfs(ll a){
    if (visit[a]) return ;
    //cout<<a<<endl;
    visit[a]=1;
    for (auto i:v[a]) {
        if (visit[i]==0) {d[i]=d[a]+1;p[i]=a;dfs(i);}
    }
}

void find_diameter(ll r){
    diameter.clear();
    FOR(i,1,n) {d[i]=0;visit[i]=0;}
    dfs(r);
    ll Ma=0,root=r;
    FOR (i,1,n){//cout<<d[i]<<" ";
        if (d[i]>Ma) {Ma=d[i];root=i;}
    }
    FOR(i,1,n) {d[i]=0;visit[i]=0;}
    //cout<<root<<endl;
    dfs(root);
    ll leaf=root;
    Ma=0;
    FOR (i,1,n){
        if (d[i]>Ma) {Ma=d[i];leaf=i;}
    }
    //FOR (i,1,n) cout<<d[i]<<" "; cout<<endl;
    ll u=leaf;
    //FOR (i,1,n) cout<<p[i]<<" ";cout<<endl;
    while (u!=root) {
        diameter.pb(u);
        u=p[u];
    }
    diameter.pb(root);
    //reverse(all(diameter));
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    FOR (i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    find_diameter(1);

    for (auto i: diameter) {
        cout << i << " ";
    }


    return 0;
}