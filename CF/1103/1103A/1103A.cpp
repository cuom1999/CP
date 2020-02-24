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

string s;
int a[6][6];
int x[8] = {1, 1, 2, 2, 3, 3, 4, 4};
int y[8] = {1, 3, 1, 3, 1, 3, 1, 3};

int xx[8] = {1, 1, 1, 1, 3, 3, 3, 3};
int yy[8] = {1, 2, 3, 4, 1, 2, 3, 4};

int main()
{IN;OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	srand(time(NULL));
	cin >> s;
	//FOR (i, 1, 1000) s += (char) (rand() % 2 + '0');
	int score = 0;

	FOR (i, 0, 5) FOR (j, 0, 5) a[i][j] = 1;
	FOR (i, 1, 4) FOR (j, 1, 4) a[i][j] = 0;

	int mask = 0;

	for (int i = 0; i < s.size(); i++) {
		int pre = score;
		int curMask = mask;
		int s1 = 0, s2 = 0;
		FOR (r, 1, 4) {
			FOR (c, 1, 4) {
				if (a[r][c] == 1) {
					if (r > 2) {
						s1++;
					}
					else s2++;
				}
			}
		}
		if (s1 > s2) {
			curMask = 1;
		}
		else if (s1 < s2) curMask = 0;
		if (mask != curMask) {
			mask = curMask;
			reverse(x, x + 8);
			reverse(xx, xx + 8);
		}

		if (s[i] == '1') {
			FOR (u, 0, 7) {
				int r = x[u], c = y[u];
				if (a[r][c] == 0 && a[r][c + 1] == 0) {
					a[r][c] = 1;
					a[r][c + 1] = 1;
					cout << r << " " << c << endl;
					score++;
					break;
				}
			}
		}
		else {
			FOR (u, 0, 7) {
				int r = xx[u], c = yy[u];
				if (a[r][c] == 0 && a[r + 1][c] == 0) {
					a[r][c] = 1;
					a[r + 1][c] = 1;
					cout << r << " " << c << endl;
					score++;
					break;
				}
			}	
		}
		if (pre == score) {
			cout << s[i] << endl;
			FOR (r, 1, 4) {
				FOR (c, 1 ,4) cout << a[r][c];
				cout << endl;
			}
			return 0;
		}
		vector<int> v;
		FOR (r, 1, 4) {
			int s = 0;
			FOR (c, 1, 4) {
				s += a[r][c];
			}
			if (s == 4) {
				v.pb(r);
			}
		}
		vector<int> v1;
		FOR (c, 1, 4) {
			int s = 0;
			FOR (r, 1, 4) {
				s += a[r][c];
			}
			if (s == 4) {
				v1.pb(c);
			}
		}
		for (auto j: v) {
			FOR (c, 1, 4) a[j][c] = 0;
		}
		for (auto j: v1) {
			FOR (r, 1, 4) a[r][j] = 0;
		}
		/*
		cout << s[i] << endl;
		FOR (r, 1, 4) {
			FOR (c, 1, 4) cout << a[r][c];
			cout << endl;
		}
		cout << endl;
		*/	
	}
	//cout << score << endl;

	return 0;
}