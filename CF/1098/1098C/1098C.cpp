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

ll n;
ll s;

ll calc(ll d, ll N) {
	ll p = 1;
	ll res = 0;
	ll u = 0;
	while (N) {
		u++;
		if (N <= p) {
			res += u * N;
			N = 0;
		}
		else {
			N -= p;
			res += u * p; 
			p = p * d;
		}
	}
	return res;
}

ll calc1 (ll i, ll d, ll N, ll coef) {
	ll p = d;
	ll res = 0;
	ll u = i - 1;
	while (N) {
		u++;
		if (N <= p) {
			res += u * N;
			N = 0;
		}
		else {
			N -= p;
			res += u * p; 
			p = p * coef;
		}
	}
	return res;
} 
 
ll ans[100005];
vector<int> layer[100005];
ll p[100005];
ll cnt[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> s;

    ll L = 1, R = n - 1;

    if (s < 2 * n - 1 || s > n * (n + 1) / 2) {
    	cout << "No";
    	return 0;
    }

    while (L < R) {
    	ll mid = (L + R) / 2;
    	if (calc(mid, n) > s) {
    		L = mid + 1;
    	}
    	else { 
    		R = mid;
    	}
    }
    
    ll N = n;
    ans[1] = 1;
    N--;
    ll S = s;
    S--;
    ll coef = L;


    FOR (i, 2, n) {
    	if (N == 0 && S == 0) break;
    	L = 1; R = ans[i - 1] * coef;
    	while (L < R) {
    		ll mid = (L + R) / 2; 
    		//if (i == 2) cout << mid << " " << calc(coef, N - mid) << endl;
    		if (calc1(i, mid, N, coef) > S) {
    			L = mid + 1;
    		}
    		else R = mid;
    	}
    	ans[i] = L;
    	N -= L;
    	S -= ans[i] * i;
    }
    //cout << N << " " << S << endl;
    //FOR (i, 1, n) cout << ans[i] << " "; cout << endl;

    int C = 1;
    layer[1].pb(1);

    FOR (i, 2, n) {
    	FOR (j, 1, ans[i]) {
    		layer[i].pb(++C);
    	}
    }

    FOR (i, 2, n) {
    	for (auto j: layer[i]) {
    		int u = layer[i - 1].back();
    		cnt[u]++;
    		p[j] = u;
    		if (cnt[u] >= coef) layer[i - 1].pop_back();
    	}
    }
    cout << "Yes" << endl;
    FOR (i, 2, n) cout << p[i] << " "; cout << endl;


	
    return 0;
}