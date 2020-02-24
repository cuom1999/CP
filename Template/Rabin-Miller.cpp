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

ll mul (ll a, ll b,ll m){
    if (b==1) return a%m;
    if (b==0) return 1%m;
    a%=m; b%=m;
    ll q=mul(a,b/2,m);
    if (b%2==0) return (q+q)%m;
    else return (q+q+a)%m;
}

ll mu(ll a, ll n, ll m){
    if (n==0) return 1%m;
    ll q=mu(a,n/2,m);
    if (n%2==0) return mul(q,q,m);
    return mul(mul(q,q,m),a,m);
}

bool checkprime (ll n){

    if (n==2) return 1;
    if (n%2==0|| n==1) return 0;
    ll m=n-1;
    ll s=0;
    while (m%2==0){
        m/=2;s++;
    }
    ll dem=0,q=0,a,b;
    while( dem<=3 ){
        dem++;

        a=rand()%(n-2)+2;

        //cout<<a<<endl;
        b=mu(a,m,n);
        if ((b+1)%n==0 || (b-1)%n==0) {q++;continue;}
        FOR (i,1,s){
            b=mul(b,b,n);
            //cout<<i<<" "<<b<<endl;
            if ((b+1)%n==0) {q++; break;}
        }
        //cout<<a<<endl;
    }
    //cout<<q<<endl;
    if (q==4) return 1;
    return 0;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(NULL);
    //cout<<mul(12,10,100);
    ll s=0;

    //cout<<checkprime((ll) 1e9+7);
    FOR (i,1e9, 1e9+100){
        if (checkprime(i)) cout<<i<<endl;
    }

        return 0;
}
