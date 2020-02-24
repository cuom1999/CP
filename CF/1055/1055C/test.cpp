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
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;



int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll la,ra,lb,rb,ta,tb;

    cin>>la>>ra>>ta;
    cin>>lb>>rb>>tb;

    la=(la-lb+INF*tb)%tb; 
    ra=(ra-lb+INF*tb)%tb; 
    rb-=lb;
    lb=0;
    ll res=0;
    ll Mi = 1e18, Ma=-1e18;
    FOR (k,0,tb-1){
    	ll l1=(la+k*ta)%tb;
    	ll r1=(ra+k*ta)%tb;
    	ll cnt=0;

    	for (ll i=l1; i!=r1%tb; i=(i+1)%tb){
    		if (i<=rb) cnt++; 
    	}
    	if (r1%tb<=rb) cnt++;
    	res=max(res,cnt);
    	cout<<cnt<<" ";
    }
    cout<<res<<endl;
    
	
         return 0;
}