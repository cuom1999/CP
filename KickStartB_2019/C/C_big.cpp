#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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

int st[400005];
int lz[400005];

void down(int id, int l, int r) {
	if (l == r) return;
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];

	st[id * 2] += lz[id];
	st[id * 2 + 1] += lz[id];

	lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int k) {
	if (v < l || r < u || u > v) return;
	if (u <= l && r <= v) {
		st[id] += k;
		lz[id] += k;
		return;
	}
	down(id, l, r);
	int mid = (l + r) / 2;

	update(id * 2, l, mid, u, v, k);
	update(id * 2 + 1, mid + 1, r, u, v, k);

	st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int getMax(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return -1;
	if (u <= l && r <= v) return st[id];
	
	down(id, l, r);
	int mid = (l + r) / 2;

	return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

int a[100005], pos[100005], endPos[100005], s[100005];
vector<int> v[100005];


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
    	cout << "Case #" << z << ": ";

    	memset(st, 0, sizeof(st));
		memset(lz, 0, sizeof(lz));
    	memset(s, 0, sizeof(s));
    	memset(endPos, 0, sizeof(endPos));
		memset(pos, 0, sizeof(pos));

		FOR (i, 1, 100000) v[i].clear();

    	int n, S;	
    	cin >> n >> S;

    	FOR (i, 1, n) {
    		cin >> a[i];
    		pos[i] = v[a[i]].size();
    		v[a[i]].pb(i);
    	}

    	FOR (i, 1, n) {
    		if (pos[i] + S >= v[a[i]].size()) {
    			endPos[i] = -1; 
    		}
    		else {
    			endPos[i] = v[a[i]][pos[i] + S];
    		}
    	}

    	FOR (i, 1, n) {
    		s[a[i]]++;

    		if (s[a[i]] <= S) {
    			update(1, 1, n, i, n, 1);
    		}
    		else if (s[a[i]] == S + 1) {
    			update(1, 1, n, i, n, -S);
    		}
    	}
    	// cout << st[1] << endl;
    	int res = st[1];

    	if (endPos[1] != -1) {
    		update(1, 1, n, endPos[1], n, S + 1);

    		if (v[a[1]].size() > 1) {
    			int nextPos = v[a[1]][pos[1] + 1];
    			if (endPos[nextPos] != -1) {
    				update(1, 1, n, endPos[nextPos], n, -S);
    			}
    		}
    	}

    	update(1, 1, n, 2, n, -1);

    	// FOR (i, 1, n) cout << getMax(1, 1, n, i, i) << " "; cout << endl;
    	FOR (i, 2, n) {
    		res = max(res, st[1]);
    		// cout << i << " " << res << endl;
    		if (endPos[i] != -1) {
	    		update(1, 1, n, endPos[i], n, S + 1);

	    		if (v[a[i]].size() > pos[i] + 1) {
	    			int nextPos = v[a[i]][pos[i] + 1];
	    			if (endPos[nextPos] != -1) {
	    				update(1, 1, n, endPos[nextPos], n, -S);
	    			}
	    		}
	    	}
	    	update(1, 1, n, i + 1, n, -1);
    	}

    	cout << res << endl;
    }
    
	
    return 0;
}