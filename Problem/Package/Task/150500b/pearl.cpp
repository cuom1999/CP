#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define pmod 1000000007
#define maxn 100005
#define IN freopen("pearl.inp","r",stdin)
#define OUT freopen("pearl.out","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

/* Beauty number (DAEJEON 2017) : n-->sum of square of digits of n--> ... --> 1

    Find the number of beauty numbers in [a,b] */

int dd[1000005];

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
    if (a==1) return 1;
    if (d[a]) return d[a];
    if (dd[a] && d[a]==0) return d[a]=2;
    dd[a]=1;
    ll w=a;
    a=tcs(a);
    return d[w]=calc(a);
}

vector<ll> v;
ll f[2005][20],ds[2005][20];
ll a[20];
ll solve (ll n){
    ll u=0;
    FOR (i,0,2000){
        FOR (j,0,19){
            f[i][j]=ds[i][j]=0;
        }
    }
    while (n){
        a[u]=n%10;
        n/=10;u++;
    }
    u--;
    FOR (i,0,9){
        f[i*i][0]++;
        if (i<=a[0]) ds[i*i][0]++;
    }
    FOR (j,1,u){
        FOR (s,0,2000){
            for (ll aa=0; aa<=9 && s>=aa*aa; aa++){
                f[s][j]+=f[s-aa*aa][j-1];
                if (aa==a[j]){
                    ds[s][j]+=ds[s-aa*aa][j-1];
                }
                if (aa<a[j]){
                    ds[s][j]+=f[s-aa*aa][j-1];
                }
            }
        }
    }
    ll res=0;
    for (auto s: v){
        res+=ds[s][u];
    }
    return res;
}

int main(){
    IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //int n;
    FOR (a,1,2000){
        if (calc(a)==1) {v.pb(a);}
    }
    //cout<<solve(12345678912345678)<<endl;
    int t;
    cin>>t;
    FOR (z,1,t){
        ll l,r;
        cin>>l>>r;
        //cout<<solve(r)-solve(l-1)<<endl;
        cout<<(r-l+1)-(solve(r)-solve(l-1))<<endl;
    }
         return 0;
}
