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

vector<int> res;
int charAfter[1000005][3], charBefore[1000005][3];

void solve(int l, int r) {
	if (l > r) return;
	int maxVal = 0;
	int index = -1;
	FOR (c, 0, 2) {
		if (charBefore[r][c] - charAfter[l][c] > maxVal) {
			maxVal = charBefore[r][c] - charAfter[l][c];
			index = c;
		}
	}	

	// cout << index << " " << charAfter[l][index] << " " << charBefore[r][index] << endl;
	if (index == -1) {
		res.pb(l);
		return;
	}

	int newL = charAfter[l][index] + 1;
	int newR = charBefore[r][index] - 1;
	res.pb(newL - 1);
	res.pb(newR + 1);

	solve(newL, newR);
}

string genString(int n) {
	string s;
	vector<int> v;
	FOR (i, 1, n) {
		int u = rand() % 3;
		while (v.size() && u == v.back()) {
			u = rand() % 3;
		}
		v.pb(u);
	}

	for (auto i: v) {
		s += (char) (i + 'a');
	}
	return s;
}

bool check(string &s, string &a) {
	int n = a.size();
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != a[n - i - 1]) {
			cerr << "NO PAL";
			return 0;
		}
	}

	int j = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == a[j] && j < n) {
			j++;
		}
	}

	if (j == n) return 1;
	cerr << "NOT SUB";
	return 0;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	// srand(time(0));

	FOR (z, 1, 1) {
		res.clear();
		string s;
		cin >> s;
		// int N = rand() % 25 + 2;
		// s = genString(N);
		// cout << s << endl;

		int n = s.length();

		s = '0' + s;

		FOR (c, 0, 2) {
			charBefore[0][c] = -INF;
			charAfter[n + 1][c] = INF;
		}

		FOR (i, 1, n) {
			FOR (c, 'a', 'c') {
				charBefore[i][c - 'a'] = charBefore[i - 1][c - 'a'];
			}
			charBefore[i][s[i] - 'a'] = i;
			// cout << i << " " << charBefore[i][2] << endl;
	 	}

	 	FORD (i, n, 1) {
	 		FOR (c, 'a', 'c') {
				charAfter[i][c - 'a'] = charAfter[i + 1][c - 'a'];
			}
			charAfter[i][s[i] - 'a'] = i;
	 	}


	 	solve(1, n);

	 	// for (auto i: res) cout << i << " ";

	 	string ans;

	 	for(int i = 0; i < res.size(); i += 2) {
	 		ans += s[res[i]];
	 	}
		
		string ans2;
		for(int i = 1; i < res.size(); i += 2) {
	 		ans2 += s[res[i]];
	 	}

	 	reverse(all(ans2));
	 	ans = ans + ans2;

	 	cout << ans << endl;
	 	// if (ans.size() >= n / 2 && check(s, ans)) {
	 	// 	cout << "YES\n\n";
	 	// }
	 	// else {
	 	// 	cout << "NO\n\n";
	 	// 	return 0;
	 	// }
	}

	return 0;
}