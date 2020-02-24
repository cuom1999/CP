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

vector<char> C;
string s;

ll res[55][55]; 
int stt[505];

const ll K = 1e9 + 7;

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) {
		return q * q % K;
	}
	return q * q % K * a % K;
}

ll gt[100005], rev[100005];

ll combi(int n, int k) {
	if (n < k || k < 0) return 0;
	return gt[n] * rev[k] % K * rev[n - k] % K; 
}
 

int leftCnt[55], rightCnt[55];
ll b[100005], a[100005];
int cnt[55];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    C.pb('#');
    FOR (i, 'a', 'z') C.pb(i), stt[i] = i - 'a' + 1;
    FOR (i, 'A', 'Z') C.pb(i), stt[i] = i - 'A' + 27;

    gt[0] = rev[0] = 1;
    FOR (i, 1, 100000) {
    	gt[i] = gt[i - 1] * 1ll * i % K;
    	rev[i] = mu(gt[i], K - 2);
    }

    cin >> s;
    int n = s.length();
    s = '0' + s;

    FOR (i, 1, n) {
    	cnt[stt[s[i]]]++;
    }
    b[0] = 1;

    FOR (i, 1, 52) {
    	int u = cnt[i];
    	FORD (j, n, 0) {
    		if (j >= u) b[j] = (b[j] + b[j - u]) % K;
    		else break;
    	}
    }

    //FOR (i, 0, n) cout << b[i] << " "; cout << endl;

    ll prod = 1;
    FOR (i, 1, 52) prod = prod * rev[cnt[i]] % K;

    FOR (i, 1, 52) {
    	FOR (j, i, 52) {
    		if (!cnt[i] || !cnt[j]) { 
    		}
    		else {
    			int n1 = n / 2, n2 = n / 2;
    			ll val = 1;

    			val = combi(n / 2, cnt[i]);
    			n1 = n / 2 - cnt[i];

				if (i != j) val = val * combi(n1, cnt[j]) % K, n1 -= cnt[j];

    			int u = cnt[i], v = cnt[j];

    			FOR (k, 0, u - 1) {
    				a[k] = b[k];
    			}
    			FOR (k, u, n1) {
    				a[k] = (b[k] - a[k - u]) % K;
    			}
    			if (i != j) {
	    			FOR (k, v, n1) {
	    				a[k] = (a[k] - a[k - v]) % K;
	    			}
	    		}

    			val = a[n1] * val % K * gt[n1] % K * gt[n2] % K * prod % K;
    			val = val * gt[u] % K;
    			if (i != j) val = val * gt[v] % K;

    			int cnt0 = 0;
    			FOR (i, 1, 52) {
    				cnt0 += (cnt[i] == 0);
    			}	
    			ll t = mu(2, cnt0);
    			val = val * mu(t, K - 2) % K * 2 % K;
    			res[i][j] = res[j][i] = (val + K) % K;
    		}
    	}
    }

    int q;
    cin >> q;
    FOR (z, 1, q) {
    	int i, j;
    	cin >> i >> j;
    	cout << res[stt[s[i]]][stt[s[j]]] << endl;
    }
    

	
    return 0;
}