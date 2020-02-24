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
typedef pair < ll, ll > pll;

set<ll> v;
vector<ll> v1;

ll mu[20];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	mu[0]=1;
 	FOR (i,1,18){
 		mu[i]=mu[i-1]*10;
 	}
 	ll S=0;
 	FOR (i1,0,17){
 		FOR (i2,i1+1,17){
 			FOR (i3,i2+1,17){
 				FOR (a1,0,9){
 					FOR (a2,0,9){
 						FOR (a3,0,9){
 							S=a1*mu[i1]+a2*mu[i2]+a3*mu[i3];

 							//if (i1==0 && i2==1 && i3==5 && a1==0 && a2==0 && a3==1) cout<<S<<endl;
 							v.insert(S);
 						}
 					}
 				}
 			}
 		}
 	}
 	//cout<<v.size()<<endl;
 	v.insert(1e18);

 	for (auto i:v)v1.pb(i);
 	sort(all(v1));
 	int q;
 	cin>>q;
 	FOR (z,1,q){
 		ll l,r;
 		cin>>l>>r;
 		cout<<upper_bound(all(v1),r)-upper_bound(all(v1),l-1)<<endl;
 	}


		
         return 0;
}