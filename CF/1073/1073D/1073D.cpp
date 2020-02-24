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

ll a[200005];
ll s[200005];

ll sum(int l, int r){
	return s[r]-s[l-1];
}
vector<ll> V;
int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	ll n;ll T;
	cin>>n>>T;
	ll l=1 , r=n;
	FOR (i,1,n){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		V.pb(a[i]);
	}
	sort(all(V));
	ll res=0;
    ll S=s[n];
    ll N=n;
    int qq=0;
	while (T>0 && n){
		res+=(T/S)*n;
		T%=S;
		while (V.size() && V.back()>T) {
			S-=V.back();
			n--;
			V.pop_back();
		}
		FOR (i,1,N){
			if (T>=a[i]){
				T-=a[i];
				res++;
			}
		}
		while (V.size() && V.back()>T) {
			S-=V.back();
			n--;
			V.pop_back();
		}
		//cout<<T<<" "<<S<<" "<<n<<endl;
	}
	cout<<res<<endl;

	return 0;
}