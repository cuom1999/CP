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

inline int abs(int x) {
	if (x < 0) return -x;
	return x;
}

vector<int> v[50005];

struct query {
	int x, y, stt;
	query(int __x = 0, int __y = 0, int __stt = 0) {
		x = __x;
		y = __y;
		stt = __stt;		
	}
};

int res[100005];
int f[50005], g[50005];
int dd[50005];
queue<int> qu;
void bfs(int n, int f[50005], int a) {
	FOR (i, 0, n) {
		f[i] = INF;
		dd[i] = 0;
	}
	f[a] = 0;
	dd[a] = 1;
	while(qu.size()) qu.pop();
	qu.push(a);
	while (qu.size()) {
		int u = qu.front();
		qu.pop();
		for (auto i: v[u]) {
			if (dd[i]) continue;
			dd[i] = 1;
			qu.push(i);
			f[i] = f[u] + 1;
		} 
	}
}	

void solve(vector<II> &E, vector<query> &Q, int n) {
	if (n > 2) {
		/*
		cout << n << endl;
		for (auto i: E) cout << i.first << " " << i.second << endl;
		for (auto i: Q) cout << i.x << " " << i.y << " " << i.stt << endl;
		cout << endl;
		*/
		FOR (i, 0, n) {
			v[i].clear();
		}
		for (auto i: E) {
			v[i.first].pb(i.second);
			v[i.second].pb(i.first);
		}
		FOR (i, 0, n) {
			v[i].pb((i + 1) % (n + 1));
			v[i].pb((i + n) % (n + 1));
		}
		int mi = INF;
		int X = 0, Y = 0;

		for (auto i: E) {
			int u = abs(i.second - i.first);
			u--;
			if (mi > abs(n - 1 - u * 2)) {
				X = i.first; 
				Y = i.second;
				mi = abs(n - 1 - u * 2);
			}
		}

		if (X > Y) swap(X, Y);
		//cout << X << " " << Y << endl << endl;

		vector<query> Q1, Q2, Q3;
		for (auto q: Q) {
			if (q.x > X && q.x < Y && q.y > X && q.y < Y) {
				query q1 = query(q.x - X, q.y - X, q.stt);
				Q1.pb(q1);
			}
			else if ((q.x > Y || q.x < X) && (q.y > Y || q.y < X)) {
				query q1 = q;
				if (q.x > Y) q1.x = q.x - Y + X + 1;
				if (q.y > Y) q1.y = q.y - Y + X + 1;
				q1.stt = q.stt;
 				Q2.pb(q1);
			}
			else Q3.pb(q);
		}
		vector<II> E1, E2;
		for (auto q: E) {
			if (q.first == X && q.second == Y) continue;
			if (q.first == Y && q.second == X) continue;
			
			if (q.first >= X && q.first <= Y && q.second >= X && q.second <= Y) {
				II q1 = II(q.first - X, q.second - X);
				E1.pb(q1);
			}
			else {
				II q1 = q;
				if (q.first >= Y) q1.first = q.first - Y + X + 1;
				if (q.second >= Y) q1.second = q.second - Y + X + 1;
 				E2.pb(q1);
			}
		}

		// bfs here
		bfs(n, f, X);
		bfs(n, g, Y);

		for (auto q: Q3) {
			res[q.stt] = min(f[q.x] + f[q.y], f[q.x] + g[q.y] + 1);
			res[q.stt] = min(res[q.stt], g[q.x] + f[q.y] + 1);
			res[q.stt] = min(res[q.stt], g[q.x] + g[q.y]);
		}
		solve(E1, Q1, Y - X);
		solve(E2, Q2, n + 1 - (Y - X));
	}
	else { 
		for (auto i: Q) {
			if (i.x == i.y) res[i.stt] = 0;
			else res[i.stt] = 1;
		}
	}
}

vector<query> Q;
vector<II> E;
int main()
{IN; OUT;
	//freopen("distance.in", "r", stdin);
	//freopen("distance.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin >> n;
	FOR (i, 1, n - 3) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		E.pb(II(x, y));
	}    

	int q;
	cin >> q;

	FOR (i, 1, q) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		Q.pb(query(x, y, i));
	}

	solve(E, Q, n - 1);

	FOR (i, 1, q) cout << res[i] << endl;
	
    return 0;
}