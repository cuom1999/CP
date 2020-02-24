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


const ll K = 1e9 + 7;

bool test(string s) {
	int n = s.length();

	if (n == 1) return 1;

	if (n == 2) {
		if (s[0] != s[1]) return 1;
		return 0;
	}

	FOR (i, 1, n - 2) {
		if ((s[i] - s[i - 1]) * (s[i] - s[i + 1]) <= 0) return 0;
	}

	return 1;
}

ll up[50005][11], down[50005][11], zigzag[50005][11], smaller[50005]; //n digits, the first is i

void preCompute() {

	FOR (j, 0, 9) {
		zigzag[1][j] = up[1][j] = down[1][j] = 1;
	}

	FOR (i, 2, 50000) {
		FOR (j, 0, 10) {
			FOR (k, j + 1, 9) {
				up[i][j] = (up[i][j] + down[i - 1][k]) % K;
			}
			FOR (k, 0, j - 1) {
				down[i][j] = (down[i][j] + up[i - 1][k]) % K;
			}
			zigzag[i][j] = (up[i][j] + down[i][j]) % K;
		}
	}

	smaller[0] = 1;

	FOR (i, 1, 50000) {
		smaller[i] = smaller[i - 1];
		FOR (j, 1, 9) {
			smaller[i] = (smaller[i] + zigzag[i][j]) % K;
		}
	}
}

ll solve(string &s, int index) {
	if (s[0] == '0') { //corner case s = 0
		return 1;
	}

	if (index == s.length()) {
		return test(s);
	}

	ll res = 0;

	int remainLen = (int) s.size() - index;

	if (index == 0) {
		res = smaller[remainLen - 1];
		FOR (i, 1, s[index] - '0' - 1) {
			res = (res + zigzag[remainLen][i]) % K;
		}
	}

	else if (index == 1) {

		FOR (i, 0, s[index] - '0' - 1) {
			if (i > s[0] - '0') {
				res = (res + down[remainLen][i]) % K;
			}
			else if (i < s[0] - '0') {
				res = (res + up[remainLen][i]) % K;
			}
		}		

	}
	else {
		if (s[index - 1] > s[index - 2]) {
			for (int i = 0; i < s[index] - '0' && i < s[index - 1] - '0'; i++) {
				res = (res + up[remainLen][i]) % K;
			}			
		}

		else if (s[index - 1] < s[index - 2]) {
			for (int i = s[index - 1] - '0' + 1; i < s[index] - '0'; i++) {
				res = (res + down[remainLen][i]) % K;
			}
		}
	}
	
	if (index >= 1 && s[index] == s[index - 1]) return res;
	if (index >= 2 && (s[index - 1] - s[index]) * (s[index - 1] - s[index - 2]) < 0) return res;

	res = (res + solve(s, index + 1)) % K;

	return res;
}

string L, R;


int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;

    cin >> L >> R;

    preCompute();

    cout << (solve(R, 0) - solve(L, 0) + test(L) + K) % K << endl;

    return 0;
}