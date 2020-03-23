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

ll mul (ll a, ll b, ll K){
    a%=K; b%=K;
    ll res=0;
    while (b){
        res=(res+a*(b%1000))%K;
        b/=1000;
        a=a*1000%K;
        //cout<<res<<" "<<b<<endl;
    }
    if (res<0) res+=K;
    return res;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll a,b ;
    cin>>a>>b;

         return 0;
}
