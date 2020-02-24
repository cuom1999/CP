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

typedef pair < int, int > II;
typedef pair < II, int > III;

int a[100005], c[100005];
int n, g, m;
vector<II> lastPeople[100005];
II person[100005];
int num[100005][2];
	
void solveC() {
	int l[100005];
	memset(l, -1, sizeof(l));

	vector<int> v;
	FOR (i, 0, n - 1) {
		if (c[i]) {
			v.pb((i + m) % n);
		}
	}
	if (!v.size()) return;

	sort(all(v));

	FOR (i, 0, n - 1) {
		if ((v[0] - i + n) % n <= m) {
			l[i] = (v[0] - m % n + n) % n;
		}
	}
	for (int i = 1; i < v.size(); i++) {
		FOR (j, v[i - 1] + 1, v[i]) {
			if ((v[i] - j + n) % n <= m) {
				l[j] = (v[i] - m % n + n) % n;
			}
		}
	}

	FOR (i, 0, n - 1) {
		if (l[i] != -1) {
			// cout << i << " " << l[i] << endl;
			lastPeople[i].pb({l[i], 0});
		} 
	}
}

void solveA() {
	int l[100005];
	memset(l, -1, sizeof(l));

	vector<int> v;
	FOR (i, 0, n - 1) {
		if (a[i]) {
			v.pb((i - m % n + n) % n);
		}
	}
	if (!v.size()) return;
	sort(all(v));

	FOR (i, 0, n - 1) {
		if ((-v.back() + i + n) % n <= m) {
			l[i] = (v.back() + m % n + n) % n;
		}
	}
	for (int i = (int) v.size() - 2; i >= 0; i--) {
		FORD (j, v[i + 1] - 1, v[i]) {
			if ((-v[i] + j + n) % n <= m) {
				l[j] = (v[i] + m % n + n) % n;
			}
		}
	}

	FOR (i, 0, n - 1) {
		if (l[i] != -1) {
			// cout << i << " " << l[i] << endl;
			lastPeople[i].pb({l[i], 1});
		} 
	}
}

int calcA(int g, int c) {
	int x = (g - c) % n;
	x = (x + n) % n;
	return ((m - x) / n * n + x);
}  

int calcC(int g, int c) {
	int x = (c - g) % n;
	x = (x + n) % n;
	return ((m - x) / n * n + x);
}  


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";

		cin >> n >> g >> m;

		FOR (i, 1, g) {
			int u;
			char ch;
			cin >> u >> ch;
			u--;
			if (ch == 'A') {
				a[u]++;
			}
			else {
				c[u]++;
			}
			if (ch == 'C') person[i] = {u, 0};
			else person[i] = {u, 1};
		}

		solveC();
		solveA();

		FOR (i, 0, n - 1) {
			if (lastPeople[i].size() == 1) {
				num[lastPeople[i][0].first][lastPeople[i][0].second]++;
			}
			if (lastPeople[i].size() == 2) {
				int timeC = calcC(lastPeople[i][0].first, i);
				int timeA = calcA(lastPeople[i][1].first, i);

				int maxTime = max(timeA, timeC);

				if (timeC == maxTime) {
					num[lastPeople[i][0].first][0]++;
				}
				if (timeA == maxTime) {
					num[lastPeople[i][1].first][1]++;
				}
			}
		}

		FOR (i, 1, g) {
			cout << num[person[i].first][person[i].second] << " ";
		}
		cout << endl;
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(num, 0, sizeof(num));
		FOR (i, 0, n) lastPeople[i].clear();
	}

	return 0;
}