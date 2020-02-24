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

const ll K = 998244353;
ll gt[1000005];
ll rev[1000005];

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll combi(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	return gt[n] * rev[n - k] % K * rev[k] % K;
}

int a[10];

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    gt[0] = 1;
    rev[0] = 1;
    FOR (i, 1, 1000000) {
    	gt[i] = gt[i - 1] * 1ll * i % K;
    	rev[i] = mu(gt[i], K - 2);
    }
    ll n;
    cin >> n;
    ll res = gt[n];
    FOR (i, 1, n - 1) { 
    	res = (res + gt[n] * rev[n - i] % K * (gt[n - i] - 1) % K) % K;
    }
    cout << res << endl;
    /*
    FOR (i, 1, n) a[i] = i;
    string s;
    do {
    	FOR (i, 1, n) s += (char) (a[i] + '0');
    } while (next_permutation(a + 1, a + n + 1));

    cout << s << endl;
    FOR (i, 0, s.size() - n + 1) {
    	int sum = 0;
    	FOR (j, 0, n - 1) {
    		sum += s[i + j] - '0';
    	}
    	if (sum == n * (n + 1) / 2) {
    		cout << i + 1 << " ";
    		FOR (j, 1, n) cout << s[i + j - 1];
    		cout << endl;
    	}
    }
    */
    return 0;
}