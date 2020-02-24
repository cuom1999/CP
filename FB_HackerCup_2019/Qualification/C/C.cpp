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

char key[4] = {'0', '1', 'x', 'X'};
char operation[3] = {'&', '|', '^'};

char calc(char a, char b, char ope) {
	if (ope == '&') {
		if (a == '0' || b == '0') return '0';
		if (a == '1') return b;
		if (b == '1') return a;
		if (a == b) return a;
		if (a != b) return '0';
	}
	else if (ope == '|') {
		if (a == '1' || b == '1') return '1';
		if (a == '0') return b;
		if (b == '0') return a;
		if (a == b) return a;
		if (a != b) return '1';
	}
	else {
		if (a == '0') return b;
		if (b == '0') return a;
		if (a == b) return '0';
		if (a == '1') {
			if (b == 'x') return 'X';
			if (b == 'X') return 'x';
		}
		if (b == '1') {
			if (a == 'x') return 'X';
			if (a == 'X') return 'x';	
		}
		if (a != b) {
			return '1';
		}
	}
	return '.';
}

int calc(int a, int b, int ope) {
	char res = calc(key[a], key[b], operation[ope]);
	FOR (i, 0, 3) {
		if (res == key[i]) return i;
	}
	return -1;
}

int a[305], p[305];
int leaf[305];
vector<int> v[305];
int d[305][4];

void dp(int x) {
	if (leaf[x]) {
		FOR (i, 0, 3) d[x][i] = 1;
		d[x][a[x]] = 0; 
	}
	else {
		for (auto i: v[x]) {
			dp(i);
		}
		int c1 = v[x][0];
		int c2 = v[x][1];

		FOR (i, 0, 3) d[x][i] = INF;
		FOR (i, 0, 3) {
			FOR (j, 0, 3) {
				FOR (ope, 0, 2) {
					int res = calc(i, j, ope);
					if (ope == a[x]) {
						d[x][res] = min(d[x][res], d[c1][i] + d[c2][j]);
					}	
					else {
						d[x][res] = min(d[x][res], d[c1][i] + d[c2][j] + 1);
					}
				}
			}
		}
	}
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		memset(leaf, 0, sizeof(leaf));
		memset(a, 0, sizeof(a));
		memset(p, 0, sizeof(p));

		cout << "Case #" << z << ": ";
		string s;
		cin >> s;

		vector<int> ver;
		ver.pb(0);

		int C = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '|' || s[i] == '^' || s[i] == '&') {
				FOR (j, 0, 2) {
					if (s[i] == operation[j]) {
						a[ver.back()] = j;
					}
				}
			}
			else {
				if (s[i] == ')') {
					ver.pop_back();
				}
				else if (s[i] == '(') {
					p[++C] = ver.back();
					ver.pb(C);
				}
				else {
					FOR (j, 0, 3) {
						if (key[j] == s[i]) {
							p[++C] = ver.back();
							a[C] = j;
							leaf[C] = 1;
						}
					}
				}
			}
		}

		FOR (i, 1, C) {
			if (p[i]) {
				v[p[i]].pb(i);
			}
		}

		dp(1);
		cout << min(d[1][0], d[1][1]) << endl;
		
		FOR (i, 1, C) {
			v[i].clear();
		}
 	}

	return 0;
}