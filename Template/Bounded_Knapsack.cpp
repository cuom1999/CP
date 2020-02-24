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

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

ll a[105],v[105],w[105],M,n;
ll w1[100005],v1[100005],d[3005][10005];
vector<ll> V[105];

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>M;
    FOR (i,1,n){
        cin>>w[i]>>v[i]>>a[i];
    }
    FOR (i,1,n){
        int f=1;
        while (a[i]>=f){
            V[i].pb(f);
            a[i]-=f;
            f*=2;
        }
        //cout<<a[i]<<" "<<f<<endl;
        if (a[i]) V[i].pb(a[i]);
    }

    int N=0;
    FOR (i,1,n) N+=V[i].size();
    int u=0;
    FOR (i,1,n){
        for (auto j:V[i]){
            w1[++u]=j*w[i];
            v1[u]=j*v[i];
        }
    }
    //cout<<N<<endl;
    //FOR (i,1,N) cout<<w1[i]<<" "<<v1[i]<<endl;

    FOR (i,1,N){
        FOR (j,0,M){
            d[i][j]=d[i-1][j];
            if (j>=w1[i]){
                d[i][j]=max(d[i][j],d[i-1][j-w1[i]]+v1[i]);
            }
            //cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
        }
    }
    ll res=0;
    FOR (i,0,M){
        res=max(res,d[N][i]);
    }
    cout<<res<<endl;

         return 0;
}
