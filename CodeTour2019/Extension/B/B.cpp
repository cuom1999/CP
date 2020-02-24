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
typedef pair < ll, ll > pll;

string button[15];
const int MINN = -9999;
const int MAXN = 99999;
// const int MINN = -9;
// const int MAXN = 99;
const int N = 9999;

bool check(int x) {
	return (MINN <= x && x <= MAXN);
} 

int reverse(int x) {
	int y = abs(x);
	int res = 0;
	while (y) {
		res = res * 10 + y % 10;
		y /= 10;
	}
	if (x < 0) return -res;
	return res;
}

int sum(int x) {
	int y = abs(x);
	int res = 0;
	while (y) {
		res += y % 10;
		y /= 10;
	}
	if (x < 0) return -res;
	return res;
}

vector<II> v[200005];

int transform(int x, int b) {
	string s = button[b];
	if (button[b].size() == 2) return INF;
	if (button[b].size() == 4) {
		int num = s[2] - '0';
		if (s[1] == '+') {
			if (check(x + num)) {
				return x + num;
			}
		}
		if (s[1] == '-') {
			if (check(x - num)) {
				return x - num;
			}
		}
		if (s[1] == 'x') {
			if (check(x * num)) {
				return x * num;
			}
		}
		if (s[1] == '/') {
			if (num && x % num == 0 && check(x / num)) {
				return x / num;
			}
		}
	}
	if (s.size() == 3) {
		if (s[1] == '<') {
			return x / 10;
		}
		else {
			int num = s[1] - '0';
			int a = x * 10;
			if (x >= 0) a += num;
			else a -= num;
			if (check(a)) {
				return a;
			}
		}
	}
	if (s.size() == 5) {
		if (s[1] == '+') {
			if (check(-x)) {
				return -x;
			}
		}
		else {
			if (check(sum(x))) {
				return sum(x);
			}
		}
	}
	if (s.size() == 9) {
		int a = reverse(x);
		if (check(a)) {
			return a;
		}
	}
	return INF;
}

int d[200005];
II p[200005];
int main()
{IN; //OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int s, g;
	cin >> s >> g;

	FOR (i, 1, 9) {
		cin >> button[i];
	}

	FOR (i, MINN, MAXN) {
		FOR (j, 1, 9) {
			int a = transform(i, j);
			if (a != INF) {
				v[i + N].pb({a + N, j});
			}
		}
	}

	queue<int> q;
	q.push(s + N);

	d[s + N] = 1;

	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto i: v[u]) {
			if (d[i.first] == 0) {
				// cout << i.first << endl;
				d[i.first] = 1;
				p[i.first] = {u, i.second};
				q.push(i.first);
			}
		}
	}

	vector<int> res;
	int cur = g + N;
	while (cur != s + N) {
		res.pb(p[cur].second);
		cur = p[cur].first;
	}

	reverse(all(res));
	for (auto i: res) cout << button[i] << " ";
	cout << endl;

	return 0;
}