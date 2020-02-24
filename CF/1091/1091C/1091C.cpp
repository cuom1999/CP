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

vector<ll> A, res;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	ll n;
 	cin >> n;
 	for (ll i = 1; i <= n / i; i++) {
 		if (n % i == 0) {
 			A.pb(i);
 			if (i * i != n) A.pb(n / i);
 		}
 	}   

 	for (auto i: A) {
 		res.pb(i + n * (i - 1) / 2);
 	}
 	sort(all(res));
 	for (auto i: res) cout << i << " ";
	
    return 0;
}