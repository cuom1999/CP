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


ll K=1e9+7;

ll mu(ll a, ll n){
    if (n==0) return 1;
    else{ ll q=mu(a,n/2);
        if(n%2==0) return q*q%K;
        else return (q*q%K)*a%K;
    }
}

ll phimu(ll p, ll k){
    if (k==0) return 1;
    else{
        return (p-1)*mu(p,k-1)%K;
    }
}

ll phi (ll m){ ll d=0;ll r=1;
    for (int i=2; i*i<=m;i++){ d=0;
        if (m%i==0){
            while (m%i==0) {d++;m/=i;}

        }
        if (d>0) r=(r*phimu(i,d))%K;
        r%=K;
    }
    if (m>1) r*= m-1;
    r%=K;
    return r;
}

ll m,n,k;
ll gt[1000006],rev[1000006];

inline ll Combi(ll n, ll k){
    if (n<k) return 0;
    return (gt[n]*rev[n-k]%K*rev[k])%K;
}
int main()
{//IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    rev[0]=1;gt[0]=1;
    FOR (i,1,1000001){
        gt[i]=gt[i-1]*i%K;
        rev[i]=mu(gt[i],K-2)%K;
    }
    ll a,b,k;
    /*Chia a diem xanh va b diem do thanh k phan tren duong tron */
    while (1){
        cin>>a>>b>>k;
        if (a==0) break;

        ll res=0;
        FOR (d,1,k){
            if ((a*d)%k==0 && (b*d)%k==0){
                res=(res+Combi((a*d/k)-1,d-1)*Combi((b*d/k)-1,d-1)%K)%K;
                cout<<d<<endl;
                //res=(res*mu(k,K-2))%K;
            }
            cout<<res<<endl;
        }

        res=(res*mu(k,K-2))%K;

        res%=K;
        if (res<0) res+=K;
        cout<<res<<endl;

    }
         return 0;
}
