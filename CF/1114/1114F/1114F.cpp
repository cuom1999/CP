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

int comp[305];
vector<int> prime;
int stt[305];

void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!comp[i]) {
			stt[i] = prime.size();
			prime.pb(i); 
		}
		for (int j = 0; j < prime.size() && prime[j] <= n / i; j++) {
			comp[i * prime[j]] = 1;
		}
	}
}

int a[400005];
int dataMul[400005][65], dataAdd[400006][65];
vector<II> divisors[305];
int n, q;
const int K = 1e9 + 7;

bitset<64> st[400005 * 4], lz[400005 * 4];
bitset<64> b[400005];


void build (int id, int l, int r) {
    if (l == r) {
        st[id] |= b[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2] | st[id * 2 + 1];
}

void down (int id, int l, int r) {
    if (lz[id].count() == 0) return;
    st[id * 2] |= lz[id];
    lz[id * 2] |= lz[id];
    st[id * 2 + 1] |= lz[id];
    lz[id * 2 + 1] |= lz[id];
    lz[id].reset();
}

void updateBit(int id, int l, int r, int u, int v, bitset<64> bit) {
    if (v < l || r < u || bit.count() == 0) return;
    if (u <= l && r <= v) {
        st[id] |= bit;
        lz[id] |= bit;
        return;
    }

    down(id, l, r);

    int mid = (l + r) / 2;
    updateBit(id * 2, l, mid, u, v, bit);
    updateBit(id * 2 + 1, mid + 1, r, u, v, bit);

    st[id] = st[id * 2] | st[id * 2 + 1];
}

bitset<64> zero;

bitset<64> getBit(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return zero;
    if (u <= l && r <= v) {
        return st[id];
    }

    down(id, l, r);

    int mid = (l + r) / 2;
    return getBit(id * 2, l, mid, u, v) | getBit(id * 2 + 1, mid + 1, r, u, v);
}
    

void internalUpdate(int at, int mul, int add, int p) {
    while (at <= n) {
        dataMul[at][p] += mul;
        dataMul[at][p] %= (K - 1);
        dataAdd[at][p] += add;
        dataAdd[at][p] %= (K - 1);
        at |= (at + 1);
    }
}

void update(int left, int right, int by, int p) {
    internalUpdate(left, by, -by * (left - 1), p);
    internalUpdate(right, -by, by * right, p);
}

int query(int at, int p) {
    int mul = 0;
    int add = 0;
    int start = at;
    while (at >= 0) {
        mul += dataMul[at][p];
        mul %= K - 1;
        add += dataAdd[at][p];
        add %= K - 1;
        at = (at & (at + 1)) - 1;
    }
    return (mul * 1ll * start + add) % (K - 1);
}

void pre() {
	FOR (i, 2, 300) {
		int M = i;
		for (int j = 2; j <= M / j; j++) {
			if (M % j == 0) {
				int cnt = 0;
				while (M % j == 0) {
					cnt++;
					M /= j;
				}
				divisors[i].pb(II(j, cnt));
			}
		}
		if (M > 1) divisors[i].pb(II(M, 1));
	}
}


ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

bitset<64> intToBit(int x) {
    bitset<64> res;
    for (auto i: divisors[x]) {
        res[stt[i.first]] = 1;
    }
    return res;
}

char s[10];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    //cin >> n >> q;
    sf("%d%d", &n, &q);
    sieve(300);
    pre();


    FOR (i, 1, n) {
    	//cin >> a[i];
        sf("%d", &a[i]);
        b[i] = intToBit(a[i]);
    	for (auto j: divisors[a[i]]) {
    		update(i, i, j.second, stt[j.first]);
    	}
    }

    build(1, 1, n);

    int cnt = 0;

    FOR (z, 1, q) {
    	//string s;
    	//cin >> s;

        sf("%10s", s);
    	if (s[0] == 'T') {
    		int l, r;
    		//cin >> l >> r;
            sf("%d%d", &l, &r);
    		ll res = 1;

            bitset<64> bit = getBit(1, 1, n, l, r);
            for(int j = bit._Find_first(); j < bit.size(); j = bit._Find_next(j)) {
                int u = (query(r, j) - query(l - 1, j) - 1) % (K - 1);
                if (u < 0) u += K - 1;
                res = res * (prime[j] - 1) % K * mu(prime[j], u) % K;
            }

    		//cout << res << endl;
            pf("%d\n", res);
    	}
    	else {
    		int l, r, x;
    		//cin >> l >> r >> x;
            sf("%d%d%d", &l, &r, &x);

    		for (auto i: divisors[x]) {
    			update(l, r, i.second, stt[i.first]);
    		}

            bitset<64> bit = intToBit(x);

            updateBit(1, 1, n, l, r, bit);
    	}
    }


	
    return 0;
}