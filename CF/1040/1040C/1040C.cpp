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
typedef pair < ll, ll > II;

ll a[200005], x[200005];
vector<II> v;
vector<ll> res;
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	ll t;
	cin>>n>>t;
	FOR (i,1,n) cin>>a[i];
	FOR (i,1,n) cin>>x[i];
	int last=1;
	x[n+1]=-1;
	FOR (i,1,n){
		if (x[i]==x[i+1]) continue;
		else{
			if (x[i]!=i) {
				cout<<"No"; return 0;
			}
			else{
				v.pb(II(last,i));
				last=i+1;
			}
		}
	}
	//for (auto i:v) cout<<i.first<<" "<<i.second<<endl;

	for (auto i:v){
		ll st=i.first, en=i.second;
		if (st==en){
			res.pb(a[st]+t);
		}
		else{
			FOR (i,st+1,en) res.pb(a[i]+t);
			res.pb(a[en]+t+1);
		}
	}
	for (int i=1; i<res.size(); i++){
		if (res[i]<=res[i-1]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for (auto i:res) cout<<i<<" ";
         return 0;
}