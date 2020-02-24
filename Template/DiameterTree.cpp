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
    ll t;
    cin>>t;
    FOR (z,1,t){

        cin>>n;
        FOR (i,1,n) v[i].clear();
        FOR (i,1,n-1){
            ll x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        n=50;

        find_diameter(1);

        for (auto i: diameter) cout<<i<<" ";
        /*ll cat1=diameter[(diameter.size()-1)/2],cat2=cat1+1;
        //cout<<cat1<<" "<<cat2<<endl;
        for (ll i=0; i<v[cat1].size();i++){
            if (v[cat1][i]==cat2){
                swap(v[cat1][i],v[cat1][v[cat1].size()-1]);
                v[cat1].pop_back();break;
            }
        }

        for (ll i=0; i<v[cat2].size();i++){
            if (v[cat2][i]==cat1){
                swap(v[cat2][i],v[cat2][v[cat2].size()-1]);
                v[cat2].pop_back();break;
            }
        }

        ll res=INF;
        find_diameter(cat1);
        res=(diameter.size())/2;
        ll t1=diameter[(diameter.size()-1)/2];
        //for (auto i: diameter) cout<<i<<" "; cout<<endl;

        find_diameter(cat2);
        res=max(res,(ll) (diameter.size())/2);
        //cout<<cat1<<" "<<cat2<<endl;
        //for (auto i: diameter) cout<<i<<" "; cout<<endl;
        ll t2=diameter[(diameter.size()-1)/2];
        //if (t1==t2) {if (t1>1) t2=1; else t2=2;}
        cout<<res<<" "<<t1<<" "<<t2<<endl;
        */
    }



         return 0;
}
