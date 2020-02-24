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
const ll K = 1e9 + 7;
ll d[605][605][2], g[605][605][2];
int n;
ll aProb, bProb;

ll pw(ll a, ll n) {
	if (n == 0) return 1;
	ll q = pw(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> aProb >> bProb;

	ll inv = pw(100, K - 2);

	FORD (i, 2 * n - 1, 0) {
		FOR (aWin, 0, min(i, n)) {
			int bWin = i - aWin;
			if (bWin > n) continue;
			FOR (last, 0, 1) {
				FOR (streak, 0, max(aWin, bWin)) {
					if (aWin == n) {
						d[aWin][last][streak] = 1;
					}
					else if (bWin == n) {

					} 
					else {
						ll aWinProb;
						if (i % 4 == 1 || i % 4 == 2) {
							if (last == 0) {
								aWinProb = min(100LL, aProb + streak * 5);
							}
							else {
								ll bWinProb = min(100LL, 100 - aProb + streak * 5);
								aWinProb = 100 - bWinProb;
							}
						}
						else {
							if (last == 0) {
								aWinProb = min(100LL, 100 - bProb + streak * 5);
							}
							else {
								ll bWinProb = min(100LL, bProb + streak * 5);
								aWinProb = 100 - bWinProb;
							}	
						}
						if (last == 0) {
							d[aWin][last][streak] = (aWinProb * inv % K * g[aWin + 1][0][streak + 1] + (100 - aWinProb) * inv % K * g[aWin][1][1]) % K;
						}
						else {
							d[aWin][last][streak] = (aWinProb * inv % K * g[aWin + 1][0][1] + (100 - aWinProb) * inv % K * g[aWin][1][streak + 1]) % K;	
						}
					}
				}
			}
		}

		FOR (i, 0, n) {
			FOR (l, 0, 1) {
				FOR (s, 0, n) {
					g[i][l][s] = d[i][l][s];
				}
			}
		}
	}

	cout << d[0][0][0] * pw(100, 2 * n - 1) % K << endl;


	return 0;
}