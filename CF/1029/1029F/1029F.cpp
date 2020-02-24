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
#define FORD(i,a,b) for(ll i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > II;



vector<II> solve(ll n){
	vector<II> v;
	for (ll i=1; i*i<=n; i++){
		if (n%i==0){
			v.pb(II(i,n/i));
		}
	}
	return v;
}

vector<II> v[5];

bool cmp(II a, II b){
	return (a.first+a.second)<(b.first+b.second);
}

bool check(ll a, ll b, ll c, ll d){
	return ((a<=c && b<=d) || (a<=d && b<=c));
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    v[0]=solve(a+b);
    v[1]=solve(a);
    v[2]=solve(b);
    sort(all(v[0]),cmp);
    //for (auto i:v[0]) cout<<i.first<<" "<<i.second<<endl;
    for (auto i:v[0]){
    	FOR (z,1,2){
	    	for (auto j:v[z]){
	    		if (check(j.first,j.second,i.first,i.second)) {
	    			cout<<2*(i.first+i.second)<<endl;
	    			return 0;
	    		}
	    	}
	    }
    }
	
         return 0;
}