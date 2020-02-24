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

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

vector<int> v[100005];

int inv_index[100005];
vector<int> Eulertour;
int index[100005];
int tin[100005],tout[100005];
int TIME;
void dfs(int u, int par){
    index[u]=++TIME;
    inv_index[TIME]=u;

    Eulertour.pb(index[u]);

    tin[u]=Eulertour.size();

    for (auto i: v[u]){
        if (i==par) continue;
        dfs(i,u);
        Eulertour.pb(index[u]);
    }
    tout[u]=Eulertour.size();
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;
    cin>>n;
    FOR (i,1,n-1){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    //FOR (i,1,n) cout<<index[i]<<" "; cout<<endl;
    for (auto i: Eulertour) cout<<inv_index[i]<<" ";
    cout<<endl;
    FOR (i,1,n) cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;

        return 0;
}
