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

/* Cho bảng m * n (m, n <= 2e5). Tính số cách đặt xe sao cho có đúng t con xe được bình yên
(a peaceful rook is a rook that has a GFF so he doesn't have to compete with other rooks)
*/

const ll K = 1e9 + 7;
ll m, n;
const int MAXN = 200005;

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll gt[MAXN], rev[MAXN];

ll Combi(int n, int k) {
	if (k > n || k < 0) return 0;
	return gt[n] * rev[k] % K * rev[n - k] % K;
}

ll solve(ll t) {
	if (t > n) return 0;
	ll res = 0;
	FOR (i, 0, n - t) {
		ll q = Combi(n - t, i) * Combi(m - t, i) % K * gt[i] % K;
		ll u = (m - t - i) * 1ll * (n - t - i);
		u = mu(2, u);
		q = q * u % K;
		if (i % 2 == 0) {
			res = (res + q) % K;
		}
		else {
			res = (res - q + K) % K;
		}
	}
	res = res * Combi(m, t) % K * Combi(n, t) % K * gt[t] % K;
	return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    gt[0] = rev[0] = 1;
    FOR (i, 1, 200000){
    	gt[i] = gt[i - 1] * 1ll * i % K;
    	rev[i] = mu(gt[i], K - 2);
    }
  	cin >> m >> n;
  	if (m < n) swap(m, n);
  	ll res = 0;

  	int q;
  	cin >> q;
  	FOR (i, 1, q) {
  		ll t;
  		cin >> t;
  		cout << solve(t) << endl;
  	}

	
    return 0;
}