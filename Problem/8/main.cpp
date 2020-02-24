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
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF (ll) (1e18+10)
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

/* DE BAI: f(n); tong binh phuong cac uoc cua n. Tinh sum f(i) from 1 to n. */

const ll K=1e9+7;

ll mu(ll a, ll n){
    if (n==0) return 1;
    ll q=mu(a,n/2);
    if (n%2==0) return q*q%K;
    return q*q%K*a%K;
}

ll rev6=mu(6,K-2);

ll S(ll n){
    n%=K;
    return n*(n+1)%K*(2*n+1)%K*rev6%K;
}

inline ll calc(ll n){
    ll d=sqrt(n);
    ll uk,uk1,j,res=0;
    FOR (i,1,d){
        uk=n/i;
        uk1=n/(i+1);
        j=i%K;
        ll s=(S(uk)-S(uk1))%K*j%K;
        res=(res+s)%K;
    }
    ll t;
    FOR (i,1,n/(d + 1)){
        t=(n/i)*i%K*i%K;
        res=(res+t)%K;
    }
    return (res+K)%K;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    //FOR (i,1,10) cout<<calc(i)<<endl;
    ll n;
    while (1){
        cin>>n;
        cout<<calc(n)<<endl;
        ll res2=0;
        FOR (i,1,n){
            ll t=(n/i)*i%K*i%K;
            res2=(res2+t)%K;
        }
        cout<<res2<<endl;
    }



    return 0;
}
