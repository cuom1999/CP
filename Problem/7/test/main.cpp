#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define pmod 1000000007
#define maxn 100005
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

int dd[100000005];

int tcs(int n){
    int res=0;
    while (n){
        res+=(n%10)*(n%10);
        n/=10;
    }
    return res;
}
ll d[1000005];

ll calc (ll a){
    //cout<<a<<endl;
    if (a==1) return 1;
    if (d[a]) return d[a];
    if (dd[a] && d[a]==0) return d[a]=2;
    dd[a]=1;
    ll w=a;
    a=tcs(a);
//    d[a]++;
    return d[w]=calc(a);
}

vector<ll> v;
ll f[2005][20][11],ds[2005][20][11];
ll a[20];
ll solve (ll n){
    ll u=0;
    while (n){
        a[u]=n%10;
        n/=10;u++;
    }
    u--;
    FOR (i,0,9){
        f[i*i][0][i]=1;
        if (i<=a[0]) ds[i*i][0][i]=1;
    }
    FOR (j,1,u){
        FOR (s,0,2000){
            for (ll aa=0; aa<=9 && s>=aa*aa; aa++){
                FOR (b,0,9) f[s][j][aa]+=f[s-aa*aa][j-1][b];
                if (aa==a[j]){
                    ds[s][j][aa]+=ds[s-aa*aa][j-1][a[j-1]];
                    FOR (b,0,a[j-1]-1) ds[s][j][aa]+=f[s-aa*aa][j-1][b];
                }
                if (aa<a[j]){
                    ds[s][j][aa]=f[s][j][aa];

                }

            }
        }
    }
    ll res=0;
    for (auto s: v){
        FOR (aa,0,9) res+=ds[s][u][aa];
        //FOR (j,0,u) FOR (s,0,2000) FOR (aa,0,9) if (ds[s][j][aa]) cout<<s<<" "<<j<<" "<<aa<<" "<<ds[s][j][aa]<<endl;
    }
    //cout<<u<<endl;
    return res;
}

ll dem[2004][11];


long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}



int main()
{//OUT;
    IN;
    //freopen("input.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
    //int n;
    ll r=0;
    FOR (a,1,2000){
        if (calc(a)==1) {v.pb(a);}
    }
    //cout<<v.size()<<endl;
    /*for (auto i:v){
        //cout<<tcs(i)<<" "<<3<<" "<<i/1000
        dem[tcs(i)][i/1000]++;
    }
    FOR (i,0,2000){
        FOR (j,0,9){
            if (dem[i][j]) cout<<i<<" "<<3<<" "<<j<<" "<<dem[i][j]<<endl;
        }
    }*/
    int t;
    cin>>t;
    FOR (z,1,t){
        ll r=0;
        ll l1,r1;
        cin>>l1>>r1;
        FOR (i,l1,r1){
            if (calc(i)==1) r++;
            //cout<<i<<endl;
        }
        //cout<<1<<endl;
        cout<<r<<endl;
    }

         return 0;
}
