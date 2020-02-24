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

string s, a, b;
int nextPre[2][55][32];

void init(string &s, int type) {
	FOR (i, 0, 50) {
		FOR (j, 0, 30) nextPre[type][i][j] = 0;
	}
	int n = s.length();
	s = '0' + s;
	
	nextPre[type][0][s[1] - 'a'] = 1;
	FOR (i, 1, n) {
		FOR (c, 'a', 'z') {
			string tmp = s.substr(1, i);
			tmp += c;

			FORD (j, i + 1, 1) {
				if (s.substr(1, j) == tmp.substr(i + 1 - j, j)) {
					nextPre[type][i][c - 'a'] = j;
					break;
				}
				// cout << s.substr(1, j) << " " << tmp.substr(i + 1 - j, j) << endl;
			}
		}
	}
}

int dp[1005][55][55];
int n;

int calcDP(int index, int prefA, int prefB) {
	// cout << index << " " << prefA << " " << prefB << endl;
	if (dp[index][prefA][prefB] != -INF) return dp[index][prefA][prefB];
	
	int val = 0;
	if (prefA == a.length() - 1) val++;
	if (prefB == b.length() - 1) val--; 

	if (index == s.length() - 1) {
		return val;
	}

	int res = -INF;
	if (s[index + 1] == '*') {
		FOR (c, 'a', 'z') {
			res = max(res, val + calcDP(index + 1, nextPre[0][prefA][c - 'a'], nextPre[1][prefB][c - 'a']));
		}
	}	
	else {
		char c = s[index + 1];
		res = max(res, val + calcDP(index + 1, nextPre[0][prefA][c - 'a'], nextPre[1][prefB][c - 'a']));
	}
	return dp[index][prefA][prefB] = res;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s >> a >> b;

	init(a, 0);
	init(b, 1);
	
	n = s.length();
	s = "0" + s;

	FOR (i, 0, 1000) {
		FOR (j, 0, 50) {
			FOR (k, 0, 50) {
				dp[i][j][k] = -INF;
			}
		}
	}

	cout << calcDP(0, 0, 0) << endl;

	return 0;
}