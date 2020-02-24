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

const ll K = 1e9 + 7;

ll s[105][105];
ll a[105];

ll mu(ll a, ll n){
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	else return q * q % K * a % K;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
  	int n;
  	cin >> n;
  	FOR(i, 0, n) s[i][0] = 1;
  	FOR(i, 1, n){
  		cout << 1 << " 1 " << i << endl;
  		int c;
  		cin >> c >> s[i][c];
  		ll u = (s[i][c] - s[i-1][c] + K) % K;
  		//cout << u << " " << s[i-1][c-1] << endl; 
  		u = u * mu(s[i-1][c-1], K-2) % K;
  		a[i] = u;
  		FOR (j, 1, i) s[i][j] = (s[i-1][j-1] * a[i] + s[i-1][j]) % K; 
  	}
  	cout << 2 << " ";
  	FOR (i, 1, n) cout << a[i] << " "; cout << endl;
	

        return 0;
}