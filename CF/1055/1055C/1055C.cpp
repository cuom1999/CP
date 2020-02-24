#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
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

ll la,ra,lb,rb,ta,tb,g;


ll solve(ll u){
    ll u1 = (u+ra-la)%tb;

    ll Y=0;
    if (u<=u1){
    	Y=max(Y,min(u1-u+1,rb-u+1));
    }
    else{
    	Y=max(Y,max(0LL,rb-u+1)+min(rb+1,u1+1));
    } 
    return Y;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin>>la>>ra>>ta;
    cin>>lb>>rb>>tb;

    la-=lb; 
    ra-=lb;
    rb-=lb;
    lb=0;

    g=__gcd(ta,tb);
    ll u = (la%g+g)%g;
    ll res=0;
    FOR(i,-1000,1000){
    	ll uu=(u+i*g)%tb;
    	uu=(uu+tb)%tb;
    	res=max(res,solve(uu));
    }	
    
	cout<<res<<endl;
         return 0;
}