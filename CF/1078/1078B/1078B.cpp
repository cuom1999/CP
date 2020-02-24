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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

ll d[105][10005];
int a[105];
int cnt[105];
vector<II> v;
int dd[105];

const ll K = 1e9 + 7;

ll gt[105], rev[105];
ll mu(ll a, ll n) {
    if (n == 0) return 1;
    ll q = mu(a, n / 2);
    if (n % 2 == 0) return q * q % K;
    return q * q % K * a % K;
}
ll Combi(int n, int k) {
	if (n < k || k < 0) return 0;
	return gt[n] * rev[k] % K * rev[n - k] % K;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    gt[0] = rev[0] = 1;
    FOR (i, 1, 100) {
    	gt[i] = gt[i - 1] * 1ll * i % K;
        rev[i] = mu(gt[i], K - 2);
    }
    
    int n;
    cin >> n;
    d[0][0] = 1;
    FOR (i, 1, n) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }

    FOR (i, 1, n) {
    	FORD (k, i, 1) {
    		FORD (m, 10000, a[i]) {
    			d[k][m] = (d[k][m] + d[k - 1][m - a[i]]) % K;
    			//if (d[k][m]) cout << k << " " << m << " " << d[k][m] << endl; 
    		}
    	}
    }


    FOR (i, 1, n) {
    	if (!dd[a[i]]) v.pb(II(a[i], cnt[a[i]]));
    	dd[a[i]] = 1;
    }

    int res = 1;

    for (auto i: v) {
    	FORD(j, i.second, 1) {
    		if (d[j][i.first * j] == Combi(i.second, j)) {
                res = max(res, j);
            }
    	}
    }
    if (v.size() == 2 && (res == v[0].second || res == v[1].second)) res = n; 
    cout << res << endl;


	
    return 0;
}