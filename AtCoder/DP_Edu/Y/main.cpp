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
ll d[3005], gt[200005], rev[200005];

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);

	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll combi(int n, int k) {
	if (n < k || k < 0) return 0;
	return gt[n] * rev[n - k] % K * rev[k] % K;
}

ll numPaths(int r1, int c1, int r2, int c2) {
	return combi(r2 - r1 + c2 - c1, r2 - r1);
}

struct Data {
	int r, c;
	Data(int __r = 0, int __c = 0): r(__r), c(__c) {}

	bool operator < (const Data & x) {
		if (r != x.r) return r < x.r;
		return c < x.c;
	}
};

vector<Data> data;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    gt[0] = rev[0] = 1;

    FOR (i, 1, 200000) {
    	gt[i] = gt[i - 1] * 1ll * i % K;
    	rev[i] = mu(gt[i], K - 2);
    }

    int H, W;
    cin >> H >> W;

    int n;
    cin >> n;
    FOR (i, 1, n) {
    	int r, c;
    	cin >> r >> c;
    	data.pb(Data(r, c));
    }
    sort(all(data));
    ll res = numPaths(1, 1, H, W);

    FOR (i, 0, n - 1) {
    	d[i] = numPaths(1, 1, data[i].r, data[i].c);

    	FOR (j, 0, n - 1) {
    		if (i == j) continue;
    		d[i] = (d[i] - d[j] * numPaths(data[j].r, data[j].c, data[i].r, data[i].c) % K + K) % K;
     	}
     	res = (res - d[i] * numPaths(data[i].r, data[i].c, H, W) % K + K) % K;
     	//cout << d[i] << " ";
    }

    //cout << endl;

    cout << res << endl;



    
	
    return 0;
}