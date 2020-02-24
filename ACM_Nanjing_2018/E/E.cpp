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

int st[4000005];
int lz[4000005];
char a[1000005];
char b[1000005];

void build (int id, int l, int r) {
	if (l == r) {
		if (a[l] == b[l]) st[id] = 1;
		else st[id] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build (id * 2, l, mid);
	build (id * 2 + 1, mid + 1, r);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

void down (int id, int l, int r){
	if (l == r || !lz[id]) return;
	int mid = (l + r) / 2;
	st[id * 2] = mid - l + 1 -st[id * 2];
	lz[id * 2] ^= 1;
	st[id * 2 + 1] = r - mid - st[id * 2 + 1];
	lz[id * 2 + 1] ^= 1;
	lz[id] = 0;
}

void update (int id, int l, int r, int u, int v) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		st[id] = r - l + 1 - st[id];
		lz[id] ^= 1;
		return;
	}
	int mid = (l + r) / 2;
	down (id, l, r);
	update(id * 2, l, mid, u, v);
	update(id * 2 + 1, mid + 1, r, u, v);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

int getSum (int id, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	down(id, l, r);
	return getSum(id * 2, l, mid, u, v) + getSum(id * 2 + 1, mid + 1, r, u, v);
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    FOR (i, 1, n) cin >> a[i];
    FOR (i, 1, n) cin >> b[i];
    build(1, 1, n);

    //FOR (i, 1, n) cout << getSum(1, 1, n, i, i); cout << endl;

    FOR (i, 1, n - k + 1) {
    	if (getSum(1, 1, n, i, i) == 0) {
    		update(1, 1, n, i, i + k - 1);
    	}
    }
    bool res = 1;
    FOR (i, n - k + 2, n) {
    	if (getSum(1, 1, n, i, i) == 0) {
    		cout << "No" << endl;
    		return 0; 
    	}
    }
    cout << "Yes" << endl;


	
    return 0;
}