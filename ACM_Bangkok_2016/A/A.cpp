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

int fen[100005];
int G;

void add(int u, int v){
	for (int i = u; i <= 100000; i += i & -i){
		fen[i] += v;
	}
}

int sum(int u){
	int res = 0;
	for (int i = u; i; i -= i & -i){
		res += fen[i];
	}
	return res;
}

int getOrd(int a){
	return G - sum(a) + 1;
}

void ins(int a){
	add(a, 1);
}

void erase(int a){
	add(a, -1);
}
int a[100005];
multiset<int, greater<int> > S[100005];
deque<int> v[100005];
deque<ll> s[100005];
ll s1[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin >> T;
    FOR (zz, 1 ,T){
    	cout << "Case " << zz << ": " << endl;
	    int m;
	    cin >> G >> m;
	    int n = (G - 1) / m + 1;
	    FOR (i, 0, 100000) {
	    	fen[i] = 0;
	    	v[i].clear();
	    	s[i].clear();
	    	s1[i] = 0;
	    	S[i].clear();
	    }
	    FOR (i, 1, G) {
	    	cin >> a[i];
	    	ins(a[i]);
	    }
	    if (m > n) {	
	    	vector<int> V;
	    	FOR (i, 1, G) V.pb(a[i]);
	    	sort(all(V));
	    	reverse(all(V));
	    	FOR (i, 0, G - 1){
	    		S[i / m + 1].insert(V[i]);
	    	}
	    	ll res = 0;
	    	FOR (i, 1, n){
	    		for (auto j: S[i]) {
	    			res += i * 1ll * j;
	    		}
	    	}

	    	int q;
	    	cin >> q;
	    	FOR (z, 1, q) {
	    		int u, v;
	    		cin >> u >> v;
	    		int r1 = getOrd(a[u]);
	    		int old = a[u];
	    		erase(a[u]);
	    		ins(v);
	    		a[u] = v;
	    		int r2 = getOrd(a[u]);
	    		int u1 = (r1 - 1) / m + 1;
	    		int u2 = (r2 - 1) / m + 1;
	    		if (u1 < u2) {
		    		S[u1].erase(S[u1].find(old));
		    		int w = *S[u1 + 1].begin();
		    		S[u1].insert(w);
		    		res -= u1 * 1ll * old;
		    		res += u1 * 1ll * w;
		    		FOR (i, u1 + 1, u2 - 1){
		    			w = *S[i + 1].begin();
		    			S[i].insert(w);
		    			int st = *S[i].begin();
		    			S[i].erase(S[i].begin());
		    			res -= i * 1ll * st;
		    			res += w * 1ll * i;
		    		}
		    		int st = *S[u2].begin();
		    		S[u2].erase(S[u2].begin());
		    		S[u2].insert(a[u]);
		    		res -= u2 * 1ll * st;
		    		res += a[u] * 1ll * u2;
		    	}
		    	else if (u1 > u2){
		    		S[u1].erase(S[u1].find(old));
		    		int w = *(--S[u1 - 1].end());
		    		S[u1].insert(w);

		    		res -= u1 * 1ll * old;
		    		res += u1 * 1ll * w;
		    		
		    		FORD (i, u1 - 1, u2 + 1){
		    			w = *(--S[i - 1].end());
		    			S[i].insert(w);
		    			int st = *(--S[i].end());
		    			S[i].erase(--S[i].end());
		    			res -= i * 1ll * st;
		    			res += w * 1ll * i;
		    		}
		    		int st = *(--S[u2].end());
		    		S[u2].erase(--S[u2].end());
		    		S[u2].insert(a[u]);
		    		res -= u2 * 1ll * st;
		    		res += a[u] * 1ll * u2;
		    	}
		    	else{
		    		S[u1].erase(S[u1].find(old));
		    		S[u1].insert(a[u]);
		    		res += u1 * 1ll * (a[u] - old);
		    	}
		    	cout << res << endl;
	    	}
	    }
	    else{
	    	int S = sqrt(n * 1.0 / m);
	    	int nS = (n - 1) / S;
	    	vector<int> V;
	    	FOR (i, 1, G) V.pb(a[i]);
	    	sort(all(V));
	    	reverse(all(V));
	    	FOR (i, 0, G - 1) {
	    		v[i / (S * m)].pb(V[i]);
	    	}
	    	/*FOR (i, 0, nS) {
	    		cout << i << ": ";
	    		for (auto j: v[i]) cout << j << " "; cout << endl;
	    	}*/
	    	FOR (i, 0, nS) {
	    		s[i].resize(m);
	    		for (int j = 0; j < v[i].size(); j++){
	    			s[i][j % m] += v[i][j];
	    			s1[i] += v[i][j] * 1ll * (j / m + i * S + 1);
	    		}
	    	}
	    	ll res = 0;
	    	FOR (i, 0, nS) res += s1[i];
	    	int q;
	    	cin >> q;
	    	FOR (z, 1, q) {
	    		int u, vv;
	    		cin >> u >> vv;
	    		int r1 = getOrd(a[u]);
	    		int old = a[u];
	    		erase(a[u]);
	    		ins(vv);
	    		a[u] = vv;
	    		int r2 = getOrd(a[u]);
	    		int u1 = (r1 - 1) / (m * S);
	    		int u2 = (r2 - 1) / (m * S);

	    		if (u1 < u2){
	    			int ind = r1 - u1 * S * m - 1;
	    			v[u1].erase(v[u1].begin() + ind);
	    			v[u1].pb(v[u1 + 1][0]);
	    			s[u1].clear(); s[u1].resize(m);
	    			res -= s1[u1];
	    			s1[u1] = 0;
		    		for (int j = 0; j < v[u1].size(); j++) {
		    			s[u1][j % m] += v[u1][j];
		    			s1[u1] += v[u1][j] * 1ll * (j / m + u1 * S + 1);
		    		}
		    		res += s1[u1];

		    		FOR (i, u1 + 1, u2 - 1) {
		    			ll Q = s[i][0];
		    			Q -= v[i][0];
		    			Q += v[i + 1][0];
		    			
		    			res -= v[i][0] * 1ll * (i * S + 1);
		    			res += v[i + 1][0] * 1ll * ((i + 1) * S);
		    			res += s[i][0] - v[i][0];
						 
		    			v[i].pop_front();
		    			v[i].pb(v[i + 1][0]);
		    			s[i].pop_front();
		    			s[i].pb(Q);
		    		}
		    		ind = r2 - u2 * S * m - 1;
		    		v[u2].pop_front();
					v[u2].insert(v[u2].begin() + ind, a[u]);

	    			s[u2].clear(); s[u2].resize(m);
	    			res -= s1[u2];
	    			s1[u2] = 0;
		    		for (int j = 0; j < v[u2].size(); j++) {
		    			s[u2][j % m] += v[u2][j];
		    			s1[u2] += v[u2][j] * 1ll * (j / m + u2 * S + 1);
		    		}
		    		res += s1[u2];
	    		}
	    		else if (u1 > u2) {
	    			int ind = r1 - u1 * S * m - 1;
	    			v[u1].erase(v[u1].begin() + ind);
	    			v[u1].push_front(v[u1 - 1].back());
	    			s[u1].clear(); s[u1].resize(m);
	    			res -= s1[u1];
	    			s1[u1] = 0;
		    		for (int j = 0; j < v[u1].size(); j++) {
		    			s[u1][j % m] += v[u1][j];
		    			s1[u1] += v[u1][j] * 1ll * (j / m + u1 * S + 1);
		    		}
		    		res += s1[u1];
		    		//cout << u1 << endl;
		    		//for (auto i: v[u1]) cout << i << " "; cout << endl;

		    		FORD (i, u1 - 1, u2 + 1) {
		    			ll Q = s[i].back();
		    			Q -= v[i].back();
		    			Q += v[i - 1].back();
		    			
		    			res -= v[i].back() * 1ll * ((i + 1) * S);
		    			res += v[i - 1].back() * 1ll * (i * S + 1);
		    			res -= s[i].back() - v[i].back();
						 
		    			v[i].pop_back();
		    			v[i].push_front(v[i - 1].back());
		    			s[i].pop_back();
		    			s[i].push_front(Q);
		    		}
		    		ind = r2 - u2 * S * m - 1;
		    		v[u2].pop_back();
					v[u2].insert(v[u2].begin() + ind, a[u]);

	    			s[u2].clear(); s[u2].resize(m);
	    			res -= s1[u2];
	    			s1[u2] = 0;
		    		for (int j = 0; j < v[u2].size(); j++) {
		    			s[u2][j % m] += v[u2][j];
		    			s1[u2] += v[u2][j] * 1ll * (j / m + u2 * S + 1);
		    		}
		    		res += s1[u2];
	    		}
	    		else{
	    			int ind = r1 - u1 * S * m - 1;
	    			v[u1].erase(v[u1].begin() + ind);
	    			ind = r2 - u1 * S * m - 1;
					v[u1].insert(v[u1].begin() + ind, a[u]);

	    			s[u1].clear(); s[u1].resize(m);
	    			res -= s1[u1];
	    			s1[u1] = 0;
		    		for (int j = 0; j < v[u1].size(); j++) {
		    			s[u1][j % m] += v[u1][j];
		    			s1[u1] += v[u1][j] * 1ll * (j / m + u1 * S + 1);
		    		}
		    		res += s1[u1];
	    		}
	    		cout << res << endl;
	    	}
	    }
	}

    return 0;
}